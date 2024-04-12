//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "TEST_CAN_AFFConst.h"    // Note. This file will not be created if there are no generated graphics

#include <ESP32-TWAI-CAN.hpp>


<<<<<<< Updated upstream
#define CAN_TX    43
#define CAN_RX    44
=======
#define CAN_TX    2    // BRUN
#define CAN_RX    4   // ORANGE
>>>>>>> Stashed changes

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
  ESP32Can.setPins(CAN_TX, CAN_RX);
  ESP32Can.setSpeed(ESP32Can.convertSpeed(500));
  ESP32Can.setRxQueueSize(1);
  ESP32Can.setTxQueueSize(1);
  if(ESP32Can.begin())
      gfx.println("CAN bus started!");
  else
      gfx.println("CAN bus failed!");
  delay(2000);
  gfx.UserImages(iAngularmeter1,0);
  gfx.UserImage(iLeddigits1);
  gfx.UserImages(iAngularmeter1,0) ;                         // init_Angularmeter1 show initialy, if required
} // end Setup **do not alter, remove or duplicate this line**

void loop()
{
    if(ESP32Can.readFrame(rxFrame, 1000))
    {
      for (int i=0; i<8; i++){
        gfx.UserImages(iAngularmeter1, (int)rxFrame.data[i]);
        if ((int)rxFrame.data[i] < 9)
           gfx.LedDigitsDisplay((int)rxFrame.data[i], iiLeddigits1, 1, 3, 53, 0);
        if ((int)rxFrame.data[i] > 9 && (int)rxFrame.data[i] < 99 )
          gfx.LedDigitsDisplay((int)rxFrame.data[i], iiLeddigits1, 2, 3, 53, 0);
          if ((int)rxFrame.data[i] > 99 && (int)rxFrame.data[i] < 999 )
          gfx.LedDigitsDisplay((int)rxFrame.data[i], iiLeddigits1, 3, 3, 53, 0);
          if ((int)rxFrame.data[i] > 999 && (int)rxFrame.data[i] < 9999 )
          gfx.LedDigitsDisplay((int)rxFrame.data[i], iiLeddigits1, 4, 3, 53, 0);
        delay(1500);
        if(i == 7)
          gfx.Cls();
      }
    }
    else
    {
      gfx.MoveTo(150,150);
      gfx.Cls();
      gfx.MoveTo(250,250);
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

