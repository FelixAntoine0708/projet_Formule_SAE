/*
Programme : CAN_FCT_MODIFF.cpp
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      13 mars 2024
Brief :     Ce fichier contient toutes les fonctions modifiées qui seront utiles au projet
            (lecture de la trame CAN, vérification de la trame CAN, affichage des informations, etc.)
            Les fonctions ont été modifiées pour les adapter à l'affichage utilisé. "verif_trame"
            et "affiche_data" ne sont pas utilisés pour l'instant.

Matérielle: ESP32-S3 (x2), TJA1050 (x2)
Encironement: Visual Studio Code V 1.86.2,
Système d’exploitation : Linux x64 5.15.0-94-generic.
*/




#include <ESP32-TWAI-CAN.hpp>
#include "CAN_FCT_DRIVE.h"
#include "ID_CAPT_DRIVE.h"

CanFrame rxFrame

void read_can()
{
    int coolant_temp = 0;
    int motor_temp = 0;

    coolant_temp = rxFrame.data[0] + rxFrame.data[1]<<8;

    motor_temp = rxFrame.data[4] + rxFrame.data[5]<<8;

}
