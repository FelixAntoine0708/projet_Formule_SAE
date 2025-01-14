//
// NB! This is a file generated from the .4Dino file, changes will be lost
//     the next time the .4Dino file is built
//
/*
Programme : Code_Final_CANVision_V1_FA.4Dino
Auteur :    F�lix-Antoine Guimont, Marc-Etienne Gendron-Fontaine
Date :      27 avril 2024
Brief :     Version finale de l'affichage. Ce fichier inclus le code pour recevoir des trame CAN ainsi
            que le code pour afficher et mettre � jour les donn�es re�ues par ces trames.

Materielle: ESP32-S3 (x1), Ecran 7" de 4d systeme, TJA1050 (x2)
Encironement: Workshop 4 V4.9.0.9b,
Systeme d'exploitation: Windows 10 V22H2.
*/







// Pattern is ignored on this platform
#include "gfx4desp32_gen4_ESP32_70CT.h"

gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

#include "Code_Final_CANVision_V1_FAConst.h"
#include <ESP32-TWAI-CAN.hpp>

#define CAN_TX      43     // GPIO 43 comme pin TX
#define CAN_RX      44    // GPIO 44 comme pin RX
CanFrame rxFrame;   // Pour la trame CAN

// tableau CAN
struct Result {
  int dataArray[10];
};

// Variable Global
int pageValue = 0;
Result clean;
int incHVtank =0;
int incHVTemp = 0;
int incHVSOC = 0;
int incHVVolt = 0;
int incCoolant = 0;
int incDrive = 0;
int incMotor = 0;
int incLVSOC = 0;
int incLVTemp = 0;
int incLVVolt = 0;

// initialisation des fonctions
void btn();
void button();
void clear();
void hv_page(Result total, bool erase);
void temp_page(Result total, bool erase);
void lv_page(Result total, bool erase);
void error_page();
void noDataRecieved();
Result readCAN();



void setup()
{
  // ****************     Initialisation de base NE PAS TOUCHER     ****************
  gfx.begin();
  gfx.Cls();
  gfx.ScrollEnable(false);
  gfx.BacklightOn(true);
  gfx.Orientation(LANDSCAPE);
  gfx.SmoothScrollSpeed(5);
  gfx.TextColor(WHITE, BLACK); gfx.Font(2);  gfx.TextSize(1);
  gfx.Open4dGFX("Code_Final_CANVision_V1_FA");
  gfx.touch_Set(TOUCH_ENABLE);
  //*****************************************************************************

  // CAN
  ESP32Can.setPins(CAN_TX, CAN_RX);   // Initialisation des pin RX et TX
  ESP32Can.setSpeed(ESP32Can.convertSpeed(1000));  // Initialisation de la vitesse de transmission (ICI 1000 Kbits)

  // Initialisation du queue size
  ESP32Can.setRxQueueSize(1);
  ESP32Can.setTxQueueSize(1);

  // button for changing page
  button();

  // HV page init widget
  gfx.UserImages(iAngularmeter1,0);
  gfx.UserImage(iLeddigits1);
  gfx.UserImage(iLeddigits2);
  gfx.UserImages(iTank1,0);
  gfx.UserImage(iLeddigits3);
  gfx.UserImage(iLeddigits4);
  gfx.UserImages(iMeter1,0);

  // Temp page init widget
  gfx.UserImages(iAngularmeter2,0);
  gfx.UserImage(iLeddigits5);
  gfx.UserImages(iAngularmeter3,0);
  gfx.UserImage(iLeddigits6);
  gfx.UserImages(iAngularmeter4,0);
  gfx.UserImage(iLeddigits7);

  // LV page init widget
  gfx.UserImages(iMeter2,0);
  gfx.UserImage(iLeddigits10);
  gfx.UserImages(iAngularmeter5,0);
  gfx.UserImage(iLeddigits9);
  gfx.UserImage(iLeddigits8);

  // Debut du CAN
  if(ESP32Can.begin()){
    gfx.println("CAN bus started!");
    delay(1000);
  }
  else
  {
      noDataRecieved();
      while(1);
  }

  // page de base
  error_page();
  delay(2000);
  gfx.Cls();
  clean.dataArray[4] =0;
  clean.dataArray[5] =0;
  clean.dataArray[6] =0;
  temp_page(clean, false);
  pageValue = 2;
  button();


} // end Setup **do not alter, remove or duplicate this line**

