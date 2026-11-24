#pragma once

#include "Constantes.h"
#include "The.h"

class Configuration {
public:
    const The* getTheCourant() const;
    void setTheCourant(const The* the);
    int getNPortions() const;
    bool setNPortions(int nPortions);
private:
    const The* theCourant_ = nullptr;
    int nPortions_ = constantes::PORTIONS_INITIALES;
};