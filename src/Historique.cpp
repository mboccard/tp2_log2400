#include "Historique.h"

bool Historique::executer(std::unique_ptr<Commande> commande)
{
    if (!commande->executer()) {
        return false;
    }
    pileFait_.push_back(std::move(commande));
    pileAnnuler_.clear();
    return true;
}

bool Historique::undo()
{
    if (pileFait_.empty()) {
        return false;
    }
    std::unique_ptr<Commande> commande = std::move(pileFait_.back());
    pileFait_.pop_back();
    commande->undo();
    pileAnnuler_.push_back(std::move(commande));
    return true;
}

bool Historique::redo()
{
    if (pileAnnuler_.empty()) {
        return false;
    }
    std::unique_ptr<Commande> commande = std::move(pileAnnuler_.back());
    pileAnnuler_.pop_back();
    commande->redo();
    pileFait_.push_back(std::move(commande));
    return true;
}