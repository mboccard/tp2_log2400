#include "FabriquePro.h"

#include "ChauffagePro.h"
#include "DistributeurEauPro.h"
#include "DistributeurThePro.h"

std::unique_ptr<Chauffage> FabriquePro::creerChauffage() const
{
    return std::make_unique<ChauffagePro>();
}

std::unique_ptr<DistributeurEau> FabriquePro::creerDistributeurEau() const
{
    return std::make_unique<DistributeurEauPro>();
}

std::unique_ptr<DistributeurThe> FabriquePro::creerDistributeurThe() const
{
    return std::make_unique<DistributeurThePro>();
}
