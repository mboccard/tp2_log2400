#pragma once

#include "Commande.h"
#include <vector>
#include <memory>
#include <string>
#include "CommandeElementaire.h"

class Routine : public Commande {
public:
    explicit Routine(std::string nom);
    bool executer() override;
    void undo() override;
    void redo() override;
    std::vector<const CommandeElementaire*> obtenirCommandesElementaires() const override;
    IterateurCommandes creerIterateur() const override;
    const std::string& getNom() const;
    void ajouterCommande(std::unique_ptr<Commande> commande);
private:
    std::vector<std::unique_ptr<Commande>> commandes_;
    std::string nom_;
};