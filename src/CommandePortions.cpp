#include "CommandePortions.h"
#include <iostream>

CommandePortions::CommandePortions(Configuration& configuration, int nPortions) : configuration_(configuration), nPortions_(nPortions) {}

bool CommandePortions::executer()
{
    ancienNPortions_ = configuration_.getNPortions();
    if(!configuration_.setNPortions(nPortions_)) {
        std::cout << "Erreur : le nombre de portions doit être un entier strictement positif.\n";
        return false;
    }
    std::cout << "Nombre de portions : " << nPortions_ << ".\n";
    return true;
}

void CommandePortions::undo()
{
    configuration_.setNPortions(ancienNPortions_);
}

void CommandePortions::redo()
{
    configuration_.setNPortions(nPortions_);
}

std::string CommandePortions::decrire() const
{
    return "Régler le nombre de portions à " + std::to_string(nPortions_) + ".";
}