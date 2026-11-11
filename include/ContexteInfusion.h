#pragma once
 
#include "Chauffage.h";
#include "DistributeurEau.h";
#include "DistributeurThe.h";
#include "Infuseur.h";
#include "Reserve.h";

class ContexteInfusion {
public:
    Chauffage& chauffage;
    DistributeurEau& distributeurEau;
    DistributeurThe& distributeurThe;
    Infuseur& infuseur;
    Reserve& reserveEau;
    Reserve& reserveThe;
};