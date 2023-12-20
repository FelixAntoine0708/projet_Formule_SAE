#!/usr/bin/env python3



import spidev
import time

# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0

# Configuration du bus SPI (facultatif)
spi.max_speed_hz = 1000000  # Définissez la fréquence du bus SPI si nécessaire
spi.mode = 0               # Mode 0 ou 3 généralement utilisé

try:
    while True:
        # Envoi de données
        tx_data = [0x01, 0x02, 0x03]  # Exemple de données à envoyer
        rx_data = spi.xfer2(tx_data)
        #spi.xfer2(tx_data)
        
        for i in tx_data:
            print("Données reçues:", chr (i))
        
        # Affichage des données reçues
        print("Données reçues:", rx_data)
        
        time.sleep(1)

except KeyboardInterrupt:
    spi.close()
    print("Communication SPI interrompue.")

