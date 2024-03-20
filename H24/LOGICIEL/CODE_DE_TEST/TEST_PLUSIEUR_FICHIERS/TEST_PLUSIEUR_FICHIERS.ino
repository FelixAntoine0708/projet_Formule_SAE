//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
/*
Programme : TEST_PLUSIEUR_FICHIERS.4Dino
Auteur :    Marc-�tienne Gendron-Fontaine
Date :      5 mars 2024
Brief :     Ce programme teste la possibilité de séparer les fonctions utiles pour l'affichage
            (par exemple, le message de débogage hello_1 qui print sur l'écran HELLO_1!!!!!).

Mat�rielle: ESP32-S3R8 (dans l'�cran), écran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7,
Syst�me d�exploitation�: Windows 10 V22H2.
*/




#include "gfx4desp32_gen4_ESP32_70CT.h"
//#include "gfx4desp32_gen4_ESP32_70CT.h"

//gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();
gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();


#include "TEST_PLUSIEUR_FICHIERSConst.h"    // Note. This file will not be created if there are no generated graphics

#include "CONST_AFF.h"
#include "FCT_AFF.h"



void imp();



void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("TEST_PLUSIEUR_FICHIERS"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);                // Global touch enabled



  imp();

  //hello_2(gfx);

  //while(1);

} // end Setup **do not alter, remove or duplicate this line**




void loop()
{



  //hello_1(gfx);
  delay(1000);
  imp();
  delay(1000);
  gfx.print("!!!!!!!!!!!!!!!!!!!!!!!!!");
  //delay(1000);




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



void imp()
{
  gfx.MoveTo(150, 150);       // Met le curseur aux positions (X,Y) 150, 150
  gfx.print(EFFACE);          // Efface la ligne
  gfx.MoveTo(150, 150);       // Met le curseur aux positions (X,Y) 150, 150
  gfx.print("IMP_TEST!!!!!");  // �cris le message
}