void loop()
{
  while(true){
    btn();  // verifie les boutons s'il sont appuyer
    Result total = readCAN(); // lis le BUS CAN

    switch(pageValue){
      case 1:
        hv_page(total, false);  // appel la page HV
        break;

      case 2:
        temp_page(total, false);  // appel la page Temp
        break;

      case 3:
        lv_page(total, false); // appel la page LV
        break;
    }
  }




  /***                        Code de base de Workshop4 qu'on ne peux pas modifier sinon cela ne fonctionne plus                         ***/
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // put your main code here, to run repeatedly:
  //int itouched, val ;
  //if(gfx.touch_Update())
  //{
  //  itouched = gfx.imageTouched() ;
  //  switch (itouched)
  //  {                                                         // start touched selection **do not alter, remove or duplicate this line**
  //    // case statements for Knobs and Sliders go here
  //    default :                                               // end touched selection **do not alter, remove or duplicate this line**
  //      int button = gfx.ImageTouchedAuto();    // use default for keyboards and buttons
  //      val = gfx.getImageValue(button);
  //      switch (button)
  //      {                                                     // start button selection **do not alter, remove or duplicate this line**
  //        // case, one for each button or keyboard, default should end up as -1
  //      }                                                     // end button selection **do not alter, remove or duplicate this line**
  //  }
  //}
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}



/*
Brief   : Initialise les boutons
Param   : Rien
Return  : Rien
*/
void button(){
  gfx.RectangleFilled(0, 428, 800, 500, YELLOW) ;  // Rectangle1
  gfx.Buttonx(1, 0, 428, 120, 55, GREEN, "HV", FONT2, YELLOW);  // bouton HV
  gfx.Buttonx(2, 330, 428, 150, 55, GREEN, "Temp", FONT2, YELLOW);  // bouton Temp
  gfx.Buttonx(3, 678, 428, 125, 55, GREEN, "LV", FONT2, YELLOW);  // bouton LV
}




/*
Brief   : Affiche la page HV avec les valeurs des widgets mis � jour.
Param   : erase, pour savoir si nous devons effacer la page ou non.
Return  : Rien
*/
void hv_page(Result total, bool erase){

  if(erase){  //si premiere fois dans page
    clear();  // efface les anciens widget
  }
  // Titre page
  gfx.UserImage(iStatictext3) ;

  // Temp
  gfx.UserImage(iStatictext1);  // titre Widget
  gfx.UserImages(iAngularmeter1, total.dataArray[0]); // widget aiguille
  gfx.LedDigitsDisplay(total.dataArray[0], iiLeddigits1, 2, 1, 45, 0);  // widget 7 segments

  // Voltage
  gfx.UserImage(iStatictext2);// titre Widget
  gfx.LedDigitsDisplay(total.dataArray[3], iiLeddigits2, 2, 1, 45, 0);  // widget 7 segments

  // SOH
  gfx.UserImage(iStatictext5);// titre Widget
  gfx.UserImages(iTank1, total.dataArray[1]); // widget Tank Batterie
  gfx.LedDigitsDisplay(total.dataArray[1], iiLeddigits3, 3, 1, 45, 0);  // widget 7 segments

  // SOC
  gfx.UserImage(iStatictext4);// titre Widget
  gfx.UserImages(iMeter1, total.dataArray[2]);  // widget charge
  gfx.LedDigitsDisplay(total.dataArray[2], iiLeddigits4, 3, 1, 45, 0);  // widget 7 segments

  // btn activation
  gfx.ButtonActive(1, false); // desactive le bouton HV
  gfx.ButtonActive(2, true);  // active le bouton Temp
  gfx.ButtonActive(3, true);  // active le bouton LV
}




