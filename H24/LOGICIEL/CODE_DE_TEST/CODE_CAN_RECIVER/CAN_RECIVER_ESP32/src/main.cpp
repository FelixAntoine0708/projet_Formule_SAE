/*
Programme : main.cpp
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      12 février 2024
Brief :     Ce programme permet à un ESP32-S3 de recevoir des trames CAN provenant, dans ce cas si, d'un autre ESP32-S3.
            SE PROGRAMME FONCTIONNE SEULEMENT AVEC LE TJA1050!!!!! Donc, le ESP32 lit le port série à chaque seconde.
            Quand il reçoit une trame CAN, il fait passer l’ID dans un Switch/case qui va, ensuite, appeler la bonne fonction d'affichage
            selon le capteur. Une vérification de la trame est faite puis on affiche la partie "data" de la trame.

Matérielle: ESP32-S3 (x2), TJA1050 (x2)
Encironement: Visual Studio Code V 1.86.2, Système d’exploitation : Linux x64 5.15.0-94-generic.
*/




#include <Arduino.h>
#include <ESP32-TWAI-CAN.hpp>

#include "CAN_FCT.h"
#include "ID_CAPT.h"


// GPIO par défaut pour la communication CAN (série)
#define CAN_TX		12
#define CAN_RX		13

CanFrame rxFrame;

void setup()
{
  // Initialisation de la vitesse du moniteur série
  Serial.begin(115200);
  delay(2000);

  // Initialisation des GPIO pour recevoir/transmettre des trames CAN.
	ESP32Can.setPins(CAN_TX, CAN_RX);


//----------------------------------------------------------------------
  // You can set custom size for the queues - those are default
  //ESP32Can.setRxQueueSize(5);
	//ESP32Can.setTxQueueSize(5);
//------------------------------------------------------------------------

  // Initialise la vitesse de communication du CAN.
  // .setSpeed() ne prend que des enum de type TwaiSpeed.
  // Bref, on met la vitesse convertie dans le .setSpeed.
  ESP32Can.setSpeed(ESP32Can.convertSpeed(500));

  // Démare les driver TWAI
    if(ESP32Can.begin())
        Serial.println("CAN bus started!");
    else
        Serial.println("CAN bus failed!");
}

void loop()
{
  //read_CAN(rxFrame);

  delay(1000);
  send_CAN(COOLANT_TEMP);
  delay(1000);
  send_CAN(DRIVE_TEMP);
}
