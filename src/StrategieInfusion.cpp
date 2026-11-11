#include "StrategieInfusion.h"
#include <iostream>
#include <string>

Besoins StrategieInfusion::calculerBesoins(const The& the, ContexteInfusion& contexte) const 
{
    const Besoins preliminaires = obtenirBesoinsPreliminaires(the, contexte);
    const bool theDejaDose = preliminaires.getThe() > 0;

    return preliminaires.ajouter(obtenirBesoinsInfusion(the, contexte, !theDejaDose));
}

void StrategieInfusion::executer(const The& the, ContexteInfusion& contexte) const 
{
    std::cout << "Préparation d’un thé " << the.getNom() << ".\n";
 
    const bool theDejaDose = phasePreliminaire(the, contexte);
    phaseInfusion(the, contexte, !theDejaDose);
    servir(the, contexte);
 
    std::cout << "Votre thé est prêt.\n";
}

bool StrategieInfusion::phasePreliminaire(const The& the, ContexteInfusion& contexte) const
{
    return false;
}

Besoins StrategieInfusion::obtenirBesoinsPreliminaires(const The& the, ContexteInfusion& contexte) const
{
    return Besoins(0.0, 0.0);
}

Besoins StrategieInfusion::obtenirBesoinsInfusion(const The& the, ContexteInfusion& contexte, bool doserThe) const 
{
    const double eau = contexte.distributeurEau.obtenirQuantiteReelle(the.getVolumeServi());
    const double feuilles = doserThe ? contexte.distributeurThe.obtenirQuantiteReelle(the.getQuantiteFeuilles()) : 0.0;
    return Besoins(eau, feuilles);
}


void StrategieInfusion::phaseInfusion(const The& the, ContexteInfusion& contexte, bool doserThe) const
{
    const std::string description = doserThe ? "" : "de l’eau de préparation";
 
    contexte.chauffage.chauffer(the.getTemperatureCible(), description);
    contexte.distributeurEau.distribuer(the.getVolumeServi(), contexte.reserveEau);
    if (doserThe) {
        contexte.distributeurThe.distribuer(the.getQuantiteFeuilles(), contexte.reserveThe);
    }
    contexte.infuseur.infuser(the.getDureeInfusion());
}

void StrategieInfusion::servir(const The& the, ContexteInfusion& contexte) const
{
    contexte.infuseur.servir(the.getVolumeServi());
}
