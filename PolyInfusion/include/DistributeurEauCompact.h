#pragma once

#include "Constantes.h"
#include "DistributeurEau.h"

class DistributeurEauCompact : public DistributeurEau {
public:
    DistributeurEauCompact() : DistributeurEau(constantes::FACTEUR_PERTE_EAU_COMPACT) {}
};