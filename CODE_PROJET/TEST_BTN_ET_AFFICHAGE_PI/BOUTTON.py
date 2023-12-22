#!/usr/bin/env python3


"""
Programme : BOUTTON.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     BOUTTON.py est le programme test pour lire un bouton avec le Pi et il utilise la librairie Turtle pour l'affichage.
            Le bouton, qui est sur le GPIO 17, est lu à chaque 100 ms. Si le GPIO est à un niveau bas (le bouton est pressé),
            le fond devient vert et il est écrit "BTN_ENFONCÉ!!!!!". Sinon, le fond est rouge et il est écrit "BTN_PAS_ENFONCÉ!!!!!"
            avant de bloquer pendant une seconde dans les deux cas. Il y a un compteur pour que le programme se ferme automatiquement.
            Ce compteur compte jusqu'à cent. Ce qui donne dix secondes.
"""




import RPi.GPIO as GPIO     # Pour les GPIO
import time                 # Pour la fonction sleep (delay)

# Importation de la librairie Turtle
import turtle
from turtle import *


# Création de la fenêtre Turtle
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




"""
Brief : Fonction pour changer l'affichage selon l'état du bouton.
Param. : btn, soit l'état du GPIO 17 (HIGH ou LOW)
Retourne : Rien
"""
def AFF(btn):
    
    """
    Si le BTN est pressé (GPIO 17 LOW), l'arrière
    plan devient vert et il est écrit "BTN_ENFONCÉ!!!!!".
    Sinon, l'arrière-plan est rouge et il est écrit
    "BTN_PAS_ENFONCÉ!!!!!".
    """  
    if btn == GPIO.LOW:
        wn.bgcolor("light green")
        turtle.clear()
        write("BTN_ENFONCÉ!!!!!")
    else:
        wn.bgcolor("red")
        turtle.clear()
        write("BTN_PAS_ENFONCÉ!!!!!")
    
    # Attendre un certain temps
    time.sleep(1)


# Pour le compteur (FALCULTATIF)
cnt = 0



# Boucle principale.
while True:
    
    # Lire l'état du bouton
    etat_bouton = GPIO.input(bouton_pin)
    
    # Change l'affichage selon la variable
    # etat_bouton.
    AFF(etat_bouton)
    
    # Attendre un court laps de temps pour éviter la surcharge du processeur
    time.sleep(0.1)
    
    cnt = cnt + 1   # Incrémentation du compteur
    
    # Si le compteur est égal à cent (a.k.a 10 secondes de passé)
    # le programme se ferme.
    if cnt == 100:
        GPIO.cleanup()  # Nettoyer les configurations GPIO avant de quitter le script
        exit(1)         # Quitte le programme