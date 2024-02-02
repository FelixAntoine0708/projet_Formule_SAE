#!/usr/bin/env python3

"""
Programme : PI_MASTER_V3_AFF.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     PI_MASTER_V3_AFF.py est le programme fonctionnel où le Pi est le master et le ESP32-C3
            est le slave. Le Pi envoie des données bidon pour que le ESP32-C3 commence à envoyer
            les données sur le bus SPI. Ces données sont affichées dans une fenêtre fait avec la
            librairie Turtle.
"""

# Importation de la librairie Turtle
import turtle
from turtle import *


import spidev   # Pour le SPI
import time     # Pour le delay


# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0



# Configuration du bus SPI (facultatif)
spi.max_speed_hz = 1000000  # Définissez la fréquence du bus SPI si nécessaire
spi.mode = 0               # Mode 0 ou 3 généralement utilisé



# Création de la fenêtre
wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()


"""
Brief : Affiche les données provenant du ESP32-C3 qui ont été
        converties en ASCII.
Param. : msg soit les données provenant du ESP32-C3 qui ont été
        converties en ASCII..
Retourne : Rien
"""
def AFF(msg):
    skk.clear()
    skk.write(msg)



"""
Brief : Convertis les données en caractères ASCII.
Param. : data soit les données à convertir.
Retourne : message soit les données en ASCII.
"""
def conversion(data):
    message = ''.join(chr(val) for val in data)
    return message


# Compteur (OPTIONNELLE)
cnt = 0



"""
Boucle infinie qui envoie des données bidon pour initier le transfert
de données en SPI avec le ESP32-C3. Convertis ces données en caractère
ASCII. Affiche les données reçues dans la fenêtre fait avec la
librairie Turte. Boucle chaque seconde.
"""
try:
    while True:
        
        AFF("DONNÉES!!!!")
        
        # Envoi de données
        tx_data = [0x01, 0x02, 0x03]  # Exemple de données à envoyer
        rx_data = spi.xfer2(tx_data)
        
        # Conversion ASCII en char
        convertie = conversion(rx_data)
        
        AFF(convertie)
        
        time.sleep(1)   # delay de 1 sec
        

        # Après un compte de 300 (environ 5 min dans ce code), le programme se ferme.
        if cnt == 300:
            spi.close()     # Ferme le bus SPI
            exit(1)         # Quitte le programme
        
        
        cnt = cnt + 1
        
        
except KeyboardInterrupt:
    spi.close()
    print("Communication SPI interrompue.")