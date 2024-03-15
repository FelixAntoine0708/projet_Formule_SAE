/*
Programme : CONST_AFF.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      5 mars 2024
Brief :     Ce fichier contient les constantes qui pourraient être utilisées pour les fonctions
            d'affichage. Il y a des constantes temporaires pour le débug.

Matérielle: ESP32-S3R8 (dans l'écran), écran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7,
Système d'exploitation : Windows 10 V22H2.
*/


#include "CONST_AFF.h"


// ----------- PAGE ACCUMULATEUR ----------------------------

#define POSY_NOM_DON_ACC 125    // Position en Y des nom des données



// ------------ TEMPÉRATURE ----------------------------------------


#define POSX_NOM_TEMP_ACC 50

#define POSX_BAR_TEMP_ACC 100

#define LARG_BAR_TEMP_ACC POSX_BAR_TEMP_ACC + LARGEUR


#define POSY_1_R_TEMP_ACC POSY_BAR
#define POSY_2_R_TEMP_ACC POSY_1_R_TEMP_ACC + HAUT_R

#define POSY_1_J_TEMP_ACC POSY_2_R_TEMP_ACC
#define POSY_2_J_TEMP_ACC POSY_1_J_TEMP_ACC + HAUT_J

#define POSY_1_V_TEMP_ACC POSY_2_J_TEMP_ACC
#define POSY_2_V_TEMP_ACC POSY_1_V_TEMP_ACC + HAUT_V


// --------------- CHARGE --------------------------------

#define POSX_NOM_CHAR_ACC 350   // Position en X du nom "CHARGE"
 
#define POSX_BAR_CHAR_ACC 400   // Position en X de la bande "CHARGE"


#define LARGE_BAR_CHAR_ACC POSX_BAR_CHAR + LARGEUR      // Position en X_2 (la LARGEURE) des bandes "CHARGE"



// SECTION VERT
#define POSY_1_V_CHAR_ACC POSY_BAR              		// Position en Y_1 de la bande verte "CHARGE"
#define POSY_2_V_CHAR_ACC POSY_1_V_CHAR_ACC + HAUT_V    // Position en Y_2 de la bande verte "CHARGE"

// SECTION JAUNE
#define POSY_1_J_CHAR_ACC POSY_2_V_CHAR_ACC             // Position en Y_1 de la bande jaune "CHARGE"
#define POSY_2_J_CHAR_ACC POSY_1_J_CHAR_ACC + HAUT_J    // Position en Y_2 de la bande jaune "CHARGE"

// SECTION ROUGE
#define POSY_1_R_CHAR_ACC POSY_2_J_CHAR_ACC             // Position en Y_1 de la bande rouge "CHARGE"
#define POSY_2_R_CHAR_ACC POSY_1_R_CHAR_ACC + HAUT_R    // Position en Y_2 de la bande rouge "CHARGE"


// --------------- SANTE ---------------------------

#define POSX_NOM_SANTE_ACC 600
#define POSY_NOM_SANTE_ACC 150



// --------------- TENSION ---------------------------

#define POSX_NOM_TENS_ACC 600
#define POSY_NOM_TENS_ACC 250