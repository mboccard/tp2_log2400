#pragma once

#include <memory>
#include <string>

#include "Besoins.h"

class ContexteInfusion;
class StrategieInfusion;

class The {
public:
    virtual ~The();

    const std::string& getNom() const;
    double getQuantiteFeuilles() const;   // en g
    double getVolumeServi() const;        // en mL
    double getTemperatureCible() const;   // en °C
    int getDureeInfusion() const;         // en secondes

    // Ressources totales requises pour préparer ce thé (pertes incluses).
    // Aucune consommation n'est effectuée.
    Besoins calculerBesoins(ContexteInfusion& contexte) const;

    // Prépare le thé en déléguant à la stratégie d'infusion.
    void preparer(ContexteInfusion& contexte) const;

protected:
    The(std::string nom, double quantiteFeuilles, double volumeServi, double temperatureCible, int dureeInfusion, std::unique_ptr<StrategieInfusion> strategie);

private:
    std::string nom_;
    double quantiteFeuilles_;
    double volumeServi_;
    double temperatureCible_;
    int dureeInfusion_;
    std::unique_ptr<StrategieInfusion> strategie_;
};
