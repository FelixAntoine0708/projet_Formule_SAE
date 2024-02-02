#!/usr/bin/env python3

"""
Programme : SPI_PI_MASTER.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     SPI_PI_MASTER.py devait transmettre 0xAA au ESP32-C3 dans l'espoir que celui-ci les reçoive et les affiche dans un terminal.
"""

import time     # Pour le delay
import spidev   # Pour le SPI


bus = 0     # BUS SPI


device = 1  # CS0


spi = spidev.SpiDev()   # Enable SPI

spi.open(bus, device)   # ON OUVRE LA CONNECTION SPI SUR LE BUS 0 ET LE CS0 (CE0)

# VITESSE SPI DE 500Kbs ET MODE 0
spi.max_speed_hz = 500000
spi.mode = 0
spi.bits_per_word = 8
spi.cshigh = False
spi.lsbfirst = False
spi.threewire = False




"""
Doit transmettre 0xAA au ESP32 toutes les 100ms. Il affiche dans le terminal "MESSAGE_ENVOYE!!!".
Pendant ce temps, le ESP32 doit recevoir le 0xAA. Du moins, en théorie...
"""
try:
    while True:
        spi.writebytes([0xAA])
        print("MESSAGE_ENVOYE!!!")
        time.sleep(0.1)

finally:
    spi.close() 