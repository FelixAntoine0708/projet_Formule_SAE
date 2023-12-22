#!/usr/bin/env python3

"""
Programme : SLAVE_PI_V2.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     SLAVE_PI_V2.py est une mise à jour de SPI_PI_SLAVE.py. Il y a moins de configuration, mais il ne fonctionne pas pour les mêmes raisons
            que son prédécesseur.
"""

import spidev   # Pour le SPI
import time     # Pour le delay




# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0




"""
Brief : Lecture de données sur le bus SPI. Le Pi envoie des données bidon
        pour recevoir les données du ESP32-C3.
Param. : Aucun
Retourne : Les données  sur le bus SPI.
"""
def lire_donnees():
    return spi.xfer2([0])[0]


"""
Cette boucle doit lire les données, provenant du ESP32-C3, sur le bus SPI.
Le Pi affiche ensuite ces données dans le terminal. Le tout à chaque seconde.
On quitte le programme avec une interruption du clavier.
"""
try:
    while True:
        donnees_recues = lire_donnees()
        print(f"Données reçues : {donnees_recues}")
        time.sleep(1)

except KeyboardInterrupt:
    spi.close()
    print("Programme terminé.")
