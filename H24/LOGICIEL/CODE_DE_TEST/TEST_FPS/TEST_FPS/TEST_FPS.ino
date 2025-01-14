//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
/*
Programme : TEST_FPS.4Dino
Auteur :    Marc-Etienne Gendron-Fontaine, Felix-Antoine Guimont
Date :      15 avril 2024
Brief :     Ceci est le code pour vérifier la fluidité de l'écran. Le widget, Angularmeter, à des valeurs allant
            de 0 à 150. Selon les calculs, si on boucle 150 fois avec un délai de 0.0333333 ms, l'animation
            devrait durer 5 secondes. Le fichier du widget fait environ 60 Mb.

Materielle: ESP32-S3 (x1), Ecran 7" de 4d systeme, TJA1050 (x2)
Encironement: Workshop 4 V4.9.0.9b,
Systeme d'exploitation: Windows 10 V22H2.
*/




#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "TEST_FPSConst.h"    // Note. This file will not be created if there are no generated graphics

void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("TEST_FPS"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);                // Global touch enabled


  //gfx.UserImages(iAngularmeter1, 0) ; // where frame is 0 to 300 (for a displayed 0 to 300)

  gfx.LedDigitsDisplay(0, iiLeddigits1, 4, 3, 41, 0) ;  // Leddigits1



  //gfx.UserImages(iAngularmeter1,0) ;                         // init_Angularmeter1 show initialy, if required
  gfx.UserImage(iLeddigits1);                                // init_Leddigits1 show all digits at 0, only do this once
} // end Setup **do not alter, remove or duplicate this line**

void loop()
{



  for(int i=1; i<130; i++)
   {
      gfx.LedDigitsDisplay(i, iiLeddigits1, 4, 3, 41, 0) ;
     //gfx.UserImages(iAngularmeter1,i);
      //gfx.MoveTo(50,50);
      //gfx.print(i);
     //delay(33);
   }
    delay(2000);
    //gfx.UserImages(iAngularmeter1,20);
    //gfx.UserImages(iAngularmeter1,30);
    //gfx.UserImages(iAngularmeter1,120);
    //gfx.UserImages(iAngularmeter1,123);



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

