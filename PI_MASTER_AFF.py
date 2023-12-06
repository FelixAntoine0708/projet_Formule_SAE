#!/usr/bin/env python3


import turtle
from turtle import *


import spidev
import time



# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0

# Configuration du bus SPI (facultatif)
spi.max_speed_hz = 1000000  # Définissez la fréquence du bus SPI si nécessaire
spi.mode = 0               # Mode 0 ou 3 généralement utilisé


wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()



def AFF(msg):
    skk.clear()
    skk.write(msg)
    time.sleep(0.2)



def conversion(data):
    message = ''.join(chr(val) for val in data)
    return message



cnt = 0


try:
    while True:
        
        AFF("SLAVE!!!!")
        
        # Envoi de données
        tx_data = [0x01, 0x02, 0x03]  # Exemple de données à envoyer
        rx_data = spi.xfer2(tx_data)
        
        # Conversion ASCII en char
        convertie = conversion(rx_data)
        
        AFF(convertie)
        
        time.sleep(1)
        
        if cnt == 300:
            spi.close()
            exit(1)
        
        
        cnt = cnt + 1
        
        
except KeyboardInterrupt:
    spi.close()
    print("Communication SPI interrompue.")