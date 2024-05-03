/*
Programme : CAN_FCT_FINAL.cpp
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      3 mai 2024
Brief :     Ce fichier contient une partie du code de l'affichage : la fonction responsable de la réception
            et du traitement des trames CAN.

Matérielle: ESP32-S3R8 (Dans l'écran), TJA1050 (x1)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/


#include <ESP32-TWAI-CAN.hpp>
#include "ID_CAPT.h"
#include "CONST_CAPT.h"

CanFrame rxFrame;   // Pour garder la trame CAN

// Tableau pour contenire les valeurs des widgets
int tab_val[SIZE_TAB] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};




/*
Brief   : Lis le port série CAN. Si une trame CAN
          est reçue, on traite la trame. On regarde,
          ensuite l'ID et on met la valeure dans la
          bonne case du tableau.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void read_CAN()
{

    int entier = 0; // Pour la partie des entier
    int deci = 0;   // Pour la partie des décimal
    int total = 0;  // Pour le total

    


    // Si on reçoit une transmission, on regarde l’ID puis,
    // et on met la valeur dans la bonne case du tableau.
    if(ESP32Can.readFrame(rxFrame, 0))
    {
        entier = (rxFrame.data[0] * 100);
        deci =  rxFrame.data[1];
        total = entier + deci;
        
        
        if(rxFrame.identifier == COOLANT_TEMP)
            tab_val[COOLANT_TEMP] = total;
        else if(rxFrame.identifier == DRIVE_TEMP)
            tab_val[DRIVE_TEMP] = total;
        else if(rxFrame.identifier == MOTOR_TEMP)
            tab_val[MOTOR_TEMP] = total;
        else if(rxFrame.identifier == HV_TEMP)
            tab_val[HV_TEMP] = total;
        else if(rxFrame.identifier == HV_SOC)
            tab_val[HV_SOC] = total;
        else if(rxFrame.identifier == HV_SOH)
            tab_val[HV_SOH] = total;
        else if(rxFrame.identifier == HV_VOLTAGE)
            tab_val[HV_VOLTAGE] = total;
        else if(rxFrame.identifier == LV_SOC)
            tab_val[LV_SOC] = total;
        else if(rxFrame.identifier == LV_VOLTAGE)
            tab_val[LV_VOLTAGE] = total;
        else if(rxFrame.identifier == LV_TEMP)
            tab_val[LV_TEMP] = total;

    }
}
