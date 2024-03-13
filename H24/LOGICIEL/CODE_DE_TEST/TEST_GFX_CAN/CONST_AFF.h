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




// CONSTANTES DES BOUTONS
#define X_BTN_BATTERIE 35                   // Distance en X du bouton BATTERIE au bord de l'écran (DANS CE CAS-CI, c’est LE BORD GAUCHE)
#define X_BTN_ACCUMULATEUR 300              // Distance en X du bouton ACCUMULATEUR au bord de l'écran (DANS CE CAS-CI, c’est LE BORD GAUCHE)
#define X_BTN_MOTEUR_DRIVE_COOLANT 565      // Distance en X du bouton MOTEUR_DRIVE_COOLANT au bord de l'écran (DANS CE CAS-CI, c’est LE BORD GAUCHE)
#define Y_BTN 425                           // Distance en Y des boutons à partir du haut de l'écran
#define LONG_BTN_X 200                      // Longueur des boutons
#define HAUT_BTN 50                         // Hauteur des boutons

// ID DES BOUTONS
#define BTN_1 0     // ID pour le bouton BATTERIE
#define BTN_2 1     // ID pour le bouton ACCUMULATEUR
#define BTN_3 2     // ID pour le bouton MOTEUR_DRIVE_COOLANT

// ID BOUTONS EN RÉSERVE
#define BTN_4 3
#define BTN_5 4
#define BTN_6 5
#define BTN_7 6
#define BTN_8 7
#define BTN_9 8


// CONSTANTES TEMPORAIRES SERVANT AU DÉBUG
#define BATTERIE "BATTERIE"
#define ACCUMULATEUR "ACCUMULATEUR"
#define MOTEUR_DRIVE_COOLANT "MOTEUR_DRIVE_COOLANT"
#define EFFACE "                          "

#define POSX_NOM_PAGE 325
#define POSY_NOM_PAGE 0


// NOM DES MESURES
#define TEMP "TEMPÉRATURE : "
#define NIV_CHARGE "CHARGE : "
#define VOLT "TENSION : "
#define SANTE "SANTÉE : "


// CONSTANTES DES BANDES
#define LARGEUR 50
#define HAUT_V 75
#define HAUT_J 75
#define HAUT_R 75


