/*
Programme : CAN_FCT_V3.cpp
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      17 avril 2024
Brief :     Ce fichier contient toutes les fonctions qui seront utiles au projet AVEC LES INFORMATIONS REÇUES DE L'UNIVERSITÉ.
            (lecture de la trame CAN et décodage de celle-ci)

Matérielle: ESP32-S3R8 (Dans l'écran), TJA1050 (x1)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/





#include <ESP32-TWAI-CAN.hpp>
#include "ID_CAPT.h"
#include "CAN_FCT_V3.h"




/*
Brief   : Lis le port série CAN. Si une trame CAN
          est reçue, on regarde l'ID et on appelle la fonction
          de décodage correspondante.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void read_CAN(CanFrame rxFrame)
{

    // Si on reçoit une transmission, on regarde l’ID puis,
    // on décode la trame.
    if(ESP32Can.readFrame(rxFrame, 0))
    {
        if(rxFrame.identifier == TEMP_SET_3)
            temp_set_3(rxFrame);
        else if(rxFrame.identifier == DRIVE_TEMP)
            drive_temp(rxFrame);
        else if(rxFrame.identifier == HV_TEMP)
            hv_temp(rxFrame);
        else if(rxFrame.identifier == HV_SOC)
            hv_soc(rxFrame);
        else if(rxFrame.identifier == HV_SOH)
            hv_soh(rxFrame);
        else if(rxFrame.identifier == HV_VOLTAGE)
            hv_voltage(rxFrame);
        else if(rxFrame.identifier == LV_SOC)
            lv_soc(rxFrame);
        else if(rxFrame.identifier == LV_VOLTAGE)
            lv_voltage(rxFrame);
        else if(rxFrame.identifier == LV_TEMP)
            lv_temp(rxFrame);

    }
}


/*
Brief   : Décode la trame CAN pour avoir la température
          du moteur et du coolant
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void temp_set_3(CanFrame rxFrame)
{
    int coolant_temp = 0;
    int motor_temp = 0;

    coolant_temp = rxFrame.data[0] + rxFrame.data[1]<<8;

    motor_temp = rxFrame.data[4] + rxFrame.data[5]<<8;
}


/*
Brief   : Décode la trame CAN pour avoir la température de la drive.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void drive_temp(CanFrame rxFrame)
{

}


/*
Brief   : Décode la trame CAN pour avoir la température du hv_temp.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_temp(CanFrame rxFrame)
{

}



/*
Brief   : Décode la trame CAN pour avoir le hv_soc.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_soc(CanFrame rxFrame)
{

}



/*
Brief   : Décode la trame CAN pour avoir le hv_soh.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_soh(CanFrame rxFrame)
{

}



/*
Brief   : Décode la trame CAN pour avoir le hv_voltage.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hv_voltage(CanFrame rxFrame)
{

}



/*
Brief   : Décode la trame CAN pour avoir le lv_soc.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void lv_soc(CanFrame rxFrame)
{

}



/*
Brief   : Décode la trame CAN pour avoir le lv_voltage.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void lv_voltage(CanFrame rxFrame)
{

}




/*
Brief   : Décode la trame CAN pour avoir la température du lv_temp.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void lv_temp(CanFrame rxFrame)
{

}