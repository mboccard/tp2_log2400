#include "InfusionAvecRincage.h"

InfusionAvecRincage::InfusionAvecRincage(double volumeRincage) : volumeRincage_(volumeRincage) {}
 
bool InfusionAvecRincage::phasePreliminaire(const The& the, ContexteInfusion& contexte) const
{
    contexte.chauffage.chauffer(the.getTemperatureCible(), "de l’eau de rinçage");
    contexte.distributeurEau.distribuer(volumeRincage_, contexte.reserveEau);
    contexte.distributeurThe.distribuer(the.getQuantiteFeuilles(), contexte.reserveThe);
    contexte.infuseur.rincer();
    contexte.infuseur.evacuer();
    return true;
}
 
Besoins InfusionAvecRincage::obtenirBesoinsPreliminaires(const The& the, ContexteInfusion& contexte) const
{
    return Besoins(contexte.distributeurEau.obtenirQuantiteReelle(volumeRincage_), contexte.distributeurThe.obtenirQuantiteReelle(the.getQuantiteFeuilles()));
}