/*
Brief   : Affiche la page TEMP avec les valeurs des widgets mis � jour.
Param   : erase, pour savoir si nous devons effacer la page ou non.
Return  : Rien
*/
void temp_page(Result total, bool erase){

  if(erase){  //si premiere fois dans page
    clear();  // efface les anciens widget
  }

  // Titre page
  gfx.UserImage(iStatictext9);

  // Coolant
  gfx.UserImage(iStatictext6);  // titre Widget
  gfx.UserImages(iAngularmeter2, total.dataArray[4]); // widget aiguille
  gfx.LedDigitsDisplay(total.dataArray[4], iiLeddigits5, 2, 1, 45, 0);  // widget 7 segments

  // Drive
  gfx.UserImage(iStatictext7);  // titre Widget
  gfx.UserImages(iAngularmeter3, total.dataArray[5]); // widget aiguille
  gfx.LedDigitsDisplay(total.dataArray[5], iiLeddigits6, 2, 1, 45, 0);  // widget 7 segments

  // Motor
  gfx.UserImage(iStatictext8);  // titre Widget
  gfx.UserImages(iAngularmeter4, total.dataArray[6]); // widget aiguille
  gfx.LedDigitsDisplay(total.dataArray[6], iiLeddigits7, 2, 1, 45, 0);  // widget 7 segments

  // btn activation
  gfx.ButtonActive(1, true);  // active le bouton HV
  gfx.ButtonActive(2, false); // desactive le bouton Temp
  gfx.ButtonActive(3, true);  // active le bouton LV
}



/*
Brief   : Affiche la page LV avec les valeurs des widgets mis � jour.
Param   : erase, pour savoir si nous devons effacer la page ou non.
Return  : Rien
*/
void lv_page(Result total, bool erase){

  if(erase){  //si premiere fois dans page
    clear();  // efface les anciens widget
  }

  // Titre page
  gfx.UserImage(iStatictext13);

  // SOC
  gfx.UserImage(iStatictext12); // titre Widget
  gfx.UserImages(iMeter2, total.dataArray[7]);  // widget charge
  gfx.LedDigitsDisplay(total.dataArray[7], iiLeddigits10, 3, 1, 45, 0); // widget 7 segments

  // Temp
  gfx.UserImage(iStatictext10); // titre Widget
  gfx.UserImages(iAngularmeter3, total.dataArray[8]); // widget aiguille
  gfx.LedDigitsDisplay(total.dataArray[8], iiLeddigits9, 2, 1, 45, 0);  // widget 7 segments

  // Voltage
  gfx.UserImage(iStatictext11); // titre Widget
  gfx.LedDigitsDisplay(total.dataArray[9], iiLeddigits8, 2, 1, 45, 0);  // widget 7 segments

  // btn activation
  gfx.ButtonActive(1, true);  // active le bouton HV
  gfx.ButtonActive(2, true);  // active le bouton Temp
  gfx.ButtonActive(3, false); // desactive le bouton LV
}



/*
Brief   : Efface les Widgets de la page en dessinant un rectangle noir.
Param   : Rien
Return  : Rien
*/
void clear(){
  gfx.RectangleFilled(0, 0, 800, 428, BLACK); // affiche un rectangle noir
}



/*
Brief   : V�rifie quel bouton a �t� press� et affiche la page en cons�quence.
Param   : Rien
Return  : Rien
*/
void btn(){
  int btnVerif;

  btnVerif = gfx.CheckButtons();  // verifie si bouton toucher

  if(btnVerif == 1){ // si page HV choisi
    clean.dataArray[0] =0; // affiche 0
    clean.dataArray[1] =0;
    clean.dataArray[2] =0;
    clean.dataArray[3] =0;
    pageValue = 1; // garde les wiget actif
    hv_page(clean, true); // appel la page
  }

  if(btnVerif == 2){  // si page Temp choisi
    clean.dataArray[4] =0;  // affiche 0
    clean.dataArray[5] =0;
    clean.dataArray[6] =0;
    pageValue = 2;  // garde les wiget actif
    temp_page(clean, true); // appel la page
  }

  if (btnVerif == 3){ // si page LV choisi
    clean.dataArray[7] =0;  // affiche 0
    clean.dataArray[8] =0;
    clean.dataArray[9] =0;
    pageValue = 3;  // garde les wiget actif
    lv_page(clean, true); // appel la page
  }
}



