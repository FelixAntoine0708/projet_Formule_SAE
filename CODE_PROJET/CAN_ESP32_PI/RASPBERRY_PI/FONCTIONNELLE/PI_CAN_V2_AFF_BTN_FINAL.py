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
skk.ht()
font = ('Arial', 32)
sensor = 0

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
        wn.bgcolor("light green")  # change de couleur avec l'état du bouton

    else:
        wn.bgcolor("red")
    
    


def AFF(msg):
    skk.clear() #efface l'ancien message
    message = decode(msg)   # décode le message
    skk.write(message, font = font, align = 'center')   # afficher le message recu


def can_receive():
    while True:
        try:
            # Lire l'état du bouton
            etat_bouton = GPIO.input(bouton_pin) 
            AFF_BTN(etat_bouton)    # Affiche l'état du BTN
            
            message = bus.recv(timeout=0.1)
            if message:
                AFF(message.data)

        except KeyboardInterrupt:
            break

def decode(msg):
    global sensor
    sensor = bytes(msg).decode('ascii') #décode le message
    return sensor   #retourne le message

if __name__ == "__main__":
    can_receive()   #fonction principal du programme
