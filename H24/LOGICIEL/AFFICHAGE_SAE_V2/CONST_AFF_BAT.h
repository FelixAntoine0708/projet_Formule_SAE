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



// ---------------------------PAGE BATTERIE-----------------------------

#define POSY_NOM_DON 125
#define POSY_BAR 150


// ------------ TEMPÉRATURE ----------------------------------------

#define POSX_NOM_TEMP 50
//#define POSY_NOM_TEMP 125


#define POSX_BAR_TEMP 100
//#define POSY_BAR_TEMP 150

#define POSY_1_J_TEMP POSY_BAR + HAUT_R
#define POSY_2_J_TEMP POSY_BAR + HAUT_R + HAUT_J
#define POSY_1_V_TEMP POSY_BAR + HAUT_R + HAUT_J
#define POSY_2_V_TEMP POSY_BAR + HAUT_R + HAUT_J + HAUT_V


// -------------- CHARGE -----------------------------------------

#define POSX_NOM_CHAR 350
 
#define POSX_BAR_CHAR 400

#define LARGE_BAR_CHAR POSX_BAR_CHAR + LARGEUR

// SECTION VERT
#define POSY_1_V_CHAR POSY_BAR
#define POSY_2_V_CHAR POSY_BAR + HAUT_V

// SECTION JAUNE
#define POSY_1_J_CHAR POSY_2_V_CHAR
#define POSY_2_J_CHAR POSY_1_J_CHAR + HAUT_J

// SECTION ROUGE
#define POSY_1_R_CHAR POSY_2_J_CHAR
#define POSY_2_R_CHAR POSY_1_R_CHAR + HAUT_R


// --------------- TENSION ---------------------------

#define POSX_NOM_TENS 600
#define POSY_NOM_TENS 250