#include "Machine.h"

#include <algorithm>
#include <iostream>

#include "Constantes.h"
#include "ContexteInfusion.h"
#include "TheNoir.h"
#include "TheOolong.h"
#include "TheVert.h"

Machine::Machine(const FabriqueComposants& modele) : chauffage_(modele.creerChauffage()), distributeurEau_(modele.creerDistributeurEau()), distributeurThe_(modele.creerDistributeurThe()), reserveEau_(constantes::NOM_RESERVE_EAU, constantes::UNITE_EAU, constantes::EAU_INITIALE_ML, constantes::SEUIL_EAU_ML)
{
    abonner(reserveEau_);

    thes_.push_back(std::make_unique<TheVert>());
    thes_.push_back(std::make_unique<TheNoir>());
    thes_.push_back(std::make_unique<TheOolong>());
 
    for (const auto& the : thes_) {
        const std::string nom = the->getNom();
        reservesThe_.emplace(nom, Reserve(constantes::PREFIXE_NOM_RESERVE_THE + nom, constantes::UNITE_THE, constantes::THE_INITIAL_G, constantes::SEUIL_THE_G));
        abonner(reservesThe_.at(nom));
    }

    routines_[constantes::NOM_ROUTINE_SOLO] = [this]() { return creerRoutineSolo(); };
    routines_[constantes::NOM_ROUTINE_DUO] = [this]() { return creerRoutineDuo(); };
    routines_[constantes::NOM_ROUTINE_MATIN] = [this]() { return creerRoutineMatin(); };
}

void Machine::abonner(Reserve& reserve)
{
    reserve.attacher(&alerteEcran_);
    reserve.attacher(&notificationDistante_);
}

const The* Machine::trouverThe(const std::string& nom) const
{
    const auto it = std::find_if(thes_.begin(), thes_.end(), [&nom](const std::unique_ptr<The>& the) { return the->getNom() == nom; });
    return it == thes_.end() ? nullptr : it->get();
}

void Machine::afficherReserve(const Reserve& reserve) const
{
    std::cout << reserve.getNom() << " : " << reserve.getQuantite() << " " << reserve.getUnite() << "\n";
}

void Machine::afficherAjout(const Reserve& reserve, double quantite) const
{
    const std::string de = (reserve.getNom() == constantes::NOM_RESERVE_EAU) ? "d’" : "de ";
    std::cout << "Ajout " << de << reserve.getNom() << " : " << quantite << " " << reserve.getUnite() << ".\n";
}

void Machine::afficherErreurInsuffisante(const Reserve& reserve, double quantiteRequise) const
{
    const std::string de = (reserve.getNom() == constantes::NOM_RESERVE_EAU) ? "d’" : "de ";
    std::cout << "Erreur : réserve " << de << reserve.getNom() << " insuffisante.\n" << "Quantité requise : " << quantiteRequise << " " << reserve.getUnite() << ". Quantité disponible : " << reserve.getQuantite() << " " << reserve.getUnite() << ".\n";
}

void Machine::selectionner(const std::string& nomThe)
{
    const The* the = trouverThe(nomThe);
    if (the == nullptr) {
        std::cout << "Erreur : thé inconnu.\n";
        return;
    }
    historique_.executer(std::make_unique<CommandeSelection>(configuration_, the));
}

bool Machine::reservesSuffisantes(const Besoins& besoins, const Reserve& reserveThe) const
{
    const bool theSuffisant = reserveThe.getQuantite() + constantes::EPSILON >= besoins.getThe();
    const bool eauSuffisante = reserveEau_.getQuantite() + constantes::EPSILON >= besoins.getEau();
    if (theSuffisant && eauSuffisante) {
        return true;
    }

    if (!theSuffisant) {
        afficherErreurInsuffisante(reserveThe, besoins.getThe());
    }
    if (!eauSuffisante) {
        afficherErreurInsuffisante(reserveEau_, besoins.getEau());
    }
    std::cout << "Aucune consommation effectuée.\n";
    return false;
}

void Machine::infuser()
{
    const The* theCourant = configuration_.getTheCourant();
    if (theCourant == nullptr) {
        std::cout << "Erreur : aucun thé sélectionné.\n";
        return;
    }

    const int portions = configuration_.getNPortions();
    Reserve& reserveThe = reservesThe_.at(theCourant->getNom());
    ContexteInfusion contexte{*chauffage_, *distributeurEau_, *distributeurThe_, infuseur_, reserveEau_, reserveThe};

    const Besoins besoins = theCourant->calculerBesoins(contexte).multiplier(portions);
    if (!reservesSuffisantes(besoins, reserveThe)) {
        return;
    }

    for (int i = 0; i < portions; ++i) {
        theCourant->preparer(contexte);
    }
}

