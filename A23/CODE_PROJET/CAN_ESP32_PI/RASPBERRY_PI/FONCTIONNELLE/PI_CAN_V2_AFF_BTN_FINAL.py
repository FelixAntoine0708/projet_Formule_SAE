#!/usr/bin/env python3

"""
Programme : PI_VAN_V2_AFF_BTN_FINAL.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     PI_VAN_V2_AFF_BTN_FINAL.py fait la même chose que CAN_PI_V2.py, mais, en affichant les informations du message CAN dans
            une fenêtre fait avec la librairie Turtle. Message lu à chaque 1sec. Ajout de la lecture du bouton qui change la
            couleur de fond de la fenêtre. Quelques modifications pour l'affichage du message. Il est plus facile de la lire maintenant!
"""

import can
import time
import RPi.GPIO as GPIO
import turtle
from turtle import *

# Création de la fenêtre
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


"""
Brief : Fais changer la couleur de fond de la fenêtre selon l'état du btn.
Param. : btn soit l'état logique du bouton
Retourne : Rien
"""
def AFF_BTN(btn):
    if btn == GPIO.LOW:
        wn.bgcolor("light green")  # change de couleur avec l'état du bouton
    else:
        wn.bgcolor("red")
    
    

"""
Brief : Affiche les informations de la trame CAN dans la fenêtre après
        qu'il a été convertie an ASCII.
Param. : msg soit la partie data de la trame CAN.
Retourne : Rien
"""
def AFF(msg):
    skk.clear() #efface l'ancien message
    message = decode(msg)   # décode le message
    skk.write(message, font = font, align = 'center')   # afficher le message recu



"""
Brief : Lis les trames CAN et les envoie dans la fonction "AFF" pour
        qu'elles soient affichées dans la fenêtre. Lis l'état du BTN.
Param. : Rien
Retourne : Rien
"""
def can_receive():
    while True:
        try:
            # Lire l'état du bouton
            etat_bouton = GPIO.input(bouton_pin) 
            AFF_BTN(etat_bouton)    # Affiche l'état du BTN
            
            message = bus.recv(timeout=0.1)      # Lis le bus CAN chaque 100ms
            if message:
                AFF(message.data)

        except KeyboardInterrupt:
            break


"""
Brief : Convertie la partie data de la trame CAN en ASCII.
Param. :msg soit la partie data de la trame CAN.
Retourne : sensor soit la conversion en ASCII
"""
def decode(msg):
    global sensor
    sensor = bytes(msg).decode('ascii') #décode le message
    return sensor   #retourne le message

if __name__ == "__main__":
    can_receive()   #fonction principal du programme
