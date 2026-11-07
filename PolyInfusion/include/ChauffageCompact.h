#pragma once

#include "Chauffage.h"
#include "Constantes.h"

class ChauffageCompact : public Chauffage {
protected:
    double vitesse() const override { return constantes::VITESSE_CHAUFFAGE_COMPACT; }
};
