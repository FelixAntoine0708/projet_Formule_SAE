#!/usr/bin/env python3

#import turtle
#from turtle import *


import spidev
import time

# Initialiser le bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # Bus SPI 0, Périphérique SPI 0


#wn = turtle.Screen()
#wn.bgcolor("light green")
#wn.title("Turtle")
#skk = turtle.Turtle()



def read_data():
    # Lire les données du bus SPI
    received_data = spi.xfer2([0]*6)  # Envoyer des octets fictifs pour déclencher la réception
    return received_data

while True:
    try:
        # Lire les données de l'ESP32
        received_data = read_data()
        print("Données reçues:", received_data)

        write(received_data)

        # Attendre un certain temps
        time.sleep(1)

    except KeyboardInterrupt:
        spi.close()
        break

