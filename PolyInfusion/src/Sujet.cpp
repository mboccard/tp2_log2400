#include "Sujet.h"

#include <algorithm>

#include "ObservateurReserve.h"

void Sujet::attacher(ObservateurReserve* observateur)
{
    if (observateur == nullptr) {
        return;
    }
    const auto it = std::find(observateurs_.begin(), observateurs_.end(), observateur);
    if (it == observateurs_.end()) {
        observateurs_.push_back(observateur);
    }
}

void Sujet::detacher(ObservateurReserve* observateur)
{
    observateurs_.erase(std::remove(observateurs_.begin(), observateurs_.end(), observateur), observateurs_.end());
}

void Sujet::notifierFaible(const Reserve& reserve) const
{
    for (ObservateurReserve* observateur : observateurs_) {
        observateur->reserveFaible(reserve);
    }
}

void Sujet::notifierRetablie(const Reserve& reserve) const
{
    for (ObservateurReserve* observateur : observateurs_) {
        observateur->reserveRetablie(reserve);
    }
}
