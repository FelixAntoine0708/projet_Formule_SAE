//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
/*
Programme : AFFICHAGE_SAE_CAN_V_0_0_1.4Dino
Auteur :    Marc-Etienne Gendron-Fontaine
Date :      14 avril 2024
Brief :     Version 0.0.1 de l'affichage finale. L'affichage peut changer, mais le code pour le
            CAN sera sensiblement le m�me.

Mat?rielle: ESP32-S3R8 (dans l'Ecran), Ecran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.9,
Syst?me d?exploitation?: Windows 10 V22H2.

*/




#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "AFFICHAGE_SAE_CAN_V_0_0_1Const.h"    // Note. This file will not be created if there are no generated graphics
#include <ESP32-TWAI-CAN.hpp>





// CONSTANTE
#define CAN_TX      43     // GPIO 43 comme pin TX
#define CAN_RX      44    // GPIO 44 comme pin RX
#define TEMP_SET_3  0xA2  // ID des valeur envoye par la DRIVE

// Prototype de FCT
void setUpWidget();
void touch();
void show_temp();
void showLV();
void showHV();
void CAN_OK();
void CAN_ATT();


// VARIALBLE GLOBALE

CanFrame rxFrame;   // Pour la trame CAN

int motor_temp = 0;     // Temperature du MOTOR
int coolant_temp = 0;   // Temperature du COOLANT




void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("AFFICHAGE_SAE_CAN_V_0_0_1"); // Opens DAT and GCI files for read using filename without extension.
  gfx.touch_Set(TOUCH_ENABLE);                // Global touch enabled

  // CAN -----------------------------------
  ESP32Can.setPins(CAN_TX, CAN_RX);   // Initialisation des pin RX et TX

  ESP32Can.setSpeed(ESP32Can.convertSpeed(500));  // Initialisation de la vitesse de transmission (ICI 500 Kbits)

  // Initialisation du queue size
  ESP32Can.setRxQueueSize(1);
  ESP32Can.setTxQueueSize(1);


  /*
    Si les driver CAN d�marrent, on affiche "CAN bus started!"
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

  setUpWidget();
  show_temp();
} // end Setup **do not alter, remove or duplicate this line**






void loop()
{

   if(ESP32Can.readFrame(rxFrame, 0))
   {
      CAN_OK();

      if(rxFrame.identifier == TEMP_SET_3)
      {
         coolant_temp = rxFrame.data[0] + rxFrame.data[1]<<8;
         motor_temp = rxFrame.data[4] + rxFrame.data[5]<<8;
      }

   }
   else
   {
        CAN_ATT();
        delay(5000);
        ESP.restart();
   }


   touch();





  /*// put your main code here, to run repeatedly:
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
          case iWinbutton1 :                                      // process_Winbutton1(HV) process Button (on Form2)
            // process win button, for toggle val will be 1 for down and 0 for up
            break ;
          case iWinbutton2 :                                      // process_Winbutton2 process Button (on Form2)
            // process win button, for toggle val will be 1 for down and 0 for up
            break ;
          case iWinbutton3 :                                      // process_Winbutton3 process Button (on Form2)
            // process win button, for toggle val will be 1 for down and 0 for up
            break ;
        }                                                     // end button selection **do not alter, remove or duplicate this line**
    }
  }  */
}



void setUpWidget()
{
    gfx.UserImages(iGauge1,0) ;                                // init_Gauge1 show initialy, if required
    gfx.UserImages(iGauge2,0) ;                                // init_Gauge2 show initialy, if required
    gfx.UserImages(iGauge3,0) ;                                // init_Gauge3 show initialy, if required
    gfx.UserImage(iLeddigits1);                                // init_Leddigits1 show all digits at 0, only do this once
    gfx.UserImage(iLeddigits2);                                // init_Leddigits2 show all digits at 0, only do this once
    gfx.UserImage(iLeddigits3);                                // init_Leddigits3 show all digits at 0, only do this once
    gfx.imageTouchEnable(iWinbutton1, true, MOMENTARY) ;       // init_Winbutton1(HV) enable touch of widget (on Form2)
    gfx.UserImages(iWinbutton1,0) ;                            // init_Winbutton1(HV) show initially, if required (on Form2)
    gfx.imageTouchEnable(iWinbutton2, true, MOMENTARY) ;       // init_Winbutton2 enable touch of widget (on Form2)
    gfx.UserImages(iWinbutton2,0) ;                            // init_Winbutton2 show initially, if required (on Form2)
    gfx.imageTouchEnable(iWinbutton3, true, MOMENTARY) ;       // init_Winbutton3 enable touch of widget (on Form2)
    gfx.UserImages(iWinbutton3,0) ;                            // init_Winbutton3 show initially, if required (on Form2)
    gfx.UserImage(iLeddigits4);                                // init_Leddigits4 show all digits at 0, only do this once
    gfx.UserImages(iAngularmeter1,0) ;                         // init_Angularmeter1 show initialy, if required
    gfx.UserImages(iGauge4,0) ;                                // init_Gauge4 show initialy, if required
    gfx.UserImage(iLeddigits8);                                // init_Leddigits8 show all digits at 0, only do this once
    gfx.UserImage(iLeddigits7);                                // init_Leddigits7 show all digits at 0, only do this once
    gfx.UserImage(iLeddigits6);                                // init_Leddigits6 show all digits at 0, only do this once
    gfx.UserImage(iLeddigits5);                                // init_Leddigits5 show all digits at 0, only do this once

}





