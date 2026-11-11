#pragma once

#include "Reserve.h"

class ObservateurReserve {
public:
    virtual ~ObservateurReserve() = default;

    virtual void reserveFaible(const Reserve& reserve) = 0;
    virtual void reserveRetablie(const Reserve& reserve) = 0;
};
