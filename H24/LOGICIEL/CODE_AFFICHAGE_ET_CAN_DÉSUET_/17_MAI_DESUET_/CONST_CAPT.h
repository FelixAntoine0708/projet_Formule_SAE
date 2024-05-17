/*
Programme : CONST_CAPT.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      3 mai 2024
Brief :     Ce fichier d'entête contient toutes les constantes pour la position des capteurs dans le tableau. 

Matérielle: ESP32-S3R8 (Dans l'écran), TJA1050 (x1)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/


#define SIZE_TAB        10  // Grosseur du tableau

#define COOLANT_TEMP    0   // Température du liquide de refroidissement
#define DRIVE_TEMP      1   // Température interne de l’onduleur
#define MOTOR_TEMP      2   // Température interne du moteur
#define HV_TEMP         3   // Température interne de l’accumulateur
#define HV_SOC          4   // Niveau de charge de l’accumulateur
#define HV_SOH          5   // Niveau de santé de l’accumulateur
#define HV_VOLTAGE      6   // Tension totale de l’accumulateur
#define LV_SOC          7   // Niveau de charge de la batterie 12V
#define LV_VOLTAGE      8   // Tension de la batterie 12V
#define LV_TEMP         9   // Température de la batterie 12V