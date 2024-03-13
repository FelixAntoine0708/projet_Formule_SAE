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
#include "ID_CAPT.h"
#include "CAN_FCT.h"



/*
Brief   : Affiche la Température du liquide de refroidissement.
Param   : rxFrame soit la trame CAN.
Return  : msg soit la Température du liquide de refroidissement.
*/
String coolant_temp(CanFrame rxFrame)
{
  String msg = "Température du liquide de refroidissement : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}

/*
Brief   : Affiche la Température interne de l’onduleur.
Param   : rxFrame soit la trame CAN.
Return  : msg soit la Température interne de l’onduleur.
*/
String drive_temp(CanFrame rxFrame)
{
  String msg = "Température interne de l’onduleur : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}



/*
Brief   : Affiche la Température interne du moteur.
Param   : rxFrame soit la trame CAN.
Return  : msg soit la Température interne du moteur.
*/
String motor_temp(CanFrame rxFrame)
{
  String msg = "Température interne du moteur : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}

/*
Brief   : Affiche la Température interne de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : msg soit la Température interne de l’accumulateur.
*/
String hv_temp(CanFrame rxFrame)
{
  String msg = "Température interne de l’accumulateur : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}

/*
Brief   : Affiche le Niveau de charge de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : msg soit le Niveau de charge de l’accumulateur.
*/
String hv_soc(CanFrame rxFrame)
{
  String msg = "Niveau de charge de l’accumulateur : ";

  msg += String(rxFrame.data[0]);
  
  return msg;
}


/*
Brief   : Affiche le Niveau de santé de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : msg soit le Niveau de santé de l’accumulateur.
*/
String hv_soh(CanFrame rxFrame)
{
  String msg = "Niveau de santé de l’accumulateur : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}

/*
Brief   : Affiche la Tension totale de l’accumulateur.
Param   : rxFrame soit la trame CAN.
Return  : msg soit la Tension totale de l’accumulateur.
*/
String hv_voltage(CanFrame rxFrame)
{
  String msg = "Tension totale de l’accumulateur : ";

  msg += String(rxFrame.data[0]);
  
  return msg;
}

/*
Brief   : Affiche le Niveau de charge de la batterie 12V.
Param   : rxFrame soit la trame CAN.
Return  : msg soit le Niveau de charge de la batterie 12V.
*/
String lv_soc(CanFrame rxFrame)
{
  String msg = "Niveau de charge de la batterie 12V : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}


/*
Brief   : Affiche la Tension de la batterie 12V.
Param   : rxFrame soit la trame CAN.
Return  : msg soit la Tension de la batterie 12V.
*/
String lv_voltage(CanFrame rxFrame)
{
  String msg = "Tension de la batterie 12V : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}

/*
Brief   : Affiche la Température de la batterie 12V.
Param   : rxFrame soit la trame CAN.
Return  : msg soit la Température de la batterie 12V.
*/
String lv_temp(CanFrame rxFrame)
{
  String msg = "Température de la batterie 12V : ";
  
  msg += String(rxFrame.data[0]);
  
  return msg;
}



/*
Brief   : Lis le port série à chaque seconde. Si une trame CAN
          est reçue, on regarde l'ID et on appelle la fonction
          d'affichage correspondante.
Param   : rxFrame soit la trame CAN.
Return  : msg soit le message renvoyer par la bonne fonction.
*/
String read_CAN(CanFrame rxFrame)
{
    String msg = "";    // Pour garder le message retourné par la fct
	
	
	  // Si on reçoit une transmission, on regarde l’ID puis,
    // on affiche le bon message.
    if(ESP32Can.readFrame(rxFrame, 1000))
    {
        
        
      switch (rxFrame.identifier)
      {
        case COOLANT_TEMP:
           msg = coolant_temp(rxFrame);
          break;
        case DRIVE_TEMP:
          msg = drive_temp(rxFrame);
          break;
        case MOTOR_TEMP:
          msg = motor_temp(rxFrame);
          break;
        case HV_TEMP:
          msg = hv_temp(rxFrame);
          break;
        case HV_SOC:
          msg = hv_soc(rxFrame);
          break;
        case HV_SOH:
          msg = hv_soc(rxFrame);
          break;
        case HV_VOLTAGE:
          msg = hv_voltage(rxFrame);
          break;
        case LV_SOC:
          msg = lv_soc(rxFrame);
          break;
        case LV_VOLTAGE:
          msg = lv_voltage(rxFrame);
          break;
        case LV_TEMP:
          msg = lv_temp(rxFrame);
          break;
        default:
          break;
      }
      
		return msg;
    }
}


/*
Brief   : Envoie des trames CAN selon l’ID envoyée en paramètre.
Param   : id soit l'ID du capteur
Return  : Rien
*/
void send_CAN(int id)
{
  CanFrame txTrame;   // Création de la trame CAN qui servira pour la transmission.

  txTrame.identifier = id;
  txTrame.extd = 0;
  txTrame.data_length_code = 8;
  
  for(int i=0; i<8; i++)
    txTrame.data[i] = i+1;
  
  //txTrame.data[0] = 'C';

  ESP32Can.writeFrame(txTrame, 1000);   // Envoie de la trame à chaque seconde (par défaut).
}