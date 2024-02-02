#!/usr/bin/env python3


"""
Programme : SPI_PI_AFF.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     SPI_PI_AFF.py est la mise à jour du programme SPI_PI.py. La librairie Turtle a été ajoutée
            pour avoir une idée de ce à quoi l'affichage pourrait ressembler. Ce programme est non fonctionnel
            parce que les Pi ne peuvent être que des masters.
"""


# Importation de la librairie Turtle
import turtle
from turtle import *


import spidev   # Pour le SPI
import time     # Pour le delay


# Initialiser le bus SPI
spi = spidev.SpiDev()
spi.open(0,0)  # Bus SPI 0, Périphérique SPI 0
spi.max_speed_hz = 2000000  # Vitesse à 2MHz


# Création de la fenêtre avec Turtle.
wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()


"""
Brief : Lis les données sur le bus SPI. Pour cela, il envoie des
        octets fictifs pour déclencher la réception. Il devrait lire
        au moins 6 octets. Convertis ensuite ces valeurs en caractères
        ASCII.
Param. : Aucun
Retourne : Les données lues sur le bus SPI qui sont converties en code ASCII.
"""
def read_data():
    # Lire les données du bus SPI
    received_data = spi.xfer2([0]*6)  # Envoyer des octets fictifs pour déclencher la réception
    
    # Convertir les valeurs numériques en caractères ASCII
    message = ''.join(chr(val) for val in received_data)
    return message


"""
Brief : Affiche les données converties en ASCII dans une fenêtre
        fait avec la librairie Turtle.
Param. : data soit les données converties en ASCII.
Retourne : Les données lues sur le bus SPI.
"""
def AFF(data):
    skk.clear()
    skk.write(data)
    time.sleep(0.2)



# Pour un compteur (OPTIONNEL) 
cnt = 0


"""
Cette boucle commence par afficher "HELLO_WORLD!!!!!". Le bus
SPI est lu et les données sont converties en ASCII. On affiche
ces données dans la fenêtre fait avec la librairie Turtle. Le compteur
s'incrémente de un. Le tout, à chaque 100 ms. Après 30 sec, le
programme se ferme automatiquement.
"""
while True:
    
    AFF("HELLO_WORLD!!!!!")
       
    # Lire les données de l'ESP32
    received_data = read_data()
 
    AFF(received_data)
        
    # Attendre un certain temps
    time.sleep(0.1)
   
    cnt = cnt + 1
    
    # Après 30 sec, le programme se ferme.
    if cnt == 300:
        spi.close()
        exit(1)