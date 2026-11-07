#pragma once

// Constantes de l’énoncé (réserves, seuils, paramètres des modèles).
// « inline constexpr » (C++17) : définies directement dans l’en-tête, sans .cpp.
namespace constantes {

// Tolérance pour comparer des nombres à virgule flottante.
inline constexpr double EPSILON = 1e-9;

// Unités d’affichage.
inline constexpr const char* UNITE_EAU = "mL";
inline constexpr const char* UNITE_THE = "g";

// Réserves au lancement du système.
inline constexpr double EAU_INITIALE_ML = 2000.0;
inline constexpr double THE_INITIAL_G = 20.0;

// Seuils de notification (strictement sous le seuil = réserve faible).
inline constexpr double SEUIL_EAU_ML = 500.0;
inline constexpr double SEUIL_THE_G = 10.0;

// Chauffage (la température initiale est un attribut de la classe Chauffage).
inline constexpr double VITESSE_CHAUFFAGE_COMPACT = 5.0; // °C par seconde
inline constexpr double VITESSE_CHAUFFAGE_PRO = 10.0;    // °C par seconde

// Distributeurs : facteur appliqué à la quantité prévue par le profil.
inline constexpr double FACTEUR_PERTE_EAU_COMPACT = 1.2;
inline constexpr double FACTEUR_PERTE_THE_COMPACT = 1.1;
inline constexpr double FACTEUR_PERTE_AUCUNE = 1.0;

} // namespace constantes
