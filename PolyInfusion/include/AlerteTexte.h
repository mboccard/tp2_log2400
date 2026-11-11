#pragma once

#include <string>

#include "ObservateurReserve.h"

class AlerteTexte : public ObservateurReserve {
public:
    void reserveFaible(const Reserve& reserve);
    void reserveRetablie(const Reserve& reserve);

protected:
    virtual std::string getEtiquette() const = 0;
};