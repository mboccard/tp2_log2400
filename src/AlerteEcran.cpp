#include "AlerteEcran.h"

#include <iostream>
#include <string>

#include "Reserve.h"

void AlerteEcran::reserveFaible(const Reserve& reserve)
{
    const std::string de = (reserve.getNom() == "eau") ? "d’" : "de ";
    std::cout << "[Écran] Réserve " << de << reserve.getNom() << " faible : " << reserve.getQuantite() << " " << reserve.getUnite() << ".\n";
}

void AlerteEcran::reserveRetablie(const Reserve& reserve)
{
    const std::string de = (reserve.getNom() == "eau") ? "d’" : "de ";
    std::cout << "[Écran] Réserve " << de << reserve.getNom() << " de nouveau suffisante : " << reserve.getQuantite() << " " << reserve.getUnite() << ".\n";
}
