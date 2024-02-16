/*
Programme : main.cpp
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      12 février 2024
Brief :     Ce programme permet à un ESP32-S3 de recevoir des trames CAN provenant, dans ce cas si, d'un autre ESP32-S3.
            SE PROGRAMME FONCTIONNE SEULEMENT AVEC LE TJA1050!!!!! Donc, le ESP32 lit le port série à chaque seconde.
            Quand il reçoit une trame CAN, il fait passer l’ID dans un Switch/case qui va, ensuite, appeler la bonne fonction d'affichage
            selon le capteur. Une vérification de la trame est faite puis on affiche la partie "data" de la trame.

Matérielle:  
Encironement:
*/




#include <Arduino.h>
#include <ESP32-TWAI-CAN.hpp>

#include "CAN_FCT.h"
#include "ID_CAPT.h"


// GPIO par défaut pour la communication CAN (série)
#define CAN_TX		5
#define CAN_RX		4





CanFrame rxFrame;


/*/ PROTOTYPE DE FONCTION
void affiche_data();
void verif_trame();
void lv_temp();
void lv_voltage();
void lv_soc();
void hv_voltage();
void hv_soh();
void hv_soc();
void hv_temp();
void motor_temp();
void drive_temp();
void coolant_temp();
*/


void setup()
{
  // Setup serial for debbuging.
  Serial.begin(115200);
  delay(5000);

  // Set pins
	ESP32Can.setPins(CAN_TX, CAN_RX);

  // You can set custom size for the queues - those are default
  ESP32Can.setRxQueueSize(5);
	ESP32Can.setTxQueueSize(5);

  // .setSpeed() and .begin() functions require to use TwaiSpeed enum,
  // but you can easily convert it from numerical value using .convertSpeed()
  ESP32Can.setSpeed(ESP32Can.convertSpeed(500));

  // You can also just use .begin()..
    if(ESP32Can.begin())
        Serial.println("CAN bus started!");
    else
        Serial.println("CAN bus failed!");
}

void loop()
{
  read_CAN(rxFrame);
}


