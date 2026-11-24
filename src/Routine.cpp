#include "Routine.h"

Routine::Routine(std::string nom) : nom_(std::move(nom)) {}

const std::string& Routine::getNom() const
{
    return nom_;
}

void Routine::ajouterCommande(std::unique_ptr<Commande> commande)
{
    commandes_.push_back(std::move(commande));
}

bool Routine::executer()
{
    for (const auto& commande : commandes_) {
        if (!commande->executer()) {
            return false;
        }
    }
    return true;
}

void Routine::undo()
{
    for (auto it = commandes_.rbegin(); it != commandes_.rend(); ++it) {
        (*it)->undo();
    }
}

void Routine::redo()
{
    for (const auto& commande : commandes_) {
        commande->redo();
    }
}

std::vector<const CommandeElementaire*> Routine::obtenirCommandesElementaires() const
{
    std::vector<const CommandeElementaire*> commandesElementaires;
    for (const auto& commande : commandes_) {
        auto elementaires = commande->obtenirCommandesElementaires();
        commandesElementaires.insert(commandesElementaires.end(), elementaires.begin(), elementaires.end());
    }
    return commandesElementaires;
}

IterateurCommandes Routine::creerIterateur() const
{
    return IterateurCommandes(obtenirCommandesElementaires());
}