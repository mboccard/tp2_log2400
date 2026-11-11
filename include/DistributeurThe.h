#pragma once

#include "Distributeur.h"

class DistributeurThe : public Distributeur {
protected:
    explicit DistributeurThe(double facteurPerte) : Distributeur(facteurPerte) {}
};
