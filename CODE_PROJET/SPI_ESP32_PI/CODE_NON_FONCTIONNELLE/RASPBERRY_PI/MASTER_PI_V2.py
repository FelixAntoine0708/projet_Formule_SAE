#!/usr/bin/env python3



import spidev
import time

# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0
spi.max_speed_hz = 500000



def envoyer_donnees(data):
    # Envoi de données sur le bus SPI
    spi.xfer2([data])

try:
    while True:
        donnees_a_envoyer = int(input("Entrez une valeur (0-255) à envoyer : "))
        envoyer_donnees(donnees_a_envoyer)
        time.sleep(1)

except KeyboardInterrupt:
    spi.close()
    print("Programme terminé.")
