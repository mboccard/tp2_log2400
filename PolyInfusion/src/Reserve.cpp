#include "Reserve.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

#include "Constantes.h"

Reserve::Reserve(std::string nom, std::string unite, double quantiteInitiale, double seuil)
    : nom_(std::move(nom)),
      unite_(std::move(unite)),
      quantite_(quantiteInitiale),
      seuil_(seuil),
      sousSeuil_(quantiteInitiale < seuil - constantes::EPSILON)
{
}

const std::string& Reserve::getNom() const { return nom_; }
const std::string& Reserve::getUnite() const { return unite_; }
double Reserve::getQuantite() const { return quantite_; }

void Reserve::retirer(double quantite)
{
    if (quantite_ + constantes::EPSILON < quantite) {
        throw std::invalid_argument("Reserve::retirer : quantité insuffisante");
    }
    quantite_ = std::max(0.0, quantite_ - quantite);

    if (!sousSeuil_ && quantite_ < seuil_ - constantes::EPSILON) {
        sousSeuil_ = true;
        notifierFaible(*this);
    }
}

void Reserve::ajouter(double quantite)
{
    quantite_ += quantite;

    if (sousSeuil_ && quantite_ >= seuil_ - constantes::EPSILON) {
        sousSeuil_ = false;
        notifierRetablie(*this);
    }
}