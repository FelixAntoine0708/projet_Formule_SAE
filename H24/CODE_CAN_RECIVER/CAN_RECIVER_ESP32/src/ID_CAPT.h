/*
Programme : main.cpp
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      12 février 2024
Brief :     

Matérielle:  
Encironement:
*/



// ID CAPTEUR
#define COOLANT_TEMP  0xA0  // Température du liquide de refroidissement
#define DRIVE_TEMP    0xA1  // Température interne de l’onduleur
#define MOTOR_TEMP    0xA2  // Température interne du moteur
#define HV_TEMP       0xA3  // Température interne de l’accumulateur
#define HV_SOC        0xA4  // Niveau de charge de l’accumulateur
#define HV_SOH        0xA5  // Niveau de santé de l’accumulateur
#define HV_VOLTAGE    0xA6  // Tension totale de l’accumulateur
#define LV_SOC        0xA7  // Niveau de charge de la batterie 12V
#define LV_VOLTAGE    0xA8  // Tension de la batterie 12V
#define LV_TEMP       0xA9  // Température de la batterie 12V