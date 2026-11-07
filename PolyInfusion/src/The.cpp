#include "The.h"

#include <utility>

#include "ContexteInfusion.h"
#include "StrategieInfusion.h"

The::~The() = default;

The::The(std::string nom, double quantiteFeuilles, double volumeServi, double temperatureCible, int dureeInfusion, std::unique_ptr<StrategieInfusion> strategie) : nom_(std::move(nom)), quantiteFeuilles_(quantiteFeuilles), volumeServi_(volumeServi), temperatureCible_(temperatureCible), dureeInfusion_(dureeInfusion), strategie_(std::move(strategie)) {}

const std::string& The::getNom() const { return nom_; }
double The::getQuantiteFeuilles() const { return quantiteFeuilles_; }
double The::getVolumeServi() const { return volumeServi_; }
double The::getTemperatureCible() const { return temperatureCible_; }
int The::getDureeInfusion() const { return dureeInfusion_; }

Besoins The::calculerBesoins(ContexteInfusion& contexte) const
{
    return strategie_->calculerBesoins(*this, contexte);
}

void The::preparer(ContexteInfusion& contexte) const
{
    strategie_->executer(*this, contexte);
}
