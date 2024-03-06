/*
Programme : FCT_AFF.cpp
Auteur :    Marc-�tienne Gendron-Fontaine
Date :      5 mars 2024
Brief :     Ce fichier contient le code de base pour afficher des donn�es FICTIFES!!!!! Le but
            de ce programme est de d�montrer la fonctionnalit� de l'�cran gen4_ESP32_70CT. En
            gros, la seule chose que le programme permet de faire, ces de changer de page avec
            l'aide des boutons.

Mat�rielle: ESP32-S3R8 (dans l'�cran), �cran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7,
Syst�me d�exploitation�: Windows 10 V22H2.
*/


#include "CONST_AFF.h"
#include "gfx4desp32_gen4_ESP32_70CT.h"

//gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();



/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void init_btn(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.RectangleFilled(0, 415, 800, 500, YELLOW);

	gfx.Buttonx(BTN_1, X_BTN_BATTERIE, Y_BTN, LONG_BTN_X, 50, WHITE, BATTERIE, 1, BLACK);
	gfx.Buttonx(BTN_2, X_BTN_ACCUMULATEUR, Y_BTN, LONG_BTN_X, 50, WHITE, ACCUMULATEUR, 1, BLACK);
	gfx.Buttonx(BTN_3, X_BTN_MOTEUR_DRIVE_COOLANT, Y_BTN, LONG_BTN_X, 50, WHITE, MOTEUR_DRIVE_COOLANT, 1, BLACK);
	
}


/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void Batterie(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print(BATTERIE);
}



/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void Accumulateur(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print(ACCUMULATEUR);
}

/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void Mott(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print(MOTEUR_DRIVE_COOLANT);

}



/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void touch_btn(gfx4desp32_gen4_ESP32_70CT gfx)
{
	int pos_x, pos_y;


    if(gfx.touch_Update())
    {
        pos_x = gfx.touch_GetLastX();
        pos_y = gfx.touch_GetLastY();

        if(pos_y >= Y_BTN)
        {

            if(pos_x >= X_BTN_BATTERIE && pos_x <= (X_BTN_BATTERIE + LONG_BTN_X))
                Batterie(gfx);
            else if(pos_x >= X_BTN_ACCUMULATEUR && pos_x <= (X_BTN_ACCUMULATEUR + LONG_BTN_X))
                Accumulateur(gfx);
            else if(pos_x >= X_BTN_MOTEUR_DRIVE_COOLANT && pos_x <= X_BTN_MOTEUR_DRIVE_COOLANT + LONG_BTN_X)
                Mott(gfx);
        }

    }
	 
}


/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hello_1(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
	gfx.print("HELLO_1!!!!!");
}


/*
Brief   : Affiche le premier octet de la section "data" de la trame CAN.
Param   : rxFrame soit la trame CAN.
Return  : Rien
*/
void hello_2(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
	gfx.print("HELLO_2!!!!!");
}