#pragma once

class Reserve;

// Rôle « Observateur » : réagit aux franchissements de seuil d'une réserve.
// La réserve est transmise en lecture seule (modèle « tirer »).
class ObservateurReserve {
public:
    virtual ~ObservateurReserve() = default;

    // La réserve vient de passer strictement sous son seuil.
    virtual void reserveFaible(const Reserve& reserve) = 0;

    // La réserve vient d'atteindre ou de repasser au-dessus de son seuil.
    virtual void reserveRetablie(const Reserve& reserve) = 0;
};
