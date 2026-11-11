#include "Infuseur.h"
#include <iostream>
#include "Constantes.h"

void Infuseur::infuser(int dureeSecondes) const 
{
    std::cout << "Infusion : " << dureeSecondes << " secondes simulées.\n";
}

void Infuseur::evacuer() const 
{
    std::cout << "Évacuation de l’eau de rinçage.\n";
}

void Infuseur::rincer() const 
{
   std::cout << "Rinçage des feuilles.\n";
}

void Infuseur::servir(double volume) const 
{
    std::cout << "Service : " << volume << " " << constantes::UNITE_EAU << ".\n";
}
