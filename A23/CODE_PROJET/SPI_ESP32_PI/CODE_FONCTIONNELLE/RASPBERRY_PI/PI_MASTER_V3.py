#!/usr/bin/env python3

"""
Programme : PI_MASTER_V3.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     PI_MASTER_V3.py est le programme fonctionnel où le Pi est le master et le ESP32-C3
            est le slave. Le Pi envoie des données bidon pour que le ESP32-C3 commence à envoyer
            les données sur le bus SPI. Ces données sont affichées dans le terminal.
"""

import spidev   # Pour le SPI
import time     # Pour le delay

# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0

# Configuration du bus SPI (facultatif)
spi.max_speed_hz = 1000000  # Définissez la fréquence du bus SPI si nécessaire
spi.mode = 0               # Mode 0 ou 3 généralement utilisé


"""
Boucle infinie qui envoie des données bidon pour initier le transfert
de données en SPI avec le ESP32-C3. Affiche les données reçues dans le
terminal. Boucle chaque seconde.
"""
try:
    while True:
        # Envoi de données
        tx_data = [0x01, 0x02, 0x03]  # Exemple de données à envoyer
        rx_data = spi.xfer2(tx_data)
        
        # Affichage des données reçues
        print("Données reçues:", rx_data)
        
        time.sleep(1)   #delay de 1 sec

except KeyboardInterrupt:
    spi.close()
    print("Communication SPI interrompue.")

