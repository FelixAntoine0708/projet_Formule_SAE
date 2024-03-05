


#include "CONST_AFF.h"
#include "gfx4desp32_gen4_ESP32_70CT.h"

//gfx4desp32_gen4_ESP32_70CT gfx = gfx4desp32_gen4_ESP32_70CT();

void init_btn(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.RectangleFilled(0, 415, 800, 500, YELLOW);

	gfx.Buttonx(BTN_1, X_BTN_BATTERIE, Y_BTN, LONG_BTN_X, 50, WHITE, BATTERIE, 1, BLACK);
	gfx.Buttonx(BTN_2, X_BTN_ACCUMULATEUR, Y_BTN, LONG_BTN_X, 50, WHITE, ACCUMULATEUR, 1, BLACK);
	gfx.Buttonx(BTN_3, X_BTN_MOTEUR_DRIVE_COOLANT, Y_BTN, LONG_BTN_X, 50, WHITE, MOTEUR_DRIVE_COOLANT, 1, BLACK);
	
}



void Batterie(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print(BATTERIE);
}


void Accumulateur(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print(ACCUMULATEUR);
}


void Mott(gfx4desp32_gen4_ESP32_70CT gfx)
{
    gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
    gfx.print(MOTEUR_DRIVE_COOLANT);

}


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



void hello_1(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
	gfx.print("HELLO_1!!!!!");
}



void hello_2(gfx4desp32_gen4_ESP32_70CT gfx)
{
	gfx.MoveTo(150, 150);
    gfx.print(EFFACE);
    gfx.MoveTo(150, 150);
	gfx.print("HELLO_2!!!!!");
}