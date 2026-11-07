#pragma once

#include <string>

class Chauffage {
public:
    virtual ~Chauffage() = default;

    // Affiche le chauffage et sa durée simulée.
    // description : complément du message, par exemple "de l’eau de rinçage".
    // Laisser vide pour une infusion directe : « Chauffage à 80 °C : ... ».
    void chauffer(double temperatureCible, const std::string& description) const;

protected:
    // Température de départ de l’eau, en °C.
    static constexpr double TEMPERATURE_INITIALE = 20.0;

    // Vitesse de chauffe, en °C par seconde.
    virtual double vitesse() const = 0;
};
