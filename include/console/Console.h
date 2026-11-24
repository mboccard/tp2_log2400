#pragma once

#include <string>

namespace console {

// Une instruction console est une donnée issue de la saisie utilisateur.
// Elle ne constitue pas une implémentation du patron Commande.
enum class TypeInstruction {
    Vide, Selection, Infuser, Reserves, RemplirEau, RemplirThe,
    Notifications, Aide, Quitter, Invalide, Portions, Configuration, Routine, Apercu, Undo, Redo
};

struct Instruction {
    TypeInstruction type = TypeInstruction::Vide;
    std::string the;
    double quantite = 0.0;
    bool notificationsActives = false;
    std::string erreur;
    int portions = 0;
    std::string routine;
};

Instruction analyser(const std::string& ligne);
void afficherAide();

} // namespace console
