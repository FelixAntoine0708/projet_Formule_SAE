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

#define POSY_NOM_DON_BAT 125    // Position en Y des nom des données



// ------------ TEMPÉRATURE ----------------------------------------

#define POSX_NOM_TEMP_BAT 50    // Position en X du nom "TEMPÉRATURE"

#define POSX_BAR_TEMP_BAT 100   // Position en X de la bande "TEMPÉRATURE"

#define LARG_BAR_TEMP_BAT POSX_BAR_TEMP_BAT + LARGEUR	// Position en X_2 (la LARGEURE) des bandes "TEMPERATURE"

// SECTION ROUGE
#define POSY_1_R_TEMP_BAT POSY_BAR						// Position de Y_1 de la bande rouge "TEMPERATURE"
#define POSY_2_R_TEMP_BAT POSY_1_R_TEMP_BAT + HAUT_R	// Position de Y_2 de la bande rouge "TEMPERATURE"

// SECTION JAUNE
#define POSY_1_J_TEMP_BAT POSY_2_R_TEMP_BAT         	// Position de Y_1 de la bande jaune "TEMPÉRATURE"
#define POSY_2_J_TEMP_BAT POSY_1_J_TEMP_BAT + HAUT_J    // Position de Y_2 de la bande jaune "TEMPÉRATURE"

// SECTION VERT
#define POSY_1_V_TEMP_BAT POSY_2_J_TEMP_BAT             // Position de Y_1 de la bande verte "TEMPÉRATURE"
#define POSY_2_V_TEMP_BAT POSY_1_V_TEMP_BAT + HAUT_V    // Position de Y_2 de la bande verte "TEMPÉRATURE"


// -------------- CHARGE -----------------------------------------

#define POSX_NOM_CHAR_BAT 350   // Position en X du nom "CHARGE"
 
#define POSX_BAR_CHAR_BAT 400   // Position en X de la bande "CHARGE"

#define LARGE_BAR_CHAR_BAT POSX_BAR_CHAR_BAT + LARGEUR      // Position en X_2 (la LARGEURE) des bandes "CHARGE"

// SECTION VERT
#define POSY_1_V_CHAR_BAT POSY_BAR              		// Position en Y_1 de la bande verte "CHARGE"
#define POSY_2_V_CHAR_BAT POSY_1_V_CHAR_BAT + HAUT_V    // Position en Y_2 de la bande verte "CHARGE"

// SECTION JAUNE
#define POSY_1_J_CHAR_BAT POSY_2_V_CHAR_BAT             // Position en Y_1 de la bande jaune "CHARGE"
#define POSY_2_J_CHAR_BAT POSY_1_J_CHAR_BAT + HAUT_J    // Position en Y_2 de la bande jaune "CHARGE"

// SECTION ROUGE
#define POSY_1_R_CHAR_BAT POSY_2_J_CHAR_BAT             // Position en Y_1 de la bande rouge "CHARGE"
#define POSY_2_R_CHAR_BAT POSY_1_R_CHAR_BAT + HAUT_R    // Position en Y_2 de la bande rouge "CHARGE"


// --------------- TENSION ---------------------------

#define POSX_NOM_TENS_BAT 600   // Position en X du nom "TENSION"
#define POSY_NOM_TENS_BAT 250   // Position en Y du nom "TENSION"