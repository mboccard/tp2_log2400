#pragma once

#include <string>

#include "Sujet.h"

// Contenant d'une ressource (eau en mL, ou un type de thé en g).
// Notifie ses observateurs uniquement lorsqu'elle FRANCHIT son seuil :
//   - faible   : la quantité passe strictement sous le seuil ;
//   - rétablie : la quantité atteint ou repasse au-dessus du seuil.
class Reserve : public Sujet {
public:
    // nom : en minuscules, par exemple "eau" ou "thé vert".
    Reserve(std::string nom, std::string unite, double quantiteInitiale, double seuil);

    const std::string& getNom() const;
    const std::string& getUnite() const;
    double getQuantite() const;

    // Lance std::invalid_argument si la quantité demandée dépasse la quantité disponible.
    void retirer(double quantite);
    void ajouter(double quantite);

private:
    std::string nom_;
    std::string unite_;
    double quantite_;
    double seuil_;
    bool sousSeuil_;
};