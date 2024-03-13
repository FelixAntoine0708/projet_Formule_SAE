//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "AFFICHAGE_SAE_V2Const.h"    // Note. This file will not be created if there are no generated graphics

#include "CONST_AFF.h"
#include "CONST_AFF_BAT.h"
#include "CONST_AFF_MDC.h"


// PROTOTYPE DES FCT
void init_btn();
void clear();
void nom_batterie();
void nom_accumulateur();
void nom_mott();
void donne_batterie();
void donne_mdc();
void Batterie();
void Accumulateur();
void Mott();
void touch_btn();
void hello_1();
void hello_2();





void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(3);  gfx.TextSize(2);
  gfx.Open4dGFX("AFFICHAGE_SAE_V2"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);                // Global touch enabled

  init_btn();
  Accumulateur();


} // end Setup **do not alter, remove or duplicate this line**

void loop()
{


   touch_btn();







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
  }*/
}




void init_btn()
{
  gfx.RectangleFilled(0, 415, 800, 500, YELLOW);

  gfx.Buttonx(BTN_1, X_BTN_BATTERIE, Y_BTN, LONG_BTN_X, HAUT_BTN, WHITE, BATTERIE, 2, BLACK);
  gfx.Buttonx(BTN_2, X_BTN_ACCUMULATEUR, Y_BTN, LONG_BTN_X, HAUT_BTN, WHITE, ACCUMULATEUR, 2, BLACK);
  gfx.Buttonx(BTN_3, X_BTN_MOTEUR_DRIVE_COOLANT, Y_BTN, LONG_BTN_X, HAUT_BTN, WHITE, MOTEUR_DRIVE_COOLANT, 2, BLACK);

}


void clear()
{
   gfx.RectangleFilled(0, 0, 800, 415, BLACK);

}


void nom_batterie()
{
    gfx.MoveTo(POSX_NOM_PAGE, POSY_NOM_PAGE);
    gfx.print(EFFACE);
    gfx.MoveTo(POSX_NOM_PAGE, POSY_NOM_PAGE);
    gfx.print(BATTERIE);
}


void nom_accumulateur()
{
    gfx.MoveTo(POSX_NOM_PAGE, POSY_NOM_PAGE);
    gfx.print(EFFACE);
    gfx.MoveTo(POSX_NOM_PAGE, POSY_NOM_PAGE);
    gfx.print(ACCUMULATEUR);
}



void nom_mott()
{
    gfx.MoveTo(POSX_NOM_PAGE, POSY_NOM_PAGE);
    gfx.print(EFFACE);
    gfx.MoveTo(POSX_NOM_PAGE, POSY_NOM_PAGE);
    gfx.print(MOTEUR_DRIVE_COOLANT);
}


void donne_batterie()
{
   // NOM TEMP�RATURE
   gfx.MoveTo(POSX_NOM_TEMP, POSY_NOM_DON);
   gfx.print(TEMP);
   gfx.print(55);
   gfx.print(" C");

   // BAR TEMP�RATURE
   gfx.RectangleFilled(POSX_BAR_TEMP, POSY_BAR, POSX_BAR_TEMP + LARGEUR, POSY_BAR + HAUT_R, RED);
   gfx.RectangleFilled(POSX_BAR_TEMP, POSY_1_J_TEMP, POSX_BAR_TEMP + LARGEUR, POSY_2_J_TEMP, YELLOW);
   gfx.RectangleFilled(POSX_BAR_TEMP, POSY_1_V_TEMP, POSX_BAR_TEMP + LARGEUR, POSY_2_V_TEMP, GREEN);

   // BAR CHARGE
   gfx.RectangleFilled(POSX_BAR_CHAR, POSY_1_V_CHAR, LARGE_BAR_CHAR, POSY_2_V_CHAR, GREEN);
   gfx.RectangleFilled(POSX_BAR_CHAR, POSY_1_J_CHAR, LARGE_BAR_CHAR, POSY_2_J_CHAR, YELLOW);
   gfx.RectangleFilled(POSX_BAR_CHAR, POSY_1_R_CHAR, LARGE_BAR_CHAR, POSY_2_R_CHAR, RED);

   // NOM CHARGE
   gfx.MoveTo(POSX_NOM_CHAR, POSY_NOM_DON);
   gfx.print(NIV_CHARGE);
   gfx.print(85);
   gfx.print("%");

   // SECTION TENSION
   gfx.MoveTo(POSX_NOM_TENS, POSY_NOM_TENS);
   gfx.print(VOLT);
   gfx.print(12);
   gfx.print("V");
}


void donne_mdc()
{
   // SECTION MOTTEUR
   gfx.MoveTo(POSX_NOM_MOT, POSY_NOM_DON);
   gfx.print(NOM_TEMP_MOT);
   gfx.print(60);
   gfx.print(" C");


   // SECTION DRIVE
   gfx.MoveTo(POSX_NOM_DRIV, POSY_NOM_DON);
   gfx.print(NOM_TEMP_DRIV);
   gfx.print(50);
   gfx.print(" C");


   // SECTION COOLANT
   gfx.MoveTo(POXX_NOM_COOL, POSY_NOM_DON);
   gfx.print(NOM_TEMP_COOL);
   gfx.print(45);
   gfx.print(" C");
}



void Batterie()
{
    clear();
    nom_batterie();
    donne_batterie();
}


void Accumulateur()
{
   clear();
   nom_accumulateur();
}


void Mott()
{
   clear();
   nom_mott();
   donne_mdc();
}


void touch_btn()
{
  int btnXtouch;

  btnXtouch = gfx.CheckButtons();

  if(btnXtouch == BTN_1)
    Batterie();
  else if(btnXtouch == BTN_2)
    Accumulateur();
  else if(btnXtouch == BTN_3)
    Mott();

}



void hello_1()
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print("HELLO_1!!!!!");
}



void hello_2()
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print("HELLO_2!!!!!");
}