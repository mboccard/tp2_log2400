#pragma once
#include <vector>
#include "IterateurCommandes.h"
class CommandeElementaire;

class Commande {
public:
    virtual ~Commande() = default;
    virtual bool executer() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
    virtual std::vector<const CommandeElementaire*> obtenirCommandesElementaires() const = 0;
    virtual IterateurCommandes creerIterateur() const = 0;
};