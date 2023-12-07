#!/usr/bin/env python3



import turtle
from turtle import *
import RPi.GPIO as GPIO
import spidev
import time


# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)  # bus 0, device 0

# Configuration du bus SPI (facultatif)
spi.max_speed_hz = 1000000  # Définissez la fréquence du bus SPI si nécessaire
spi.mode = 0               # Mode 0 ou 3 généralement utilisé



wn = turtle.Screen()
wn.bgcolor("light blue")
wn.title("Turtle")
skk = turtle.Turtle()


# Définir le mode de numérotation des broches (BCM ou BOARD)
GPIO.setmode(GPIO.BCM)

# Définir le numéro de la broche du bouton
bouton_pin = 17

# Configurer la broche du bouton en mode d'entrée avec une résistance de pull-up
GPIO.setup(bouton_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)




def AFF(msg):
    skk.clear()
    skk.write(msg)
    time.sleep(0.1)



def conversion(data):
    message = ''.join(chr(val) for val in data)
    return message





def AFF_BTN(btn):
    
    if btn == GPIO.HIGH:
        wn.bgcolor("light green")
        #turtle.clear()
        #write("BTN_ENFONCÉ!!!!!")
    else:
        wn.bgcolor("red")
        #turtle.clear()
        #write("BTN_PAS_ENFONCÉ!!!!!")
    
    # Attendre un certain temps
    time.sleep(0.1)
    
    
    
cnt = 0



try:
    while True:
        
        # Affichage par défaut
        AFF("SLAVE!!!!")
        
        # Envoi de données
        tx_data = [0x01, 0x02, 0x03]  # Exemple de données à envoyer
        rx_data = spi.xfer2(tx_data)
        
        
        # Lire l'état du bouton
        etat_bouton = GPIO.input(bouton_pin)
        
        # Conversion ASCII en char
        convertie = conversion(rx_data)
        
        
        AFF(convertie)          # Affiche la conversion du message SPI
        AFF_BTN(etat_bouton)    # Affiche l'état du BTN
        
        # Delay de 100ms
        time.sleep(0.1)
        
        # Après un compte de 300 (environ 5 min dans ce code), le programme se ferme.
        if cnt == 300:
            spi.close()     # Ferme le bus SPI
            GPIO.cleanup()  # Nettoyer les configurations GPIO avant de quitter le script
            exit(1)         # Quitte le programme
        
        # Incrémentation du compteur
        cnt = cnt + 1
        
        
except KeyboardInterrupt:
    spi.close()     # Ferme le bus SPI
    GPIO.cleanup()  # Nettoyer les configurations GPIO avant de quitter le script
    print("Communication SPI interrompue.")
