#include "FabriqueCompact.h"

#include "ChauffageCompact.h"
#include "DistributeurEauCompact.h"
#include "DistributeurTheCompact.h"

std::unique_ptr<Chauffage> FabriqueCompact::creerChauffage() const
{
    return std::make_unique<ChauffageCompact>();
}

std::unique_ptr<DistributeurEau> FabriqueCompact::creerDistributeurEau() const
{
    return std::make_unique<DistributeurEauCompact>();
}

std::unique_ptr<DistributeurThe> FabriqueCompact::creerDistributeurThe() const
{
    return std::make_unique<DistributeurTheCompact>();
}
