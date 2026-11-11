#pragma once

#include "Distributeur.h"

class DistributeurEau : public Distributeur {
protected:
    explicit DistributeurEau(double facteurPerte) : Distributeur(facteurPerte) {}
};
