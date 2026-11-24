#pragma once

class CommandeElementaire;

class IterateurAbstrait {
public:
    virtual ~IterateurAbstrait() = default;

    virtual void premier() = 0;
    virtual void suivant() = 0;
    virtual const CommandeElementaire& getCourant() const = 0;
    virtual bool estTermine() const = 0;
};