/*
Programme : ID_CAPT_CASCADIA.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      5 avril 2024
Brief :     Ce fichier d'entête contient l'ID utilisé par le protocole CAN de Cascadia sous la forme d'une constante.

Matérielle: ESP32-S3 (x2), TJA1050 (x2)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/



// ID CAPTEUR
#define TEMP_SET_3  0xA2

// byte 0 et 1 -> Coolant Temperature

// byte 4 et 5 -> Motor Temperature