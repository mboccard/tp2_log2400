#include "CommandeSelection.h"
#include <iostream>

CommandeSelection::CommandeSelection(Configuration& configuration, const The* the) : configuration_(configuration), the_(the) {}

bool CommandeSelection::executer()
{
    ancienThe_ = configuration_.getTheCourant();
    configuration_.setTheCourant(the_);
    std::cout << "Thé sélectionné : " << the_->getNom() << ".\n";
    return true;
}

void CommandeSelection::undo()
{
    configuration_.setTheCourant(ancienThe_);
}

void CommandeSelection::redo()
{
    configuration_.setTheCourant(the_);
}

std::string CommandeSelection::decrire() const
{
    return "Sélectionner le thé " + the_->getNom() + ".";
}