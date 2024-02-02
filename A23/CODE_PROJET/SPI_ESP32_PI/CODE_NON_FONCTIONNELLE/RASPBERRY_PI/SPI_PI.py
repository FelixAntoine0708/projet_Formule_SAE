#!/usr/bin/env python3

"""
Programme : SPI_PI.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     SPI_PI.py est l'un des deux programmes dont le but est de communiquer en SPI avec un ESP32.
            Puisque les Pi ne peuvent être que des masters, c'était une tentative vouée à l'échec.
"""


import spidev   # Pour le SPI
import time     # Pour le delay



# Initialiser le bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # Bus SPI 0, Périphérique SPI 0


"""
Brief : Lis les données sur le bus SPI. Pour cela, il envoie des
        octets fictifs pour déclencher la réception. Il devrait lire
        au moins 6 octets.
Param. : Aucun
Retourne : Les données lues sur le bus SPI.
"""
def read_data():
    received_data = spi.xfer2([0]*6)  # Envoyer des octets fictifs pour déclencher la réception
    return received_data



"""
Cette boucle infinie doit recevoir les données envoyées depuis un
ESP32-C3. Le Pi doit ensuite les afficher dans un terminal. Le tout
se fait chaque seconde.
"""
while True:
    try:
        # Lire les données de l'ESP32
        received_data = read_data()
        print("Données reçues:", received_data)

        # Attendre un certain temps
        time.sleep(1)

    except KeyboardInterrupt:
        spi.close()
        break

