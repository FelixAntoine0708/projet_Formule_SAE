#!/usr/bin/env python3

"""
Programme : PI_CAN_V2.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :    CAN_PI_V2.py est un programme qui lit le bus CAN avec l'aide du MCP2515. Le Pi affiche les informations (ID, DLC et DATA)
           du message CAN dans un terminal. Ces messages sont lus à chaque seconde. 
"""


import can
import time



"""
Brief : Lis le bus CAN et affiche les informations dans un terminal à chaque seconde.
Param. : Rien
Retourne : Rien
"""
def can_receive():
    # Initialiser le bus CAN
    bus = can.interface.Bus(channel='can0', bustype='socketcan')

    print("Attente de messages CAN...")

    while True:
        try:
            message = bus.recv(timeout=1.0)
            if message:
                print("ID: 0x{:x} DLC: {} Data: {}".format(message.arbitration_id, message.dlc, message.data))  # Affiche toute la trame CAN
        except KeyboardInterrupt:
            break

if __name__ == "__main__":
    can_receive()
