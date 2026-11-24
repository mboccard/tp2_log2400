#pragma once
#include "IterateurAbstrait.h"
#include <vector>
class CommandeElementaire;

class IterateurCommandes : public IterateurAbstrait {
public:
    explicit IterateurCommandes(std::vector<const CommandeElementaire*> commandes);
    void premier() override;
    void suivant() override;
    const CommandeElementaire& getCourant() const override;
    bool estTermine() const override;
private:
    std::vector<const CommandeElementaire*> commandes_;
    int index_ = 0;
};