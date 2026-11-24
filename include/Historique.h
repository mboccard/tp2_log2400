#pragma once

#include "Commande.h"
#include <vector>
#include <memory>

class Historique {
public:
    bool executer(std::unique_ptr<Commande> commande);
    bool undo();
    bool redo();
private:
    std::vector<std::unique_ptr<Commande>> pileFait_;
    std::vector<std::unique_ptr<Commande>> pileAnnuler_;
};