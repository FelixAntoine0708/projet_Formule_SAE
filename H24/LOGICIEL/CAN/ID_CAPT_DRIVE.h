/*
Programme : ID_CAPT_DRIVE.h
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      5 avril 2024
Brief :     Ce fichier d'entête contient tous les ID utilisé par la drive sous forme de constante.

Matérielle: ESP32-S3 (x2), TJA1050 (x2)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/



// ID CAPTEUR POUR LA DRIVE
#define TEMP_SET_1      0xA0
#define TEMP_SET_2      0xA1
#define TEMP_SET_3      0xA2
#define ANG_IN_VOLT     0xA3
#define DIGIT_IN_VOLT   0xA4
#define MOT_POSI_INFO   0xA5
#define CURRENT_INFO    0xA6
#define VOLT_INFO       0xA7
#define FLUX_INFO       0xA8
#define INTERN_VOLT     0xA9
#define INTERN_STATES   0xAA
#define FAULT_CODE      0xAB
#define TORQ_TIME_INFO  0xAC
#define MODU_FLUX_INFO  0xAD
#define FIRMWARE_INFO   0xAD
#define DIAG_DATA       0xAF
#define FAST_INFO       0xB0
#define U2C_CMD_TXD     0xBB
#define U2C_CMD_RXD     0xBC
#define CMD_MSG         0xC0
#define R_W_PARAM_CMD   0xC1
#define R_W_PARAM_RESP  0xC2
#define U2C_MSG_RXD     0x1D5
//#define U2C_CMD_TXD     0x1D7
#define BMS_CUR_LIM     0x202