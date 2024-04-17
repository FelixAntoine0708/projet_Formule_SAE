/*
Programme : CAN_FCT_V3.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      17 avril 2024
Brief :     Ce fichier d'entête contient tous les prototypes de fonctions pour la lecture
            et le décodage des trames CAN.

Matérielle: ESP32-S3R8 (Dans l'écran), TJA1050 (x1)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/







#include <ESP32-TWAI-CAN.hpp>



void read_CAN(CanFrame rxFrame);
void temp_set_3(CanFrame rxFrame);
void drive_temp(CanFrame rxFrame);
void hv_temp(CanFrame rxFrame);
void hv_soc(CanFrame rxFrame);
void hv_soh(CanFrame rxFrame);
void hv_voltage(CanFrame rxFrame);
void lv_soc(CanFrame rxFrame);
void lv_voltage(CanFrame rxFrame);
void lv_temp(CanFrame rxFrame);