//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
/*
Programme : AFFICHAGE_SAE_V1.ino
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      21 février 2024
Brief :     Ce fichier contiens le code de base pour afficher des données FICTIFES!!!!! Le but
            de ce programme est de démontrer la fonctionnalitée de l'écran gen4_ESP32_70CT. En
            gros, la seule chose que le programme permet de faire, ces de changer de page avec
            l'aide des bontons.

Matérielle: ESP32-S3R8 (dans l'écran), écran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7, Système d’exploitation : Windows 10 V22H2.
*/



//#include "gfx4desp32_gen4_ESP32_70CT.h" //"gfx4desp32_gen4_ESP32_50CT.h"
  #include "gfx4desp32_gen4_ESP32_50CT.h"
gfx4desp32_gen4_ESP32_50CT gfx = gfx4desp32_gen4_ESP32_50CT();

#include "AFFICHAGE_SAE_V1Const.h"    // Note. This file will not be created if there are no generated graphics

// Constante pour les position en X et Y des BTN.   !!!!!!!!! À CHANGER !!!!!!!!!
#define X_BTN_BATTERIE 75
#define X_BTN_ACCUMULATEUR 320
#define X_BTN_MOTEUR_DRIVE_COOLANT 565
#define Y_BTN 425


// Prototype des FCT des Forms (les pages)
void Form_1();
void Form_2();
void Form_3();




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
  gfx.imageTouchEnable(-1, true); // Active la détection du touché des widget

  // FORM 1    BATTERIE_PAGE

  gfx.imageTouchEnable(i4Dbutton1, true, MOMENTARY) ;        // init_4Dbutton1(BATTERIE_F1) enable touch of widget (on Form1)
  gfx.UserImages(i4Dbutton1,0) ;                             // init_4Dbutton1(BATTERIE_F1) show initially, if required (on Form1)
  gfx.imageTouchEnable(i4Dbutton2, true, MOMENTARY) ;        // init_4Dbutton2(ACCUMULATEUR_F1) enable touch of widget (on Form1)
  gfx.UserImages(i4Dbutton2,0) ;                             // init_4Dbutton2(ACCUMULATEUR_F1) show initially, if required (on Form1)
  gfx.imageTouchEnable(i4Dbutton3, true, MOMENTARY) ;        // init_4Dbutton3(MOTEUR_DRIVE_COOLANT_F1) enable touch of widget (on Form1)
  gfx.UserImages(i4Dbutton3,0) ;                             // init_4Dbutton3(MOTEUR_DRIVE_COOLANT_F1) show initially, if required (on Form1)
  gfx.UserImage(iStatictext14) ;  // BATTERIE_BTN_TXT
  gfx.UserImage(iStatictext15) ;  // ACCUMULATEUR_BTN_TXT_FORM1
  gfx.UserImage(iStatictext16) ;  // MOTEUR_DRIVE_COOLANT_BTN_TXT_FORM1
  gfx.UserImage(iStatictext1) ;  // PAGE_NAME_BATTERIE
  gfx.UserImage(iStatictext3) ;  // LBL_TEMP_BATTERIE
  gfx.UserImage(iStatictext4) ;  // LBL_NIVEAU_CHARGE
  gfx.UserImage(iStatictext2) ;  // LBL_TENSION_BATTERIE
  gfx.UserImages(iThermometer1, 35) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iGauge1, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.LedDigitsDisplay(50, iiLeddigits1, 4, 3, 39, 0) ;  // TENSION_BATTERIE


  // FORM 2    ACCUMULATEUR_PAGE

  gfx.imageTouchEnable(i4Dbutton4, true, MOMENTARY) ;        // init_4Dbutton4(BATTERIE_F2) enable touch of widget (on Form2)
  gfx.UserImages(i4Dbutton4,0) ;                             // init_4Dbutton4(BATTERIE_F2) show initially, if required (on Form2)
  gfx.imageTouchEnable(i4Dbutton5, true, MOMENTARY) ;        // init_4Dbutton5(ACCUMULATEUR_F2) enable touch of widget (on Form2)
  gfx.UserImages(i4Dbutton5,0) ;                             // init_4Dbutton5(ACCUMULATEUR_F2) show initially, if required (on Form2)
  gfx.imageTouchEnable(i4Dbutton6, true, MOMENTARY) ;        // init_4Dbutton6(MOTEUR_DRIVE_COOLANT_F2) enable touch of widget (on Form2)
  gfx.UserImages(i4Dbutton6,0) ;                             // init_4Dbutton6(MOTEUR_DRIVE_COOLANT_F2) show initially, if required (on Form2)
  gfx.UserImage(iStatictext17) ;  // BATTERIE_BTN_TXT_FORM2
  gfx.UserImage(iStatictext18) ;  // ACCUMULATEUR_BTN_TXT_FORM2
  gfx.UserImage(iStatictext19) ;  // MOTEUR_DRIVE_COOLANT_BTN_TXT_FORM2
  gfx.UserImage(iStatictext5) ;  // LBL_ACCUMULATEUR
  gfx.UserImage(iStatictext9) ;  // LBL_TEMP_ACCUMULATEUR
  gfx.UserImage(iStatictext6) ;  // LBL_CHARGE_ACCUMULATEUR
  gfx.UserImage(iStatictext7) ;  // LBL_SANTE_ACCUMULATEUR
  gfx.UserImage(iStatictext8) ;  // LBL_RENSION_ACCUMULATEUR
  gfx.UserImages(iThermometer2, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iGauge2, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.UserImages(iAngularmeter1, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
  gfx.LedDigitsDisplay(50, iiLeddigits2, 4, 3, 46, 0) ;  // Leddigits2







  // FORM 3     MOTEUR_DRIVE_COOLANT_PAGE

  gfx.imageTouchEnable(i4Dbutton7, true, MOMENTARY) ;        // init_4Dbutton7(BATTERIE_F3) enable touch of widget (on Form3)
  gfx.UserImages(i4Dbutton7,0) ;                             // init_4Dbutton7(BATTERIE_F3) show initially, if required (on Form3)
  gfx.imageTouchEnable(i4Dbutton8, true, MOMENTARY) ;        // init_4Dbutton8(ACCUMULATEUR_F3) enable touch of widget (on Form3)
  gfx.UserImages(i4Dbutton8,0) ;                             // init_4Dbutton8(ACCUMULATEUR_F3) show initially, if required (on Form3)
  gfx.imageTouchEnable(i4Dbutton9, true, MOMENTARY) ;        // init_4Dbutton9(MOTEUR_DRIVE_COOLANT_F3) enable touch of widget (on Form3)
  gfx.UserImages(i4Dbutton9,0) ;                             // init_4Dbutton9(MOTEUR_DRIVE_COOLANT_F3) show initially, if required (on Form3)
  gfx.UserImage(iStatictext20) ;  // BATTERIE_BTN_TXT_FORM3
  gfx.UserImage(iStatictext21) ;  // ACCUMULATEUR_BTN_TXT_FORM3
  gfx.UserImage(iStatictext22) ;  // MOTEUR_DRIVE_COOLANT_BTN_TXT_FORM3
  gfx.UserImage(iStatictext10) ;  // LBL_MOTEUR_DRIVE_COOLANT
  gfx.UserImage(iStatictext11) ;  // LBL_TEMP_MOTEUR
  gfx.UserImage(iStatictext12) ;  // LBL_TEMP_DRIVE
  gfx.UserImage(iStatictext13) ;  // LBL_TEMP_COOLANT
  gfx.UserImages(iThermometer3, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iThermometer4, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
  gfx.UserImages(iThermometer5, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)




  /*// FORM 1    BATTERIE
  gfx.UserImages(iThermometer1,0) ;                          // init_Thermometer1(TEMP_BATTERIE) show initialy, if required
  gfx.UserImages(iGauge1,0) ;                                // init_Gauge1(CHARGE_BATTERIE) show initialy, if required
  gfx.UserImage(iLeddigits1);                                // init_Leddigits1(TENSION_BATTERIE) show all digits at 0, only do this once
  */



  // FORM 2   ACCUMULATEUR
  /*gfx.UserImages(iThermometer2,0) ;                          // init_Thermometer2(TEMP_ACCUMULATEUR) show initialy, if required
  gfx.UserImages(iGauge2,0) ;                                // init_Gauge2(CARGE_ACCUMULATEUR) show initialy, if required
  gfx.UserImages(iAngularmeter1,0) ;                         // init_Angularmeter1(SANTE_ACCUMULATEUR) show initialy, if required
  gfx.UserImage(iLeddigits2);                                // init_Leddigits2 show all digits at 0, only do this once
  */

  /*// FORM 3       MOTOR_DRIVE_COOLANT
  gfx.UserImages(iThermometer3,0) ;                          // init_Thermometer3(TEMP_MOTEUR) show initialy, if required
  gfx.UserImages(iThermometer4,0) ;                          // init_Thermometer4(TEMP_DRIVE) show initialy, if required
  gfx.UserImages(iThermometer5,0) ;                          // init_Thermometer5(TEMP_COOLANT) show initialy, if required
  */



  Form_2();    // Affiche la deuxiàme page



} // end Setup **do not alter, remove or duplicate this line**

void loop()
{
  // put your main code here, to run repeatedly:

        int button = gfx.ImageTouchedAuto();    // use default for keyboards and buttons
        int val = gfx.getImageValue(button);


        // Code pour faire changere les pages en appuyant sur les BTN!!!!!!!!!
        // Félix, ne touche pasa à mon if s.v.p
        if(button == i4Dbutton1 || button == i4Dbutton4 || button == i4Dbutton7)
           Form_1();
        else if(button == i4Dbutton2 || button == i4Dbutton5 || button == i4Dbutton8)
           Form_2();
        else if(button == i4Dbutton3 || button == i4Dbutton6 || button == i4Dbutton9)
           Form_3();

        delay(1);
}


void Form_1()
{
      gfx.Cls();
      gfx.imageTouchEnable(i4Dbutton1, true, MOMENTARY) ;        // init_4Dbutton1(BATTERIE_F1) enable touch of widget (on Form1)
      gfx.UserImages(i4Dbutton1,0) ;                             // init_4Dbutton1(BATTERIE_F1) show initially, if required (on Form1)
      gfx.imageTouchEnable(i4Dbutton2, true, MOMENTARY) ;        // init_4Dbutton2(ACCUMULATEUR_F1) enable touch of widget (on Form1)
      gfx.UserImages(i4Dbutton2,0) ;                             // init_4Dbutton2(ACCUMULATEUR_F1) show initially, if required (on Form1)
      gfx.imageTouchEnable(i4Dbutton3, true, MOMENTARY) ;        // init_4Dbutton3(MOTEUR_DRIVE_COOLANT_F1) enable touch of widget (on Form1)
      gfx.UserImages(i4Dbutton3,0) ;                             // init_4Dbutton3(MOTEUR_DRIVE_COOLANT_F1) show initially, if required (on Form1)
      gfx.UserImage(iStatictext14) ;  // BATTERIE_BTN_TXT
      gfx.UserImage(iStatictext15) ;  // ACCUMULATEUR_BTN_TXT_FORM1
      gfx.UserImage(iStatictext16) ;  // MOTEUR_DRIVE_COOLANT_BTN_TXT_FORM1
      gfx.UserImage(iStatictext1) ;  // PAGE_NAME_BATTERIE
      gfx.UserImage(iStatictext3) ;  // LBL_TEMP_BATTERIE
      gfx.UserImage(iStatictext4) ;  // LBL_NIVEAU_CHARGE
      gfx.UserImage(iStatictext2) ;  // LBL_TENSION_BATTERIE
      gfx.UserImages(iThermometer1, 35) ; // where frame is 0 to 80 (for a displayed 20 to 100)
      gfx.UserImages(iGauge1, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
      gfx.LedDigitsDisplay(50, iiLeddigits1, 4, 3, 39, 0) ;  // TENSION_BATTERIE

}


void Form_2()
{
    gfx.Cls();
    gfx.imageTouchEnable(i4Dbutton4, true, MOMENTARY) ;        // init_4Dbutton4(BATTERIE_F2) enable touch of widget (on Form2)
    gfx.UserImages(i4Dbutton4,0) ;                             // init_4Dbutton4(BATTERIE_F2) show initially, if required (on Form2)
    gfx.imageTouchEnable(i4Dbutton5, true, MOMENTARY) ;        // init_4Dbutton5(ACCUMULATEUR_F2) enable touch of widget (on Form2)
    gfx.UserImages(i4Dbutton5,0) ;                             // init_4Dbutton5(ACCUMULATEUR_F2) show initially, if required (on Form2)
    gfx.imageTouchEnable(i4Dbutton6, true, MOMENTARY) ;        // init_4Dbutton6(MOTEUR_DRIVE_COOLANT_F2) enable touch of widget (on Form2)
    gfx.UserImages(i4Dbutton6,0) ;                             // init_4Dbutton6(MOTEUR_DRIVE_COOLANT_F2) show initially, if required (on Form2)
    gfx.UserImage(iStatictext17) ;  // BATTERIE_BTN_TXT_FORM2
    gfx.UserImage(iStatictext18) ;  // ACCUMULATEUR_BTN_TXT_FORM2
    gfx.UserImage(iStatictext19) ;  // MOTEUR_DRIVE_COOLANT_BTN_TXT_FORM2
    gfx.UserImage(iStatictext5) ;  // LBL_ACCUMULATEUR
    gfx.UserImage(iStatictext9) ;  // LBL_TEMP_ACCUMULATEUR
    gfx.UserImage(iStatictext6) ;  // LBL_CHARGE_ACCUMULATEUR
    gfx.UserImage(iStatictext7) ;  // LBL_SANTE_ACCUMULATEUR
    gfx.UserImage(iStatictext8) ;  // LBL_RENSION_ACCUMULATEUR
    gfx.UserImages(iThermometer2, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
    gfx.UserImages(iGauge2, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
    gfx.UserImages(iAngularmeter1, 50) ; // where frame is 0 to 100 (for a displayed 0 to 100)
    gfx.LedDigitsDisplay(50, iiLeddigits2, 4, 3, 46, 0) ;  // Leddigits2

}



void Form_3()
{
    gfx.Cls();
    gfx.imageTouchEnable(i4Dbutton7, true, MOMENTARY) ;        // init_4Dbutton7(BATTERIE_F3) enable touch of widget (on Form3)
    gfx.UserImages(i4Dbutton7,0) ;                             // init_4Dbutton7(BATTERIE_F3) show initially, if required (on Form3)
    gfx.imageTouchEnable(i4Dbutton8, true, MOMENTARY) ;        // init_4Dbutton8(ACCUMULATEUR_F3) enable touch of widget (on Form3)
    gfx.UserImages(i4Dbutton8,0) ;                             // init_4Dbutton8(ACCUMULATEUR_F3) show initially, if required (on Form3)
    gfx.imageTouchEnable(i4Dbutton9, true, MOMENTARY) ;        // init_4Dbutton9(MOTEUR_DRIVE_COOLANT_F3) enable touch of widget (on Form3)
    gfx.UserImages(i4Dbutton9,0) ;                             // init_4Dbutton9(MOTEUR_DRIVE_COOLANT_F3) show initially, if required (on Form3)
    gfx.UserImage(iStatictext20) ;  // BATTERIE_BTN_TXT_FORM3
    gfx.UserImage(iStatictext21) ;  // ACCUMULATEUR_BTN_TXT_FORM3
    gfx.UserImage(iStatictext22) ;  // MOTEUR_DRIVE_COOLANT_BTN_TXT_FORM3
    gfx.UserImage(iStatictext10) ;  // LBL_MOTEUR_DRIVE_COOLANT
    gfx.UserImage(iStatictext11) ;  // LBL_TEMP_MOTEUR
    gfx.UserImage(iStatictext12) ;  // LBL_TEMP_DRIVE
    gfx.UserImage(iStatictext13) ;  // LBL_TEMP_COOLANT
    gfx.UserImages(iThermometer3, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
    gfx.UserImages(iThermometer4, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)
    gfx.UserImages(iThermometer5, 50) ; // where frame is 0 to 80 (for a displayed 20 to 100)

}
