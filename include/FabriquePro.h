#pragma once

#include "FabriqueComposants.h"

class FabriquePro : public FabriqueComposants {
public:
    std::unique_ptr<Chauffage> creerChauffage() const override;
    std::unique_ptr<DistributeurEau> creerDistributeurEau() const override;
    std::unique_ptr<DistributeurThe> creerDistributeurThe() const override;
};
