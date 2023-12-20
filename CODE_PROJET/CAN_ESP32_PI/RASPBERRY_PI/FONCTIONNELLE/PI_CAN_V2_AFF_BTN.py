#!/usr/bin/env python3



import can
import time
import RPi.GPIO as GPIO
import turtle
from turtle import *


wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()

# Initialiser le bus CAN
bus = can.interface.Bus(channel='can0', bustype='socketcan')


# Définir le mode de numérotation des broches (BCM ou BOARD)
GPIO.setmode(GPIO.BCM)

# Définir le numéro de la broche du bouton
bouton_pin = 17

# Configurer la broche du bouton en mode d'entrée avec une résistance de pull-up
GPIO.setup(bouton_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)



def AFF_BTN(btn):
    
    if btn == GPIO.LOW:
        wn.bgcolor("light green")
        #turtle.clear()
        #write("BTN_ENFONCÉ!!!!!")
    else:
        wn.bgcolor("red")
        #turtle.clear()
        #write("BTN_PAS_ENFONCÉ!!!!!")
    
    # Attendre un certain temps
    #time.sleep(1)
    
    


def AFF(msg):
    skk.clear()
    skk.write(msg)
    #time.sleep(1)


def can_receive():
    while True:
        try:
            
            #AFF("Attente de messages CAN...")

            # Lire l'état du bouton
            etat_bouton = GPIO.input(bouton_pin)
            AFF_BTN(etat_bouton)    # Affiche l'état du BTN
            
            message = bus.recv(timeout=0.1)
            if message:
                AFF("ID: 0x{:x} DLC: {} Data: {}".format(message.arbitration_id, message.dlc, message.data))

        except KeyboardInterrupt:
            break


if __name__ == "__main__":
    can_receive()
