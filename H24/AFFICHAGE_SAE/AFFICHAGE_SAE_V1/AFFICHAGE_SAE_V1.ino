//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
//#include "gfx4desp32_gen4_ESP32_70CT.h" //"gfx4desp32_gen4_ESP32_50CT.h"
  #include "gfx4desp32_gen4_ESP32_50CT.h"
gfx4desp32_gen4_ESP32_50CT gfx = gfx4desp32_gen4_ESP32_50CT();

#include "AFFICHAGE_SAE_V1Const.h"    // Note. This file will not be created if there are no generated graphics


#define X_BTN_BATTERIE 75
#define X_BTN_ACCUMULATEUR 320
#define X_BTN_MOTEUR_DRIVE_COOLANT 565
#define Y_BTN 425

void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("AFFICHAGE_SAE_V1"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);// Global touch enabled

  // FORM 1    BATTERIE_PAGE

  gfx.Button(1, 75, 425, RED, YELLOW, FONT1, 3, 1, "BATTERIE") ; // ?%Name?<(BATTERIE_F1) Width=69 Height=33
  gfx.Button(1, 320, 425, RED, YELLOW, FONT1, 3, 1, "ACCUMULATEUR") ; // ?%Name?<(ACCUMULATEUR_F1) Width=97 Height=33
  gfx.Button(1, 565, 425, RED, YELLOW, FONT1, 3, 1, "MOTEUR_DRIVE_COOLANT") ; // ?%Name?<(MOTEUR_DRIVE_COOLANT_F1) Width=153 Height=33
  gfx.UserImage(iStatictext1) ;  // PAGE_NAME_BATTERIE
  gfx.UserImage(iStatictext3) ;  // LBL_TEMP_BATTERIE
  gfx.UserImage(iStatictext4) ;  // LBL_NIVEAU_CHARGE
  gfx.UserImage(iStatictext2) ;  // LBL_TENSION_BATTERIE
  gfx.UserImages(iThermometer1, 35) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iGauge1, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.LedDigitsDisplay(numx, iiLeddigits1, 4, 3, 39, 0) ;  // TENSION_BATTERIE


  // FORM 2    ACCUMULATEUR_PAGE

  gfx.Button(1, 75, 425, RED, YELLOW, FONT1, 3, 1, "BATTERIE") ; // ?%Name?<(BATTERIE_F2) Width=69 Height=33
  gfx.Button(1, 320, 425, RED, YELLOW, FONT1, 3, 1, "ACCUMULATEUR") ; // ?%Name?<(ACCUMULATEUR_F2) Width=97 Height=33
  gfx.Button(1, 565, 425, RED, YELLOW, FONT1, 3, 1, "MOTEUR_DRIVE_COOLANT") ; // ?%Name?<(MOTEUR_DRIVE_COOLANT_F2) Width=153 Height=33
  gfx.UserImage(iStatictext5) ;  // LBL_ACCUMULATEUR
  gfx.UserImage(iStatictext9) ;  // LBL_TEMP_ACCUMULATEUR
  gfx.UserImage(iStatictext6) ;  // LBL_CHARGE_ACCUMULATEUR
  gfx.UserImage(iStatictext7) ;  // LBL_SANTE_ACCUMULATEUR
  gfx.UserImage(iStatictext8) ;  // LBL_RENSION_ACCUMULATEUR
  gfx.UserImages(iThermometer2, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iGauge2, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.UserImages(iAngularmeter1, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.LedDigitsDisplay(numx, iiLeddigits2, 4, 3, 46, 0) ;  // Leddigits2







  // FORM 3     MOTEUR_DRIVE_COOLANT_PAGE

  gfx.Button(1, 75, 425, RED, YELLOW, FONT1, 3, 1, "BATTERIE") ; // ?%Name?<(BATTERIE_F3) Width=69 Height=33
  gfx.Button(1, 320, 425, RED, YELLOW, FONT1, 3, 1, "ACCUMULATEUR") ; // ?%Name?<(ACCUMULATEUR_F3) Width=97 Height=33
  gfx.Button(1, 565, 425, RED, YELLOW, FONT1, 3, 1, "MOTEUR_DRIVE_COOLANT") ; // ?%Name?<(MOTEUR_DRIVE_COOLANT_F3) Width=153 Height=33
  gfx.UserImage(iStatictext10) ;  // LBL_MOTEUR_DRIVE_COOLANT
  gfx.UserImage(iStatictext11) ;  // LBL_TEMP_MOTEUR
  gfx.UserImage(iStatictext12) ;  // LBL_TEMP_DRIVE
  gfx.UserImage(iStatictext13) ;  // LBL_TEMP_COOLANT
  gfx.UserImages(iThermometer3, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iThermometer4, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iThermometer5, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)




  // FORM 1    BATTERIE
  gfx.UserImages(iThermometer1,0) ;                          // init_Thermometer1(TEMP_BATTERIE) show initialy, if required
  gfx.UserImages(iGauge1,0) ;                                // init_Gauge1(CHARGE_BATTERIE) show initialy, if required
  gfx.UserImage(iLeddigits1);                                // init_Leddigits1(TENSION_BATTERIE) show all digits at 0, only do this once

  // FORM 2   ACCUMULATEUR
  gfx.UserImages(iThermometer2,0) ;                          // init_Thermometer2(TEMP_ACCUMULATEUR) show initialy, if required
  gfx.UserImages(iGauge2,0) ;                                // init_Gauge2(CARGE_ACCUMULATEUR) show initialy, if required
  gfx.UserImages(iAngularmeter1,0) ;                         // init_Angularmeter1(SANTE_ACCUMULATEUR) show initialy, if required
  gfx.UserImage(iLeddigits2);                                // init_Leddigits2 show all digits at 0, only do this once

  // FORM 3       MOTOR_DRIVE_COOLANT
  gfx.UserImages(iThermometer3,0) ;                          // init_Thermometer3(TEMP_MOTEUR) show initialy, if required
  gfx.UserImages(iThermometer4,0) ;                          // init_Thermometer4(TEMP_DRIVE) show initialy, if required
  gfx.UserImages(iThermometer5,0) ;                          // init_Thermometer5(TEMP_COOLANT) show initialy, if required
} // end Setup **do not alter, remove or duplicate this line**

void loop()
{
  // put your main code here, to run repeatedly:
  int itouched, val ;
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
  }
}



