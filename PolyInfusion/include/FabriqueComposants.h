#pragma once

#include <memory>

#include "Chauffage.h"
#include "DistributeurEau.h"
#include "DistributeurThe.h"

class FabriqueComposants {
public:
    virtual ~FabriqueComposants() = default;

    virtual std::unique_ptr<Chauffage> creerChauffage() const = 0;
    virtual std::unique_ptr<DistributeurEau> creerDistributeurEau() const = 0;
    virtual std::unique_ptr<DistributeurThe> creerDistributeurThe() const = 0;
};
