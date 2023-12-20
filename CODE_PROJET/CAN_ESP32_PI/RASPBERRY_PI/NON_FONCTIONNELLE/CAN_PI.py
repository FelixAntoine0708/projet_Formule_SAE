#!/usr/bin/env python3



import can
import RPi.GPIO as GPIO

# Configuration des broches GPIO
GPIO_RX = 14  # Remplacez par le numéro de la broche GPIO connectée à la broche RX du TJA1050
GPIO_TX = 15  # Remplacez par le numéro de la broche GPIO connectée à la broche TX du TJA1050

# Initialisation des broches GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(GPIO_RX, GPIO.IN)
GPIO.setup(GPIO_TX, GPIO.OUT)

# Configuration de la bibliothèque python-can
can_interface = 'socketcan'
channel = 'can0'  # Nom du canal CAN

# Création de l'interface CAN
bus = can.interface.Bus(channel=channel, bustype=can_interface)

try:
    while True:
        # Lecture d'une trame CAN
        message = bus.recv()

        # Traitement de la trame
        print(f"ID: {hex(message.arbitration_id)}  Data: {message.data}")

except KeyboardInterrupt:
    # Arrêt du programme lorsqu'on appuie sur Ctrl+C
    GPIO.cleanup()
    print("\nProgramme arrêté.")
