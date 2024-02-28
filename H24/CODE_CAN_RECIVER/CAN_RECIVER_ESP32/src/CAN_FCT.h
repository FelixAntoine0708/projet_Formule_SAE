/*
Programme : CAN_FCT.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      12 février 2024
Brief :     Ce fichier d'entête contient toutes les prototype de fonctions qui seront utiles au projet
            (lecture de la trame CAN, vérification de la trame CAN, affichage des informations, etc.)

Matérielle: ESP32-S3 (x2), TJA1050 (x2)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/




void affiche_data(CanFrame rxFrame);
void verif_trame(CanFrame rxFrame);
void coolant_temp(CanFrame rxFrame);
void drive_temp(CanFrame rxFrame);
void motor_temp(CanFrame rxFrame);
void hv_temp(CanFrame rxFrame);
void hv_soc(CanFrame rxFrame);
void hv_soh(CanFrame rxFrame);
void hv_voltage(CanFrame rxFrame);
void lv_soc(CanFrame rxFrame);
void lv_voltage(CanFrame rxFrame);
void lv_temp(CanFrame rxFrame);
void read_CAN(CanFrame rxFrame);
void send_CAN(int id);