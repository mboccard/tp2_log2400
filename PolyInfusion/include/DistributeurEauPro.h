#pragma once

#include "Constantes.h"
#include "DistributeurEau.h"

class DistributeurEauPro : public DistributeurEau {
public:
    DistributeurEauPro() : DistributeurEau(constantes::FACTEUR_PERTE_AUCUNE) {}
};