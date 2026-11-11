#pragma once
#include "Besoins.h"
#include "ContexteInfusion.h"
#include "The.h"

class StrategieInfusion {
public:
    virtual ~StrategieInfusion() = default;

    Besoins calculerBesoins(const The& the, ContexteInfusion& contexte) const;
    void executer(const The& the, ContexteInfusion& contexte) const;

protected:
    virtual bool phasePreliminaire(const The& the, ContexteInfusion& contexte) const;
    virtual Besoins obtenirBesoinsPreliminaires(const The& the, ContexteInfusion& contexte) const;
    Besoins obtenirBesoinsInfusion(const The& the, ContexteInfusion& contexte, bool doserThe) const;
    void phaseInfusion(const The& the, ContexteInfusion& contexte, bool doserThe) const;
    void servir(const The& the, ContexteInfusion& contexte) const;
};
