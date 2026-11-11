#pragma once

#include "Constantes.h"
#include "DistributeurThe.h"

class DistributeurThePro : public DistributeurThe {
public:
    DistributeurThePro() : DistributeurThe(constantes::FACTEUR_PERTE_AUCUNE) {}
};