#pragma once

#include <string>
#include "Constantes.h"

class Chauffage {
public:
    virtual ~Chauffage() = default;
    void chauffer(double temperatureCible, const std::string& description) const;

protected:
    virtual double vitesse() const = 0;
};
