/*
Programme : CONST_AFF_MDC.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      5 mars 2024
Brief :     Ce fichier contiens toutes les constantes pour la page MOTEUR_DRIVE_COOLANT

Matérielle: ESP32-S3R8 (dans l'écran), écran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7,
Système d'exploitation : Windows 10 V22H2.
*/


#include "CONST_AFF.h"


#define POSY_NOM_DON_MDC 125    // Position en Y des noms des données



// ------------ MOTEUR -------------

#define POSX_NOM_MOT 25     // Position en X du nom de la donnée "TEMP_MOTT"


#define NOM_TEMP_MOT "TEMP_MOTT : "     // Nom de la donnée "TEMPÉRATURE MOTTEUR"

#define POSX_TEMP_MOT 100				// Position en X de la bande "TEMP_MOTT"

#define LARG_BAR_MOT POSX_TEMP_MOT + LARGEUR	// Position en X_2 (la LARGEURE) des bandes "TEMP_MOTT"

// SECTION ROUGE
#define POSY_1_R_MOT POSY_BAR					// Position en Y_1 de la bande rouge "TEMP_MOTT"
#define POSY_2_R_MOT POSY_1_R_MOT + HAUT_R		// Position en Y_2 de la bande rouge "TEMP_MOTT"

//SECTION JAUNE
#define POSY_1_J_MOT POSY_2_R_MOT				// Position de Y_1 de la bande jaune "TEMP_MOTT"
#define POSY_2_J_MOT POSY_1_J_MOT + HAUT_J		// Position de Y_2 de la bande jaune "TEMP_MOTT"

// SECTION VERT
#define POSY_1_V_MOT POSY_2_J_MOT				// Position de Y_1 de la bande verte "TEMP_MOTT"
#define POSY_2_V_MOT POSY_1_V_MOT + HAUT_V		// Position de Y_2 de la bande verte "TEMP_MOTT"


// ------------- DRIVE ---------------------

#define POSX_NOM_DRIV 300   // Position en X du nom de la donnée "TEMP_DRIV"


#define NOM_TEMP_DRIV "TEMP_DRIVE : "   // Nom de la donnée "TEMPÉRATURE DRIVE"

#define POSX_TEMP_DRIV 375		// Position en X de la bande "TEMP_DRIV"

#define LARG_BAR_DRIV POSX_TEMP_DRIV + LARGEUR	// Position en X_2 (la LARGEURE) des bandes "TEMP_DRIV"

// SECTION ROUGE
#define POSY_1_R_DRIV POSY_BAR					// Position en Y_1 de la bande rouge "TEMP_DRIV"
#define POSY_2_R_DRIV POSY_1_R_DRIV + HAUT_R	// Position en Y_2 de la bande rouge "TEMP_DRIV"

//SECTION JAUNE
#define POSY_1_J_DRIV POSY_2_R_DRIV				// Position de Y_1 de la bande jaune "TEMP_DRIV"
#define POSY_2_J_DRIV POSY_1_J_DRIV + HAUT_J	// Position de Y_2 de la bande jaune "TEMP_DRIV"

// SECTION VERT
#define POSY_1_V_DRIV POSY_2_J_DRIV				// Position de Y_1 de la bande verte "TEMP_DRIV"
#define POSY_2_V_DRIV POSY_1_V_DRIV + HAUT_V	// Position de Y_2 de la bande verte "TEMP_DRIV"

// ------------- COOLANT -------------------

#define POSX_NOM_COOL 600   // Position en X du nom de la donnée "TEMPÉRATURE COOLANT"


#define NOM_TEMP_COOL "TEMP_COOL : "    // Nom de la donnée "TEMPÉRATURE COOLANT"

#define POSX_TEMP_COOL 675		// Position en X de la bande "TEMP_COOL"

#define LARG_BAR_COOL POSX_TEMP_COOL + LARGEUR	// Position en X_2 (la LARGEURE) des bandes "TEMP_COOL"

// SECTION ROUGE
#define POSY_1_R_COOL POSY_BAR					// Position en Y_1 de la bande rouge "TEMP_COOL"
#define POSY_2_R_COOL POSY_1_R_COOL + HAUT_R	// Position en Y_2 de la bande rouge "TEMP_COOL"

//SECTION JAUNE
#define POSY_1_J_COOL POSY_2_R_COOL				// Position de Y_1 de la bande jaune "TEMP_COOL"
#define POSY_2_J_COOL POSY_1_J_COOL + HAUT_J	// Position de Y_2 de la bande jaune "TEMP_COOL"

// SECTION VERT
#define POSY_1_V_COOL POSY_2_J_COOL				// Position de Y_1 de la bande verte "TEMP_COOL"
#define POSY_2_V_COOL POSY_1_V_COOL + HAUT_V	// Position de Y_1 de la bande verte "TEMP_COOL"
