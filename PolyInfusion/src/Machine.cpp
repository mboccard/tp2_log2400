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
 
    // Chaque thé a sa propre réserve, abonnée aux alertes.
    for (const auto& the : thes_) {
        const std::string nom = the->getNom();
        reservesThe_.emplace(nom, Reserve(constantes::PREFIXE_NOM_RESERVE_THE + nom, constantes::UNITE_THE, constantes::THE_INITIAL_G, constantes::SEUIL_THE_G));
        abonner(reservesThe_.at(nom));
    }
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
    theCourant_ = the;
    std::cout << "Thé sélectionné : " << the->getNom() << ".\n";
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
    if (theCourant_ == nullptr) {
        std::cout << "Erreur : aucun thé sélectionné.\n";
        return;
    }

    Reserve& reserveThe = reservesThe_.at(theCourant_->getNom());
    ContexteInfusion contexte{*chauffage_, *distributeurEau_, *distributeurThe_, infuseur_, reserveEau_, reserveThe};

    const Besoins besoins = theCourant_->calculerBesoins(contexte);
    if (!reservesSuffisantes(besoins, reserveThe)) {
        return;
    }

    theCourant_->preparer(contexte);
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
