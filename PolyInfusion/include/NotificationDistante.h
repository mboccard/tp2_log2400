#pragma once

#include "ObservateurReserve.h"

// Observateur concret : notification à distance (simulée dans la console).
// Peut être attaché ou détaché des réserves par la machine.
class NotificationDistante : public ObservateurReserve {
public:
    void reserveFaible(const Reserve& reserve) override;
    void reserveRetablie(const Reserve& reserve) override;
};
