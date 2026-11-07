#pragma once

#include "FabriqueComposants.h"

class FabriqueCompact : public FabriqueComposants {
public:
    std::unique_ptr<Chauffage> creerChauffage() const override;
    std::unique_ptr<DistributeurEau> creerDistributeurEau() const override;
    std::unique_ptr<DistributeurThe> creerDistributeurThe() const override;
};