void Machine::afficherReserves() const
{
    afficherReserve(reserveEau_);
    for (const auto& the : thes_) {
        afficherReserve(reservesThe_.at(the->getNom()));
    }
}

void Machine::remplirEau(double mL)
{
    afficherAjout(reserveEau_, mL);
    reserveEau_.ajouter(mL);
}

void Machine::remplirThe(const std::string& nomThe, double grammes)
{
    const auto it = reservesThe_.find(nomThe);
    if (it == reservesThe_.end()) {
        std::cout << "Erreur : thé inconnu.\n";
        return;
    }
    afficherAjout(it->second, grammes);
    it->second.ajouter(grammes);
}

void Machine::activerNotificationsDistantes(bool estActif)
{
    if (estActif) {
        reserveEau_.attacher(&notificationDistante_);
        for (auto& entree : reservesThe_) {
            entree.second.attacher(&notificationDistante_);
        }
        std::cout << "Notifications à distance activées.\n";
    } else {
        reserveEau_.detacher(&notificationDistante_);
        for (auto& entree : reservesThe_) {
            entree.second.detacher(&notificationDistante_);
        }
        std::cout << "Notifications à distance désactivées.\n";
    }
}

void Machine::changerPortions(int nombre)
{
    historique_.executer(std::make_unique<CommandePortions>(configuration_, nombre));
}

void Machine::afficherConfiguration() const
{
    const The* theCourant = configuration_.getTheCourant();
    std::cout << "Thé sélectionné : " << (theCourant ? theCourant->getNom() : constantes::AUCUN_THE) << ".\n";
    std::cout << "Nombre de portions : " << configuration_.getNPortions() << ".\n";
}

std::unique_ptr<Routine> Machine::creerRoutineSolo()
{
    auto routine = std::make_unique<Routine>(constantes::NOM_ROUTINE_SOLO);
    routine->ajouterCommande(std::make_unique<CommandeSelection>(configuration_, trouverThe(constantes::NOM_VERT)));
    routine->ajouterCommande(std::make_unique<CommandePortions>(configuration_, constantes::PORTIONS_SOLO));
    return routine;
}

std::unique_ptr<Routine> Machine::creerRoutineDuo()
{
    auto routine = std::make_unique<Routine>(constantes::NOM_ROUTINE_DUO);
    routine->ajouterCommande(std::make_unique<CommandeSelection>(configuration_, trouverThe(constantes::NOM_NOIR)));
    routine->ajouterCommande(std::make_unique<CommandePortions>(configuration_, constantes::PORTIONS_DUO));
    return routine;
}

std::unique_ptr<Routine> Machine::creerRoutineMatin()
{
    auto routine = std::make_unique<Routine>(constantes::NOM_ROUTINE_MATIN);
    routine->ajouterCommande(creerRoutineDuo());
    routine->ajouterCommande(std::make_unique<CommandeSelection>(configuration_, trouverThe(constantes::NOM_OOLONG)));
    return routine;
}

void Machine::executerRoutine(const std::string& nom)
{
    const auto it = routines_.find(nom);
    if (it == routines_.end()) {
        std::cout << "Erreur : routine inconnue.\n";
        return;
    }

    std::unique_ptr<Routine> routine = it->second();
    const std::string nomRoutine = routine->getNom();
    if (historique_.executer(std::move(routine))) {
        std::cout << "Routine appliquée : " << nomRoutine << ".\n";
    }
}

void Machine::apercuRoutine(const std::string& nom)
{
    const auto it = routines_.find(nom);
    if (it == routines_.end()) {
        std::cout << "Erreur : routine inconnue.\n";
        return;
    }

    std::unique_ptr<Routine> routine = it->second();
    IterateurCommandes iterateur = routine->creerIterateur();
    int numero = 1;
    for (iterateur.premier(); !iterateur.estTermine(); iterateur.suivant()) {
        std::cout << numero++ << ". " << iterateur.getCourant().decrire() << "\n";
    }
}

void Machine::undo()
{
    if (historique_.undo()) {
        std::cout << "Opération annulée.\n";
    } else {
        std::cout << "Erreur : aucune opération à annuler.\n";
    }
}

void Machine::redo()
{
    if (historique_.redo()) {
        std::cout << "Opération rétablie.\n";
    } else {
        std::cout << "Erreur : aucune opération à rétablir.\n";
    }
}