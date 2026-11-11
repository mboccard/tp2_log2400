#pragma once

#include <string>

#include "Sujet.h"

class Reserve : public Sujet {
public:
    Reserve(std::string nom, std::string unite, double quantiteInitiale, double seuil);

    const std::string& getNom() const;
    const std::string& getUnite() const;
    double getQuantite() const;
    void retirer(double quantite);
    void ajouter(double quantite);

private:
    std::string nom_;
    std::string unite_;
    double quantite_;
    double seuil_;
    bool sousSeuil_;
};