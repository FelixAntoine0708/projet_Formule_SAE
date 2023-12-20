#!/usr/bin/env python3

import turtle
from turtle import *


import spidev
import time


# Initialiser le bus SPI
spi = spidev.SpiDev()
spi.open(0,0)  # Bus SPI 0, Périphérique SPI 0
spi.max_speed_hz = 2000000
    
    
wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()

    
    
def read_data():
    # Lire les données du bus SPI
    received_data = spi.xfer2([0]*6)  # Envoyer des octets fictifs pour déclencher la réception
    
    # Convertir les valeurs numériques en caractères ASCII
    message = ''.join(chr(val) for val in received_data)
    return message



def AFF(data):
    skk.clear()
    skk.write(data)
    time.sleep(0.2)
    
    
cnt = 0



while True:
    
    AFF("HELLO_WORLD!!!!!")
        
        
    # Lire les données de l'ESP32
    received_data = read_data()


        
    AFF(received_data)
        
    # Attendre un certain temps
    time.sleep(0.1)

        
    cnt = cnt + 1
    
    
    if cnt == 300:
        
        spi.close()
        
        exit(1)