/*
Brief   : Regarde quel bouton a �t� press� et affiche la page en cons�quence.
Param   : Rien
Return  : Rien
*/
void touch()
{
  /*
  Si l'�cran d�tecte un �v�nement (touch_Update), on regarde si le
  dernier statut (touch_GetPen) est une pression sur l'�cran. On regarde,
  ensuite, quel bouton a �t� press� et on affiche la page en cons�quence.
  */
  if(gfx.touch_Update())
  {
    if(gfx.touch_GetPen() == TOUCH_PRESSED)
    {
      if(gfx.imageTouched() == iWinbutton1)
         showHV();
      else if(gfx.imageTouched() == iWinbutton3)
         showLV();
      else if(gfx.imageTouched() == iWinbutton2)
          show_temp();
    }

  }



}


/*
Brief   : Affiche la page Temp�rature
Param   : Rien
Return  : Rien
*/
void show_temp()
{
   gfx.Cls();  // Efface l'�cran

  // Gauge
  gfx.UserImages(iGauge1, motor_temp); // MOTOR TEMP
  gfx.UserImages(iGauge2, 0); // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.UserImages(iGauge3, coolant_temp); // COOLANT TEMP

  // TXT LABEL
  gfx.UserImage(iStatictext4) ;  // Statictext4
  gfx.UserImage(iStatictext3) ;  // Statictext3
  gfx.UserImage(iStatictext2) ;  // Statictext2
  gfx.UserImage(iStatictext1) ;  // Statictext1

  // DIGIT
  gfx.LedDigitsDisplay(motor_temp, iiLeddigits1, 4, 3, 39, 0) ;  // Leddigits1
  gfx.LedDigitsDisplay(0, iiLeddigits2, 4, 3, 39, 0) ;  // Leddigits2
  gfx.LedDigitsDisplay(coolant_temp, iiLeddigits3, 4, 3, 45, 0) ;  // Leddigits3


  // BTN AFF
  gfx.UserImages(iWinbutton1,0) ;
  gfx.UserImages(iWinbutton2,0) ;
  gfx.UserImages(iWinbutton3,0) ;

  // BTN SETUP
  gfx.imageTouchEnable(iWinbutton1, true);
  gfx.imageTouchEnable(iWinbutton2, false);
  gfx.imageTouchEnable(iWinbutton3, true);

}





/*
Brief   : Affiche la page LV
Param   : Rien
Return  : Rien
*/
void showLV()
{

  gfx.Cls();  // Efface l'�cran

  // Widget
  gfx.LedDigitsDisplay(0, iiLeddigits4, 4, 3, 51, 0) ;  // Leddigits4
  gfx.UserImages(iAngularmeter1, 0) ; // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.UserImages(iGauge4, 0) ; // where frame is 0 to 100 (for a displayed 0 to 100)

  // TXT LABEL
  gfx.UserImage(iStatictext5) ;  // Statictext5
  gfx.UserImage(iStatictext8) ;  // Statictext8
  gfx.UserImage(iStatictext7) ;  // Statictext7
  gfx.UserImage(iStatictext6) ;  // Statictext6

    // BTN AFF
  gfx.UserImages(iWinbutton1,0) ;
  gfx.UserImages(iWinbutton2,0) ;
  gfx.UserImages(iWinbutton3,0) ;

  // BTN SETUP
  gfx.imageTouchEnable(iWinbutton1, true);
  gfx.imageTouchEnable(iWinbutton2, true);
  gfx.imageTouchEnable(iWinbutton3, false);


}



/*
Brief   : Affiche la page HV
Param   : Rien
Return  : Rien
*/
void showHV()
{

  gfx.Cls();  // Efface l'�cran

  // WIDGET
  gfx.LedDigitsDisplay(0, iiLeddigits8, 4, 3, 42, 0) ;  // Leddigits8
  gfx.LedDigitsDisplay(0, iiLeddigits7, 4, 3, 37, 0) ;  // Leddigits7
  gfx.LedDigitsDisplay(0, iiLeddigits6, 4, 3, 41, 0) ;  // Leddigits6
  gfx.LedDigitsDisplay(0, iiLeddigits5, 4, 3, 43, 0) ;  // Leddigits5

  // TXT LABEL
  gfx.UserImage(iStatictext9) ;  // Statictext9
  gfx.UserImage(iStatictext10) ;  // Statictext10
  gfx.UserImage(iStatictext12) ;  // Statictext12
  gfx.UserImage(iStatictext11) ;  // Statictext11
  gfx.UserImage(iStatictext13) ;  // Statictext13

  // BTN AFF
  gfx.UserImages(iWinbutton1,0) ;
  gfx.UserImages(iWinbutton2,0) ;
  gfx.UserImages(iWinbutton3,0) ;

  // BTN SETUP
  gfx.imageTouchEnable(iWinbutton1, false);
  gfx.imageTouchEnable(iWinbutton2, true);
  gfx.imageTouchEnable(iWinbutton3, true);


}



void CAN_OK()
{
  gfx.MoveTo(50,50);
  gfx.print("                        ");
  gfx.MoveTo(50,50);
  gfx.print("DONN�ES RECUS");
}


void CAN_ATT()
{
  gfx.MoveTo(50,50);
  gfx.print("                        ");
  gfx.MoveTo(50,50);
  gfx.print("EN ATTENTE DE DONN�ES...");
}
