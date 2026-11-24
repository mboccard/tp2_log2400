#include "CommandeElementaire.h"

std::vector<const CommandeElementaire*> CommandeElementaire::obtenirCommandesElementaires() const
{
    return {this};
}

IterateurCommandes CommandeElementaire::creerIterateur() const
{
    return IterateurCommandes(obtenirCommandesElementaires());
}
