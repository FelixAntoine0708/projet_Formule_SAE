#!/usr/bin/env python3

"""
Programme : PI_VAN_V2_AFF.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     PI_CAN_V2_AFF.py fait la même chose que CAN_PI_V2.py, mais, en affichant les informations du message CAN dans
            une fenêtre fait avec la librairie Turtle. Message lu à chaque 1sec.
"""


import can
import time

import turtle
from turtle import *

# Création de la fenêtre
wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()

# Initialiser le bus CAN
bus = can.interface.Bus(channel='can0', bustype='socketcan')


"""
Brief : Affiche les informations de la trame CAN dans la fenêtre.
Param. : msg soit les données de la trame CAN.
Retourne : Rien
"""
def AFF(msg):
    skk.clear()
    skk.write(msg)
    time.sleep(1)



"""
Brief : Lis les trames CAN et les envoie dans la fonction "AFF" pour
        qu'elles soient affichées dans la fenêtre.
Param. : Rien
Retourne : Rien
"""
def can_receive():
    while True:
        try:
            
            AFF("Attente de messages CAN...")


            message = bus.recv(timeout=1.0) # Lis le bus CAN chaque seconde
            if message:
                AFF("ID: 0x{:x} DLC: {} Data: {}".format(message.arbitration_id, message.dlc, message.data))

        except KeyboardInterrupt:
            break


if __name__ == "__main__":
    can_receive()
