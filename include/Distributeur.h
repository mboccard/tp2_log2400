#pragma once

#include "Reserve.h"

class Distributeur {
public:
    virtual ~Distributeur() = default;
    double obtenirQuantiteReelle(double quantiteNominale) const;
    void distribuer(double quantiteNominale, Reserve& reserve) const;

protected:
    explicit Distributeur(double facteurPerte);

private:
    double facteurPerte_;
};
