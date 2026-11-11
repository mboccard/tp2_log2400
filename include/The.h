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
    double getQuantiteFeuilles() const;
    double getVolumeServi() const;
    double getTemperatureCible() const;
    int getDureeInfusion() const;
    Besoins calculerBesoins(ContexteInfusion& contexte) const;
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
