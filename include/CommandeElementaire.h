#pragma once
#include "Commande.h"
#include <string>

class CommandeElementaire : public Commande {
public:
    std::vector<const CommandeElementaire*> obtenirCommandesElementaires() const override;
    IterateurCommandes creerIterateur() const override;
    virtual std::string decrire() const = 0;
};