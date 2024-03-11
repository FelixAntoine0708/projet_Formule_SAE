/*
Programme : CONST_AFF_BAT.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      5 mars 2024
Brief :     Ce fichier contiens toutes les constantes pour la page BATTERIE.

Matérielle: ESP32-S3R8 (dans l'écran), écran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7,
Système d'exploitation : Windows 10 V22H2.
*/

#include "CONST_AFF.h"



// ---------------------------PAGE BATTERIE-----------------------------

#define POSY_NOM_DON 125    // Position en Y des nom des données
#define POSY_BAR 150        // Position en Y des bandes


// ------------ TEMPÉRATURE ----------------------------------------

#define POSX_NOM_TEMP 50    // Position en X du nom "TEMPÉRATURE"



#define POSX_BAR_TEMP 100   // Position en X de la bande "TEMPÉRATURE"


//#define POSY_1_J_TEMP POSY_BAR + HAUT_R
//#define POSY_2_J_TEMP POSY_BAR + HAUT_R + HAUT_J
//#define POSY_1_V_TEMP POSY_BAR + HAUT_R + HAUT_J
//#define POSY_2_V_TEMP POSY_BAR + HAUT_R + HAUT_J + HAUT_V

#define POSY_1_J_TEMP POSY_BAR + HAUT_R         // Position de Y_1 de la bande jaune "TEMPÉRATURE"
#define POSY_2_J_TEMP POSY_1_J_TEMP + HAUT_J    // Position de Y_2 de la bande jaune "TEMPÉRATURE"

#define POSY_1_V_TEMP POSY_2_J_TEMP             // Position de Y_1 de la bande verte "TEMPÉRATURE"
#define POSY_2_V_TEMP POSY_1_V_TEMP + HAUT_V    // Position de Y_2 de la bande verte "TEMPÉRATURE"


// -------------- CHARGE -----------------------------------------

#define POSX_NOM_CHAR 350   // Position en X du nom "CHARGE"
 
#define POSX_BAR_CHAR 400   // Position en X de la bande "CHARGE"

#define LARGE_BAR_CHAR POSX_BAR_CHAR + LARGEUR      // Position en X_2 (la LARGEURE) des bandes "CHARGE"

// SECTION VERT
#define POSY_1_V_CHAR POSY_BAR              // Position en Y_1 de la bande verte "CHARGE"
#define POSY_2_V_CHAR POSY_BAR + HAUT_V     // Position en Y_2 de la bande verte "CHARGE"

// SECTION JAUNE
#define POSY_1_J_CHAR POSY_2_V_CHAR             // Position en Y_1 de la bande jaune "CHARGE"
#define POSY_2_J_CHAR POSY_1_J_CHAR + HAUT_J    // Position en Y_2 de la bande jaune "CHARGE"

// SECTION ROUGE
#define POSY_1_R_CHAR POSY_2_J_CHAR             // Position en Y_1 de la bande rouge "CHARGE"
#define POSY_2_R_CHAR POSY_1_R_CHAR + HAUT_R    // Position en Y_2 de la bande rouge "CHARGE"


// --------------- TENSION ---------------------------

#define POSX_NOM_TENS 600   // Position en X du nom "TENSION"
#define POSY_NOM_TENS 250   // Position en Y du nom "TENSION"