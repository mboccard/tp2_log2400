#pragma once

#include <memory>

#include "Constantes.h"
#include "InfusionDirecte.h"
#include "The.h"

class TheNoir : public The {
public:
    TheNoir() : The(constantes::NOM_NOIR, constantes::NOIR_QUANTITE_FEUILLES_G, constantes::NOIR_VOLUME_SERVI_ML, constantes::NOIR_TEMPERATURE_C, constantes::NOIR_DUREE_INFUSION_S, std::make_unique<InfusionDirecte>()) {}
};
