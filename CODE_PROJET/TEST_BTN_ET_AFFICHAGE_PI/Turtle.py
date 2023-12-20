#!/usr/bin/env python3

import time     # Pour la fonction sleep (delay)

# Importation de la librairie Turtle
import turtle
from turtle import *


# Création de la fenêtre
wn = turtle.Screen()
wn.bgcolor("red")
wn.title("Turtle")
skk = turtle.Turtle()


# Fonction principale pour l'affichage. Écrit "Hello there!"
# fait un délay de 5 secondes, efface l'affichage. Change
# la couleur de fond en vert, écrit "BOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBO"
# puis, trace une flèche de 100 pixels.
def affichage():
    write("Hello there!")
    time.sleep(5)
    turtle.clear()
    wn.bgcolor("light green")
    write("BOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBO")
    skk.forward(100)

    # Attend que l'utilisateur clic
    # dans la fenêtre pour quitter
    turtle.exitonclick()


# Appel de la fonction d'affichage
affichage()