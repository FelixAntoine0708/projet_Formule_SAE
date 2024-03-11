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






// ------------- DRIVE ---------------------

#define POSX_NOM_DRIV 300   // Position en X du nom de la donnée "TEMP_DRIV"


#define NOM_TEMP_DRIV "TEMP_DRIVE : "   // Nom de la donnée "TEMPÉRATURE DRIVE"





// ------------- COOLANT -------------------

#define POSX_NOM_COOL 600   // Position en X du nom de la donnée "TEMPÉRATURE COOLANT"


#define NOM_TEMP_COOL "TEMP_COOL : "    // Nom de la donnée "TEMPÉRATURE COOLANT"