//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "TEST_CAN_AFFConst.h"    // Note. This file will not be created if there are no generated graphics

#include <ESP32-TWAI-CAN.hpp>

#define CAN_TX    43
#define CAN_RX    44


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
    if(ESP32Can.readFrame(rxFrame, 10))
    {
      int mil = ((int)rxFrame.data[4] - 48) * 100;
      int cent = ((int)rxFrame.data[5] - 48) * 100;
      int diz = ((int)rxFrame.data[6] - 48) * 10;
      int uni = (int)rxFrame.data[7] - 48;
      int total = mil + cent + diz + uni;

        gfx.UserImages(iAngularmeter1, total);
        if (total > 9)
           gfx.LedDigitsDisplay(total, iiLeddigits1, 1, 3, 53, 0);
        if (total > 9 && total < 99 )
          gfx.LedDigitsDisplay(total, iiLeddigits1, 2, 3, 53, 0);
        if (total > 99 && total < 999 )
          gfx.LedDigitsDisplay(total, iiLeddigits1, 3, 3, 53, 0);
        if (total > 999 && total < 9999 )
          gfx.LedDigitsDisplay(total, iiLeddigits1, 4, 3, 53, 0);


    }
    else
    {
      gfx.MoveTo(150,150);
      gfx.Cls();
      gfx.MoveTo(250,250);
      gfx.print("EN ATTENTE DE DONN�ES...");
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

