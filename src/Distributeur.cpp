#include "Distributeur.h"

#include <iostream>
#include <string>

#include "Constantes.h"
#include "Reserve.h"

Distributeur::Distributeur(double facteurPerte) : facteurPerte_(facteurPerte) {}

double Distributeur::obtenirQuantiteReelle(double quantiteNominale) const
{
    return quantiteNominale * facteurPerte_;
}

void Distributeur::distribuer(double quantiteNominale, Reserve& reserve) const
{
    const double quantite = obtenirQuantiteReelle(quantiteNominale);
    const std::string de = (reserve.getNom() == constantes::NOM_RESERVE_EAU) ? "d’" : "de ";
 
    std::cout << "Consommation " << de << reserve.getNom() << " : " << quantite << " " << reserve.getUnite() << ".\n";
    reserve.retirer(quantite);
}