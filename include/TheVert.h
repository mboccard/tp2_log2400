#pragma once
 
#include <memory>

#include "Constantes.h"
#include "InfusionDirecte.h"
#include "The.h"
 
class TheVert : public The {
public:
    TheVert() : The(constantes::NOM_VERT, constantes::VERT_QUANTITE_FEUILLES_G, constantes::VERT_VOLUME_SERVI_ML, constantes::VERT_TEMPERATURE_C, constantes::VERT_DUREE_INFUSION_S, std::make_unique<InfusionDirecte>()) {}
};