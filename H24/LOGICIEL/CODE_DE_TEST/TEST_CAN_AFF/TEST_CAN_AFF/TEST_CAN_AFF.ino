//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "TEST_CAN_AFFConst.h"    // Note. This file will not be created if there are no generated graphics

#include <ESP32-TWAI-CAN.hpp>


#define CAN_TX    43    // BRUN
#define CAN_RX    44   // ORANGE

// VARIALBLE GLOBALE
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
  gfx.Open4dGFX("TEST_CAN_AFF"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);                // Global touch enabled


  // CAN -----------------------------------

  // Initialisation des GPIO pour recevoir/transmettre des trames CAN.
  ESP32Can.setPins(CAN_TX, CAN_RX);

  // Initialise la vitesse de communication du CAN.
  ESP32Can.setSpeed(ESP32Can.convertSpeed(500));

  // D?mare les driver TWAI
  if(ESP32Can.begin())
      gfx.println("CAN bus started!");
  else
      gfx.println("CAN bus failed!");



} // end Setup **do not alter, remove or duplicate this line**

void loop()
{

    if(ESP32Can.readFrame(rxFrame, 1000))
    {
      gfx.MoveTo(250,250);
      gfx.println("                                      ");
      gfx.MoveTo(150,150);
      gfx.println("DONNÉES REÇUS!!!!!!!!!");
      //gfx.printf("%d \n", rxFrame.data[0]);

    }
    else
    {
      gfx.MoveTo(150,150);
      gfx.println("                                      ");
      gfx.MoveTo(150,150);
      gfx.print("EN ATTENTE DE DONNÉES...");
    }









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
  } */
}

