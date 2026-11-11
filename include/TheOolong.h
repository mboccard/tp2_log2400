#pragma once

#include <memory>

#include "Constantes.h"
#include "InfusionAvecRincage.h"
#include "The.h"

class TheOolong : public The {
public:
    TheOolong() : The(constantes::NOM_OOLONG, constantes::OOLONG_QUANTITE_FEUILLES_G, constantes::OOLONG_VOLUME_SERVI_ML, constantes::OOLONG_TEMPERATURE_C, constantes::OOLONG_DUREE_INFUSION_S, std::make_unique<InfusionAvecRincage>(50.0)) {}
};
