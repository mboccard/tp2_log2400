#include "IterateurCommandes.h"
#include <utility>

IterateurCommandes::IterateurCommandes(std::vector<const CommandeElementaire*> commandes) : commandes_(std::move(commandes)) {}

void IterateurCommandes::premier() {
    index_ = 0;
}

void IterateurCommandes::suivant() {
    if (!estTermine()) {
        ++index_;
    }
}

const CommandeElementaire& IterateurCommandes::getCourant() const {
    return *commandes_[index_];
}

bool IterateurCommandes::estTermine() const {
    return index_ >= static_cast<int>(commandes_.size());
}