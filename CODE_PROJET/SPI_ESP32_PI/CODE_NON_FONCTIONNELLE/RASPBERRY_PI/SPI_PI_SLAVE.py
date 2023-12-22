#!/usr/bin/env python3

"""
Programme : SPI_PI_SLAVE.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     SPI_PI_SLAVE.py devait mettre le Pi en slave pour la communication en SPI. Nous avons découvert que le Pi ne peut être qu'un master.
"""



import time       # Pour le delay
import spidev     # Pour le SPI


bus = 0     # BUS SPI
device = 1  # CS0


spi = spidev.SpiDev()   # Enable SPI
spi.open(bus, device)   # ON OUVRE LA CONNECTION SPI SUR LE BUS 0 ET LE CS0 (CE0)

# VITESSE SPI DE 500Kbs ET MODE 0
# 8 oct par mots
spi.max_speed_hz = 500000
spi.mode = 0
spi.bits_per_word = 8

# Ils sont à "False" par défaut. Mais juste pour être sur...
spi.cshigh = False
spi.lsbfirst = False
spi.threewire = False



"""
Brief : Converti les octets reçus en hexadécimal.
Param. : Byte soit les octets reçus.
Retourne : La valeur de "Byte" converti en hexadécimal.
"""
def BytesToHex(Bytes):
      return ''.join(["0x%02X " % x for x in Bytes]).strip()


"""
Cette boucle infinie doit transmettre 0xBB au ESP32-C3. Le ESP32-C3 lui
renvoie en retour un octet que le Pi devrait lire. Cet octet est ensuite
affiché dans un terminal. La fonction "BytesToHex" n'est pas utilisée tout
simplement parce que le Pi ne reçoit rien...
"""
try:
    while True:
            msg = spi.xfer([0xBB])  # VA LIRE 1 OCTETS SUR LE BUS
            hexa =  msg
            print(msg)
            time.sleep(0.1)     # DELAY DE 100MS


finally:
      spi.close()   # ON FERME LE BUS SPI