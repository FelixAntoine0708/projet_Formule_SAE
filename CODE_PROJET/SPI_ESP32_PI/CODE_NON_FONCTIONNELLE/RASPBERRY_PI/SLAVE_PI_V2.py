#!/usr/bin/env python3



import spidev
import time

# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 1

def lire_donnees():
    # Lecture de données sur le bus SPI
    return spi.xfer2([0])[0]

try:
    while True:
        donnees_recues = lire_donnees()
        print(f"Données reçues : {donnees_recues}")
        time.sleep(1)

except KeyboardInterrupt:
    spi.close()
    print("Programme terminé.")
