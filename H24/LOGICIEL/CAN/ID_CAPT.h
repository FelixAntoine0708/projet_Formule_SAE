/*
Programme : ID_CAPT.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      17 avril 2024
Brief :     Ce fichier d'entête contient toutes les constantes pour les capteurs. SEUL TEMP_SET_3,
            qui provient de la drive, est sur. Les autre sont à la discrétion de l'université.

Matérielle: ESP32-S3R8 (Dans l'écran), TJA1050 (x1)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/







// ID CAPTEUR
#define TEMP_SET_3  0xA2    // ID des donnée de la drive

// byte 0 et 1 -> Coolant Temperature

// byte 4 et 5 -> Motor Temperature


#define DRIVE_TEMP      0x1A0   // Température interne de l’onduleur
#define HV_TEMP         0x1A1   // Température interne de l’accumulateur
#define HV_SOC          0x1A2   // Niveau de charge de l’accumulateur
#define HV_SOH          0x1A3   // Niveau de santé de l’accumulateur
#define HV_VOLTAGE      0x1A4   // Tension totale de l’accumulateur
#define LV_SOC          0x1A5   // Niveau de charge de la batterie 12V
#define LV_VOLTAGE      0x1A6   // Tension de la batterie 12V
#define LV_TEMP         0x1A7   // Température de la batterie 12V