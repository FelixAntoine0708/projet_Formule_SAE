//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
/*
Programme : TEST_NEW_CODE_CAN.4Dino
Auteur :    Marc-Etienne Gendron-Fontaine
Date :      19 avril 2024
Brief :     Teste d'une nouvelle façon de traiter les trames CAN.

Materielle: ESP32-S3 (x1), Ecran 7" de 4d systeme, TJA1050 (x2)
Encironement: Workshop 4 V4.9.0.9b,
Systeme d'exploitation: Windows 10 V22H2.
*/




#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "TEST_NEW_CODE_CANConst.h"    // Note. This file will not be created if there are no generated graphics


#include <ESP32-TWAI-CAN.hpp>

#define CAN_TX      43     // GPIO 43 comme pin TX
#define CAN_RX      44    // GPIO 44 comme pin RX

CanFrame rxFrame;   // Pour la trame CAN


void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("TEST_NEW_CODE_CAN"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);                // Global touch enabled



     // CAN -----------------------------------
    ESP32Can.setPins(CAN_TX, CAN_RX);   // Initialisation des pin RX et TX

    ESP32Can.setSpeed(ESP32Can.convertSpeed(1000));  // Initialisation de la vitesse de transmission (ICI 1000 Kbits)

    // Initialisation du queue size
    ESP32Can.setRxQueueSize(1);
    ESP32Can.setTxQueueSize(1);


  /*
    Si les driver CAN d?marrent, on affiche "CAN bus started!"
    pendant 2000ms. Sinon, on affiche "CAN bus failed!" puis,
    on entre dans une boucle infini.
  */
  if(ESP32Can.begin())
  {
      gfx.println("CAN bus started!");
      delay(2000);
  }
  else
  {
      gfx.println("CAN bus failed!");
      while(1);
  }

  // Initialise le widget
  gfx.LedDigitsDisplay(0, iiLeddigits1, 3, 3, 72, 0);
  gfx.UserImage(iLeddigits1);


}





void loop()
{
     int total = 0;   // Valeur total
     int entier = 0;  // Valeur pour les enti�s
     int deci = 0;   // Valeur pour les d�cimales



     /*
    Si on recoit une trame CAN, on met a jour le widget.
    Sinon, on affiche "EN ATTENTE DE DONNEES...". Bloque a
    chaque 50 ms.
    */
     if(ESP32Can.readFrame(rxFrame, 50))
     {

        gfx.MoveTo(10,100);                    // Va au coordonnee X et Y 10 et 100
        gfx.print("                         ");  // Print "EN ATTENTE DE DONNEES..."

        // Garde la valeur de l'entier et des decimale
        entier = (rxFrame.data[0] * 100);
        deci =  rxFrame.data[1];

        // Calcul la valeur total
        total = entier + deci;

        // Met a jour le widget
        gfx.LedDigitsDisplay(total, iiLeddigits1, 3, 3, 72, 0);
     }
     else
     {
        gfx.Cls();                              // Efface l'ecran
        gfx.MoveTo(10,100);                    // Va au coordonnee X et Y 10 et 100
        gfx.print("EN ATTENTE DE DONNEES...");  // Print "EN ATTENTE DE DONNEES..."

     }



   // ------------------------ !!!!!!!!! NE PAS TOUCER CETTE SECTION !!!!!!!!!!!! ----------------------------------------------

  // put your main code here, to run repeatedly:
  /*int itouched, val ;
  if(gfx.touch_Update())
  {
    itouched = gfx.imageTouched() ;
    switch (itouched)
    {                                                         // start touched selection **do not alter, remove or duplicate this line**
      // case statements for Knobs and Sliders go here
      default :                                               // end touched selection **do not alter, remove or duplicate this line**
        int button = gfx.ImageTouchedAuto();    // use default for keyboards and buttons
        val = gfx.getImageValue(button);
        switch (button)
        {                                                     // start button selection **do not alter, remove or duplicate this line**
          // case, one for each button or keyboard, default should end up as -1
        }                                                     // end button selection **do not alter, remove or duplicate this line**
    }
  }  */
}