/*
Brief   : Si une erreur majeure apparait, on fait clignoter la page en rouge.
Param   : Rien
Return  : Rien
*/
void error_page(){
  for (int i=0; i<5; i++){
    gfx.Cls(0xF965); // efface la page en rouge
    delay(500);
    gfx.Cls();  // efface la page en noir
    delay(500);
  }
}


/*
Brief   : Si on ne re�oit aucune trame CAN, on affiche un message d'erreur.
Param   : Rien
Return  : Rien
*/
void noDataRecieved() {
  gfx.UserImage(iStatictext14); // affiche un texte error
}


/*
  Breif:  Lecteur du CAN Bus
  return: tableau 10 valeurs
*/


/*
Brief   :
Param   : Rien
Return  : Rien
*/
Result readCAN(){
  Result data;


  // CAN

  //if(ESP32Can.readFrame(rxFrame, 50))
  //{
  //
  //  entier = (rxFrame.data[0] * 100);
  //  deci =  rxFrame.data[1];
  //
  //  val_p_1 = entier + deci;
  //
  //  return val_p_1;
  //
  //}
  //
  //else
  //{
  //  clear();       // Efface l'ecran
  //  noDataRecieved();  // Print "EN ATTENTE DE DONNEES..."
  //  delay(1000);
  //  return 0;
  //}


  // HV
  if (incHVTemp < 60) { // pour le widget a aiguille
    data.dataArray[0] = incHVTemp;
    incHVTemp++;
  } else if (incHVTemp >= 60) {
    data.dataArray[0] = 0;
    incHVTemp =0;
  }
  if (incHVtank < 100) {  // pour le widget de batterie
    data.dataArray[1] = incHVtank;
    incHVtank++;
  } else if (incHVtank >=100) {
    data.dataArray[1] = 0;
    incHVtank =0;
  }
  if (incHVSOC < 100) { // pour le widget de charge
    data.dataArray[2] = incHVSOC;
    incHVSOC++;
  } else if (incHVSOC >= 100) {
    data.dataArray[2] = 0;
    incHVSOC =0;
  }
  if (incHVVolt < 12) { // pour le widget de Tension
    data.dataArray[3] = incHVVolt;
    incHVVolt++;
  } else if (incHVVolt >= 12) {
    data.dataArray[3] = 0;
    incHVVolt =0;
  }

  //Temp
  if (incCoolant < 60) {  // pour le widget a aiguille Coolant
    data.dataArray[4] = incCoolant;
    incCoolant++;
  } else if (incCoolant >= 60) {
    data.dataArray[4] = 0;
    incCoolant =0;
  }
  if (incDrive < 60) {  // pour le widget a aiguille Drive
    data.dataArray[5] = incDrive;
    incDrive++;
  } else if (incDrive >= 60) {
    data.dataArray[5] = 0;
    incDrive =0;
  }
  if (incMotor < 60) {  // pour le widget a aiguille Motor
    data.dataArray[6] = incMotor;
    incMotor++;
  } else if (incMotor >= 60) {
    data.dataArray[6] = 0;
    incMotor =0;
  }

  // LV
  if (incLVSOC < 100) { // pour le widget de charge
    data.dataArray[7] = incLVSOC;
    incLVSOC++;
  } else if (incLVSOC >= 100) {
    data.dataArray[7] = 0;
    incLVSOC =0;
  }
  if (incLVTemp < 60) { // pour le widget a aiguille
    data.dataArray[8] = incLVTemp;
    incLVTemp++;
  } else if (incLVTemp >= 60) {
    data.dataArray[8] = 0;
    incLVTemp =0;
  }
  if (incLVVolt < 12) { // pour le widget de Tension
    data.dataArray[9] = incLVVolt;
    incLVVolt++;
  } else if (incLVVolt >= 12) {
    data.dataArray[9] = 0;
    incLVVolt =0;
  }

  return data; // retourne le tableau au complet
}

