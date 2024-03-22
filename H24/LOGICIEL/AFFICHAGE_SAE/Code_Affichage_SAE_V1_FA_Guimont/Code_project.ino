//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "Code_projectConst.h"    // Note. This file will not be created if there are no generated graphics

int state;

void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("Code_project"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);                // Global touch enabled

  gfx.UserImages(iAngularmeter1,0) ; // init_Angularmeter1 show initialy, if required
  gfx.UserImages(iAngularmeter2,0) ; // init_Angularmeter2 show initialy, if required
  gfx.UserImages(iAngularmeter3,0) ; // init_Angularmeter3 show initialy, if required
  gfx.UserImages(iAngularmeter4,0) ; // init_Angularmeter4 show initialy, if required
  gfx.UserImages(iAngularmeter5,0) ; // init_Angularmeter5 show initialy, if required


  gfx.imageTouchEnable(iWinbutton1, true) ; // init_Winbutton1 enable touch of widget (on Form1)
  gfx.UserImages(iWinbutton1,0) ;// init_Winbutton1 show initially, if required (on Form1)
  gfx.imageTouchEnable(iWinbutton2, true) ;// init_Winbutton2 enable touch of widget (on Form1)
  gfx.UserImages(iWinbutton2,0) ;// init_Winbutton2 show initially, if required (on Form1)
  gfx.imageTouchEnable(iWinbutton4, true); // init_Winbutton4 enable touch of widget (on Form2)
  gfx.UserImages(iWinbutton4,0); // init_Winbutton4 show initially, if required (on Form2)
  gfx.imageTouchEnable(iWinbutton3, true) ;// init_Winbutton3 enable touch of widget (on Form3)
  gfx.UserImages(iWinbutton3,0) ;// init_Winbutton3 show initially, if required (on Form3)

  gfx.UserImages(iTank1,0) ; // init_Tank1 show initialy, if required

  gfx.UserImages(iMeter1,0) ; // init_Meter1 show initialy, if required
  gfx.UserImages(iMeter2,0) ; // init_Meter1 show initialy, if required

  gfx.LedDigitsDisplay(0, iiLeddigits1, 4, 2, 40, 0) ;  // Leddigits1
  gfx.UserImage(iLeddigits1); // init_Leddigits1 show all digits at 0, only do this once
  gfx.LedDigitsDisplay(0, iiLeddigits2, 3, 1, 40, 0) ;  // Leddigits2
  gfx.UserImage(iLeddigits2);// init_Leddigits2 show all digits at 0, only do this once


  gfx.UserImages(iMeter2,0) ;// init_Meter2 show initialy, if required

  gfx.Cls();
  showTemp();
} // end Setup **do not alter, remove or duplicate this line**

void loop()
{
  // put your main code here, to run repeatedly:
  int itouched, val ;
  gfx.touch_Update();
  state = gfx.touch_GetPen();
  if(state == TOUCH_PRESSED){
    if(gfx.imageTouched() == iWinbutton1){
     showHV();
    }

    if(gfx.imageTouched() == iWinbutton2){
     showLV();
    }

    if(gfx.imageTouched() == iWinbutton3){
     showTemp();
    }

    if(gfx.imageTouched() == iWinbutton4){
     showTemp();
    }
  }
// NE PAS EFFACER AVANT LA FIN (SINON PEUT CAUSER DES PROBLEME DE MARDE)

  //switch (itouched){  // start touched selection **do not alter, remove or duplicate this line**
    //default : // end touched selection **do not alter, remove or duplicate this line**
      //int button = gfx.ImageTouchedAuto();    // use default for keyboards and buttons
     // val = gfx.getImageValue(button);
      //case iWinbutton1 :                                      // process_Winbutton1 process Button (on Form1)
        // process win button, for toggle val will be 1 for down and 0 for up
        //break ;
      //case iWinbutton2 :                                      // process_Winbutton2 process Button (on Form1)
        // process win button, for toggle val will be 1 for down and 0 for up
        //break ;
      //case iWinbutton4 :                                      // process_Winbutton4 process Button (on Form2)
        // process win button, for toggle val will be 1 for down and 0 for up
        //break ;
      //case iWinbutton3 :                                      // process_Winbutton3 process Button (on Form3)
        // process win button, for toggle val will be 1 for down and 0 for up
        //break ;
      //switch (button){  // start button selection **do not alter, remove or duplicate this line**      //} // end button selection **do not alter, remove or duplicate this line**
  //}

// NE PAS EFFACER AVANT LA FIN (SINON PEUT CAUSER DES PROBLEME DE MARDE)
}

