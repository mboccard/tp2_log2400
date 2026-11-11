#pragma once

#include <string>

namespace constantes {

// Tolérance pour comparer des nombres à virgule flottante.
const double EPSILON = 1e-9;

// Unités d’affichage.
const std::string UNITE_EAU = "mL";
const std::string UNITE_THE = "g";

// Noms des réserves (le nom d'une réserve de thé est le préfixe suivi du nom du thé).
const std::string NOM_RESERVE_EAU = "eau";
const std::string PREFIXE_NOM_RESERVE_THE = "thé ";

const std::string ETIQUETTE_ALERTE_ECRAN = "[Écran]";
const std::string ETIQUETTE_NOTIFICATION_DISTANTE = "[Notification distante]";

// Réserves au lancement du système.
const double EAU_INITIALE_ML = 2000.0;
const double THE_INITIAL_G = 20.0;

// Seuils de notification (strictement sous le seuil = réserve faible).
const double SEUIL_EAU_ML = 500.0;
const double SEUIL_THE_G = 10.0;

// Chauffage (la température initiale est un attribut de la classe Chauffage).
const double VITESSE_CHAUFFAGE_COMPACT = 5.0; // °C par seconde
const double VITESSE_CHAUFFAGE_PRO = 10.0;    // °C par seconde

// Distributeurs : facteur appliqué à la quantité prévue par le profil.
const double FACTEUR_PERTE_EAU_COMPACT = 1.2;
const double FACTEUR_PERTE_THE_COMPACT = 1.1;
const double FACTEUR_PERTE_AUCUNE = 1.0;

// Profils de thé (tableau de l'énoncé).
const std::string NOM_VERT = "vert";
const double VERT_QUANTITE_FEUILLES_G = 5.0;
const double VERT_VOLUME_SERVI_ML = 250.0;
const double VERT_TEMPERATURE_C = 80.0;
const int VERT_DUREE_INFUSION_S = 120;

const std::string NOM_NOIR = "noir";
const double NOIR_QUANTITE_FEUILLES_G = 5.0;
const double NOIR_VOLUME_SERVI_ML = 250.0;
const double NOIR_TEMPERATURE_C = 95.0;
const int NOIR_DUREE_INFUSION_S = 180;

const std::string NOM_OOLONG = "oolong";
const double OOLONG_QUANTITE_FEUILLES_G = 5.0;
const double OOLONG_VOLUME_SERVI_ML = 250.0;
const double OOLONG_TEMPERATURE_C = 90.0;
const int OOLONG_DUREE_INFUSION_S = 90;
const double OOLONG_VOLUME_RINCAGE_ML = 50.0;

const double TEMPERATURE_INITIALE_CHAUFFAGE = 20.0;

}