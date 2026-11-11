#include "AlerteTexte.h"

#include <iostream>

#include "Constantes.h"
#include "Reserve.h"

void AlerteTexte::reserveFaible(const Reserve& reserve)
{
    const std::string de = (reserve.getNom() == constantes::NOM_RESERVE_EAU) ? "d’" : "de ";
    std::cout << getEtiquette() << " Réserve " << de << reserve.getNom() << " faible : " << reserve.getQuantite() << " " << reserve.getUnite() << ".\n";
}

void AlerteTexte::reserveRetablie(const Reserve& reserve)
{
    const std::string de = (reserve.getNom() == constantes::NOM_RESERVE_EAU) ? "d’" : "de ";
    std::cout << getEtiquette() << " Réserve " << de << reserve.getNom() << " de nouveau suffisante : " << reserve.getQuantite() << " " << reserve.getUnite() << ".\n";
}