void showTemp(){
  gfx.Cls();
  gfx.imageTouchEnable(iWinbutton1, true) ; // init_Winbutton1 enable touch of widget (on Form1)
  gfx.UserImages(iWinbutton1,0) ;// HV BTN

  gfx.imageTouchEnable(iWinbutton2, false) ;
  gfx.UserImages(iWinbutton2,0) ;// LV BTN

  gfx.UserImages(iAngularmeter1, 0) ; // Coolant Temp
  gfx.UserImage(iStatictext1) ;  // text coolant Temp

  gfx.UserImages(iAngularmeter2, 0) ; // Drive Temp
  gfx.UserImage(iStatictext2) ;  // text Dirive Temp

  gfx.UserImages(iAngularmeter3, 0) ; // Motor Temp
  gfx.UserImage(iStatictext3) ;  // Text Motor Temp

  gfx.UserImage(iStatictext6) ;  // Text Title
}

void showLV(){
  gfx.Cls();
  gfx.imageTouchEnable(iWinbutton4, true); // init_Winbutton4 enable touch of widget (on Form2)
  gfx.UserImages(iWinbutton4,0); // init_Winbutton4 show initially, if required (on Form2)
  gfx.imageTouchEnable(iWinbutton1, true) ; // init_Winbutton1 enable touch of widget (on Form1)
  gfx.UserImages(iWinbutton1,0) ;// HV BTN

  gfx.UserImage(iStatictext4) ;  // Statictext4
  gfx.UserImage(iStatictext5) ;  // Statictext5
  gfx.UserImage(iStatictext8) ;  // Statictext8

  gfx.UserImages(iAngularmeter4,0) ; // init_Angularmeter4 show initialy, if required
  gfx.UserImages(iMeter1,0) ; // init_Meter1 show initialy, if required
  gfx.LedDigitsDisplay(0, iiLeddigits1, 4, 2, 40, 0) ;  // Leddigits1
  gfx.UserImage(iLeddigits1); // init_Leddigits1 show all digits at 0, only do this once

  gfx.UserImage(iStatictext7) ;  // Text Title
}

void showHV(){
  gfx.Cls();
  gfx.imageTouchEnable(iWinbutton3, true);// init_Winbutton3 enable touch of widget (on Form3)
  gfx.UserImages(iWinbutton3,0);// init_Winbutton3 show initially, if required (on Form3)
  gfx.imageTouchEnable(iWinbutton2, true);
  gfx.UserImages(iWinbutton2,0);// LV BTN

  gfx.UserImage(iStatictext9);  // Statictext9
  gfx.UserImage(iStatictext11);  // Statictext11
  gfx.UserImage(iStatictext13);  // Statictext13
  gfx.UserImage(iStatictext12);  // Statictext12

  gfx.LedDigitsDisplay(0, iiLeddigits2, 3, 1, 40, 0);  // Leddigits2
  gfx.UserImage(iLeddigits2);// init_Leddigits2 show all digits at 0, only do this once
  gfx.UserImages(iAngularmeter5,0);
  gfx.UserImages(iTank1,0);
  gfx.UserImages(iMeter2,0);

  gfx.UserImage(iStatictext10);  // Text Title
}
