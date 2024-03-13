/*
Programme : CONST_AFF_MDC.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      5 mars 2024
Brief :     Ce fichier contiens toutes les constantes pour la page "MOTEUR_DRIVE_COOLANT"

Matérielle: ESP32-S3R8 (dans l'écran), écran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7,
Système d'exploitation : Windows 10 V22H2.
*/


#include "CONST_AFF.h"


#define POSY_NOM_DON 125    // Position en Y des noms des données
#define POSY_BAR 150        // Position en Y des bandes


// ------------ MOTEUR -------------

#define POSX_NOM_MOT 25     // Position en X du nom de la donnée "TEMP_MOTT"


#define NOM_TEMP_MOT "TEMP_MOTT : "     // Nom de la donnée "TEMPÉRATURE MOTTEUR"

#define POSX_TEMP_MOT 100
#define LARG_BAR_MOT POSX_TEMP_MOT + LARGEUR

#define POSY_1_R_MOT POSY_BAR
#define POSY_2_R_MOT POSY_1_R_MOT + HAUT_R
#define POSY_1_J_MOT POSY_2_R_MOT
#define POSY_2_J_MOT POSY_1_J_MOT + HAUT_J
#define POSY_1_V_MOT POSY_2_J_MOT
#define POSY_2_V_MOT POSY_1_V_MOT + HAUT_V


// ------------- DRIVE ---------------------

#define POSX_NOM_DRIV 300   // Position en X du nom de la donnée "TEMP_DRIV"


#define NOM_TEMP_DRIV "TEMP_DRIVE : "   // Nom de la donnée "TEMPÉRATURE DRIVE"

#define POSX_TEMP_DRIV 375
#define LARG_BAR_DRIV POSX_TEMP_DRIV + LARGEUR

#define POSY_1_R_DRIV POSY_BAR
#define POSY_2_R_DRIV POSY_1_R_DRIV + HAUT_R
#define POSY_1_J_DRIV POSY_2_R_DRIV
#define POSY_2_J_DRIV POSY_1_J_DRIV + HAUT_J
#define POSY_1_V_DRIV POSY_2_J_DRIV
#define POSY_2_V_DRIV POSY_1_V_DRIV + HAUT_V

// ------------- COOLANT -------------------

#define POSX_NOM_COOL 600   // Position en X du nom de la donnée "TEMPÉRATURE COOLANT"


#define NOM_TEMP_COOL "TEMP_COOL : "    // Nom de la donnée "TEMPÉRATURE COOLANT"

#define POSX_TEMP_COOL 675
#define LARG_BAR_COOL POSX_TEMP_COOL + LARGEUR

#define POSY_1_R_COOL POSY_BAR
#define POSY_2_R_COOL POSY_1_R_COOL + HAUT_R
#define POSY_1_J_COOL POSY_2_R_COOL
#define POSY_2_J_COOL POSY_1_J_COOL + HAUT_J
#define POSY_1_V_COOL POSY_2_J_COOL
#define POSY_2_V_COOL POSY_1_V_COOL + HAUT_V
