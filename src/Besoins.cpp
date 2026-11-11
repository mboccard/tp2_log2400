#include "Besoins.h"

Besoins Besoins::ajouter(const Besoins& autre) const 
{
    return Besoins(eau_ + autre.eau_, the_ + autre.the_);
}

double Besoins::getEau() const 
{
    return eau_;
}

double Besoins::getThe() const 
{
    return the_;
}