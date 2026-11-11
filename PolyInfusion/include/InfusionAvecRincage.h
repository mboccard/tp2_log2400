#pragma once
#include "StrategieInfusion.h"

class InfusionAvecRincage : public StrategieInfusion {
public:
    explicit InfusionAvecRincage(double volumeRincage);

protected:
    bool phasePreliminaire(const The& the, ContexteInfusion& contexte) const override;
    Besoins obtenirBesoinsPreliminaires(const The& the, ContexteInfusion& contexte) const override;
 
private:
    double volumeRincage_;
};