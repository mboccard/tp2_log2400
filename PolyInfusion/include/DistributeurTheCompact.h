#pragma once

#include "Constantes.h"
#include "DistributeurThe.h"

class DistributeurTheCompact : public DistributeurThe {
public:
    DistributeurTheCompact() : DistributeurThe(constantes::FACTEUR_PERTE_THE_COMPACT) {}
};