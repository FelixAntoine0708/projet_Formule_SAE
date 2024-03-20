/*
Programme : FCT_AFF.cpp
Auteur :    Marc-�tienne Gendron-Fontaine
Date :      5 mars 2024
Brief :     Ce fichier contient les fonctions utilisées pour l'affichage. Il contient aussi une
            fonction pour prendre le bouton pressé ainsi que deux fonctions pour le débogage.

Mat�rielle: ESP32-S3R8 (dans l'�cran), �cran gen4_ESP32_70CT
Encironement: Workshop 4 V4.9.0.7,
Syst�me d�exploitation�: Windows 10 V22H2.
*/


#include "CONST_AFF.h"
#include "gfx4desp32_gen4_ESP32_70CT.h"
#include "FCT_AFF.h"




/*
Brief   : Initialise les boutons avec un arrière-plan jaune.
Param   : gfx soit l'objet pour l'affichage.
Return  : Rien
*/
void init_btn(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.RectangleFilled(0, 415, 800, 500, YELLOW);

	gfx.Buttonx(BTN_1, X_BTN_BATTERIE, Y_BTN, LONG_BTN_X, HAUT_BTN, WHITE, BATTERIE, 1, BLACK);
	gfx.Buttonx(BTN_2, X_BTN_ACCUMULATEUR, Y_BTN, LONG_BTN_X, HAUT_BTN, WHITE, ACCUMULATEUR, 1, BLACK);
	gfx.Buttonx(BTN_3, X_BTN_MOTEUR_DRIVE_COOLANT, Y_BTN, LONG_BTN_X, HAUT_BTN, WHITE, MOTEUR_DRIVE_COOLANT, 1, BLACK);
	
}


/*
Brief   : Affiche le mot "BATTERIE"
Param   : gfx soit l'objet pour l'affichage.
Return  : Rien
*/
void Batterie(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);   // Met le curseur aux position (X,Y) 150, 150
    gfx.print(EFFACE);      // Efface la ligne
    gfx.MoveTo(150, 150);   // Met le curseur aux position (X,Y) 150, 150
    gfx.print(BATTERIE);    // Écrit le message
}



/*
Brief   : Affiche le mot "ACCUMULATEUR"
Param   : gfx soit l'objet pour l'affichage.
Return  : Rien
*/
void Accumulateur(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);       // Met le curseur aux position (X,Y) 150, 150
    gfx.print(EFFACE);          // Efface la ligne
    gfx.MoveTo(150, 150);       // Met le curseur aux position (X,Y) 150, 150
    gfx.print(ACCUMULATEUR);    // Écrit le message
}

/*
Brief   : Affiche le mot "MOTEUR_DRIVE_COOLANT"
Param   : gfx soit l'objet pour l'affichage.
Return  : Rien
*/
void Mott(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);               // Met le curseur aux position (X,Y) 150, 150
    gfx.print(EFFACE);                  // Efface la ligne
    gfx.MoveTo(150, 150);               // Met le curseur aux position (X,Y) 150, 150
    gfx.print(MOTEUR_DRIVE_COOLANT);    // Écrit le message

}



/*
Brief   : Regarde quel bouton a été pressé.
Param   : gfx soit l'objet pour l'affichage.
Return  : Rien
*/
void touch_btn(gfx4desp32_gen4_ESP32_70CT gfx)
{
	int pos_x, pos_y;   // Les position en X et Y.

    
    /*
        Si on touche l'écran, on prend les positions X et Y.
        On regarde ensuite si si la position en Y est plus grande
        que Y_BTN. Si oui, on regarde quel bouton a été pressé.
    */
    if(gfx.touch_Update())
    {
        pos_x = gfx.touch_GetLastX();
        pos_y = gfx.touch_GetLastY();

        if(pos_y >= Y_BTN)
        {

            if(pos_x >= X_BTN_BATTERIE && pos_x <= (X_BTN_BATTERIE + LONG_BTN_X))                               // BTN_BATTERIE
                Batterie(gfx);
            else if(pos_x >= X_BTN_ACCUMULATEUR && pos_x <= (X_BTN_ACCUMULATEUR + LONG_BTN_X))                  // BTN_ACCUMULATEUR
                Accumulateur(gfx);
            else if(pos_x >= X_BTN_MOTEUR_DRIVE_COOLANT && pos_x <= X_BTN_MOTEUR_DRIVE_COOLANT + LONG_BTN_X)    // BTN_MOTEUR_DRIVE_COOLANT
                Mott(gfx);
        }

    }
	 
}


/*
Brief   : Affiche le mot "HELLO_1!!!!!"
Param   : gfx soit l'objet pour l'affichage.
Return  : Rien
*/
void hello_1(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.MoveTo(150, 150);       // Met le curseur aux positions (X,Y) 150, 150
    gfx.print(EFFACE);          // Efface la ligne
    gfx.MoveTo(150, 150);       // Met le curseur aux positions (X,Y) 150, 150
	gfx.print("HELLO_1!!!!!");  // Écris le message
}


/*
Brief   : Affiche le mot "HELLO_2!!!!!"
Param   : gfx soit l'objet pour l'affichage.
Return  : Rien
*/
void hello_2(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.MoveTo(150, 150);       // Met le curseur aux positions (X,Y) 150, 150
    gfx.print(EFFACE);          // Efface la ligne
    gfx.MoveTo(150, 150);       // Met le curseur aux positions (X,Y) 150, 150
	gfx.print("HELLO_2!!!!!");  // Écris le message
}