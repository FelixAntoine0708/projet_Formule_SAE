#!/usr/bin/env python3

"""
Programme : MASTER_PI_V2.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     MASTER_PI_V2.py fait la même chose que le programme SPI_PI_MASTER.py l'exception que l'utilisateur entre les données à envoyer (entre 0 et 255).
"""



import spidev   # Pour le SPI
import time     # Pour le delay



# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0
spi.max_speed_hz = 500000   # Vitesse à 500kHz


"""
Brief : Envoi de données sur le bus SPI.
Param. : data soit les données que l'utilisateur entre (0-255).
Retourne : Rien
"""
def envoyer_donnees(data):
    spi.xfer2([data])


"""
Boucle principale où le programme attend que l'utilisateur entre une valeur
(0-255) pour ensuite tenter de le transmettre sur le bus SPI avec la fonction
"envoyer_donnees". Fais une pause de 1 seconde. Le programme se ferme avec une
interruption du clavier.
"""
try:
    while True:
        donnees_a_envoyer = int(input("Entrez une valeur (0-255) à envoyer : "))
        envoyer_donnees(donnees_a_envoyer)
        time.sleep(1)

except KeyboardInterrupt:
    spi.close()
    print("Programme terminé.")
