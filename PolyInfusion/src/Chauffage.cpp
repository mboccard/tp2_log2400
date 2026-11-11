#include "Chauffage.h"

#include <iostream>

void Chauffage::chauffer(double temperatureCible, const std::string& description) const
{
    const double duree = (temperatureCible - constantes::TEMPERATURE_INITIALE_CHAUFFAGE) / vitesse();

    std::cout << "Chauffage ";
    if (!description.empty()) {
        std::cout << description << " ";
    }
    std::cout << "à " << temperatureCible << " °C : " << duree << " secondes simulées.\n";
}
