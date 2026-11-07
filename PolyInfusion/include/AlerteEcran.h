#pragma once

#include "ObservateurReserve.h"

// Observateur concret : alerte affichée à l'écran (toujours active).
class AlerteEcran : public ObservateurReserve {
public:
    void reserveFaible(const Reserve& reserve) override;
    void reserveRetablie(const Reserve& reserve) override;
};
