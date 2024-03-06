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





#define X_BTN_BATTERIE 75                   // Distance en X du bouton BATTERIE au bord de l'écran (DANS CE CAS-CI, C’est LE BORD GAUCHE)
#define X_BTN_ACCUMULATEUR 320              // Distance en X du bouton ACCUMULATEUR au bord de l'écran (DANS CE CAS-CI, C’est LE BORD GAUCHE)
#define X_BTN_MOTEUR_DRIVE_COOLANT 565      // Distance en X du bouton MOTEUR_DRIVE_COOLANT au bord de l'écran (DANS CE CAS-CI, C’est LE BORD GAUCHE)
#define Y_BTN 425                           // Distance en Y des boutons à partir du haut de l'écran
#define LONG_BTN_X 150                      // Longueur des boutons
#define HAUT_BTN 50                         // Hauteur des boutons

// ID DES BOUTTONS
#define BTN_1 0     // ID pour le bouton BATTERIE
#define BTN_2 1     // ID pour le bouton ACCUMULATEUR
#define BTN_3 2     // ID pour le bouton MOTEUR_DRIVE_COOLANT
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
