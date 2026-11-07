#include "NotificationDistante.h"

#include <iostream>
#include <string>

#include "Reserve.h"

void NotificationDistante::reserveFaible(const Reserve& reserve)
{
    const std::string de = (reserve.getNom() == "eau") ? "d’" : "de ";
    std::cout << "[Notification distante] Réserve " << de << reserve.getNom() << " faible : " << reserve.getQuantite() << " " << reserve.getUnite() << ".\n";
}

void NotificationDistante::reserveRetablie(const Reserve& reserve)
{
    const std::string de = (reserve.getNom() == "eau") ? "d’" : "de ";
    std::cout << "[Notification distante] Réserve " << de << reserve.getNom() << " de nouveau suffisante : " << reserve.getQuantite() << " " << reserve.getUnite() << ".\n";
}
