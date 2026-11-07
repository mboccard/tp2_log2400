#pragma once

#include "Chauffage.h"
#include "Constantes.h"

class ChauffagePro : public Chauffage {
protected:
    double vitesse() const override { return constantes::VITESSE_CHAUFFAGE_PRO; }
};
