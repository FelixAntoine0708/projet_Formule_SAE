//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
/*
Programme : TEST_MULTI_PAGE_CAN.4Dino
Auteur :    Marc-Etienne Gendron-Fontaine
Date :      26 avril 2024
Brief :     Test d'une facons de mettre a jour des widgets qui sont sur des pages differentes.
            Une meme trame CAN devrait pouvoir mettre a jour les deux widgets.

Materielle: ESP32-S3 (x1), Ecran 7" de 4d systeme, TJA1050 (x2)
Encironement: Workshop 4 V4.9.0.9b,
Systeme d'exploitation: Windows 10 V22H2.
*/




#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "TEST_MULTI_PAGE_CANConst.h"    // Note. This file will not be created if there are no generated graphics
#include <ESP32-TWAI-CAN.hpp>

// CONSTANTE
#define CAN_TX      43     // GPIO 43 comme pin TX
#define CAN_RX      44    // GPIO 44 comme pin RX


CanFrame rxFrame;   // Pour la trame CAN


// PROTOTYPE DE FONCTION
void init_widget();
void touch_btn();
void page_1(bool eff);
void page_2(bool eff);


// VARRIABLE GLOBALE
int val_p_1 = 0;
int id_btn = iWinbutton1;



void setup()
{
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("TEST_MULTI_PAGE_CAN"); // Opens DAT and GCI files for read using filename without extension.
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

  init_widget();
  // end Setup **do not alter, remove or duplicate this line**
  page_1(true);
}

void loop()
{
   int deci = 0;    // Partie des decimal
   int entier = 0;  // Partie des entiers



   /*
     Regarde si on a recus une trame CAN a chaque 50ms. Si oui,
     on traite la trame et on met les valeurs dans les bonnes
     varriables. Sinon, on affiche "EN ATTENTE DE DONNEES...".
    */
   if(ESP32Can.readFrame(rxFrame, 50))
   {
      gfx.MoveTo(10,50);
      gfx.print("                         ");

      entier = (rxFrame.data[0] * 100);
      deci =  rxFrame.data[1];

      val_p_1 = entier + deci;

   }
   else
   {
      //gfx.Cls();                              // Efface l'ecran
      gfx.MoveTo(10,50);
      gfx.print("EN ATTENTE DE DONNEES...");  // Print "EN ATTENTE DE DONNEES..."

   }


   touch_btn();


   // Regarde sur quelle page on est et l'affiche.
   if(id_btn == iWinbutton1)
      page_1(false);
   else if(id_btn == iWinbutton2)
      page_2(false);


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
          case iWinbutton1 :                                      // process_Winbutton1 process Button (on Form2)
            // process win button, for toggle val will be 1 for down and 0 for up
            break ;
          case iWinbutton2 :                                      // process_Winbutton2 process Button (on Form2)
            // process win button, for toggle val will be 1 for down and 0 for up
            break ;
        }                                                     // end button selection **do not alter, remove or duplicate this line**
    }
  } */
}


/*
Brief   : Initialisation des widgets.
Param   : Rien
Return  : Rien
*/
void init_widget()
{
  gfx.LedDigitsDisplay(0, iiLeddigits2, 4, 3, 92, 0) ;  // Leddigits2
  gfx.LedDigitsDisplay(0, iiLeddigits1, 4, 3, 74, 0) ;  // Leddigits1
  gfx.UserImage(iLeddigits2);                                // init_Leddigits2 show all digits at 0, only do this once
  gfx.UserImage(iLeddigits1);                                // init_Leddigits1 show all digits at 0, only do this once
  gfx.imageTouchEnable(iWinbutton1, true, MOMENTARY) ;       // init_Winbutton1 enable touch of widget (on Form2)
  gfx.UserImages(iWinbutton1,0) ;                            // init_Winbutton1 show initially, if required (on Form2)
  gfx.imageTouchEnable(iWinbutton2, true, MOMENTARY) ;       // init_Winbutton2 enable touch of widget (on Form2)
  gfx.UserImages(iWinbutton2,0) ;                            // init_Winbutton2 show initially, if required (on Form2)

}



/*
Brief   : Regarde quel bouton a ete presse et affiche la page en consequence.
Param   : Rien
Return  : Rien
*/
void touch_btn()
{
  /*
  Si l'ecran detecte un evenement (touch_Update), on regarde si le
  dernier statut (touch_GetPen) est une pression sur l'ecran. On regarde,
  ensuite, quel bouton a ete presse et on affiche la page en consequence.
  */
    if(gfx.touch_Update())
    {
      if(gfx.touch_GetPen() == TOUCH_PRESSED)
      {
         if(gfx.imageTouched() == iWinbutton1)
         {
           page_1(true);
           id_btn = iWinbutton1;
         }
         else if (gfx.imageTouched() == iWinbutton2)
         {
            page_2(true);
            id_btn = iWinbutton2;
         }
      }
    }
}


/*
Brief   : Affiche la page 1.
Param   : Rien
Return  : Rien
*/
void page_1(bool eff)
{

    // Si on affiche la page apres avoir presse un BTN,
    // on efface la page.
    if(eff)
      gfx.Cls();  // Efface l'ecran

    // Met a jour le widget
    gfx.LedDigitsDisplay(val_p_1, iiLeddigits1, 4, 3, 74, 0);

    // Affiche les bouttons
    gfx.UserImages(iWinbutton1,0);
    gfx.UserImages(iWinbutton2,0);

     // BTN SETUP
    gfx.imageTouchEnable(iWinbutton1, false);
    gfx.imageTouchEnable(iWinbutton2, true);

}


/*
Brief   : Affiche la page 2.
Param   : Rien
Return  : Rien
*/
void page_2(bool eff)
{

    // Si on affiche la page apres avoir presse un BTN,
    // on efface la page.
    if(eff)
      gfx.Cls();  // Efface l'ecran

    // Met a jour le widget
    gfx.LedDigitsDisplay(val_p_1 + 1000, iiLeddigits2, 4, 3, 92, 0);

     // Affiche les bouttons
    gfx.UserImages(iWinbutton1,0);
    gfx.UserImages(iWinbutton2,0);

     // BTN SETUP
    gfx.imageTouchEnable(iWinbutton1, true);
    gfx.imageTouchEnable(iWinbutton2, false);

}
