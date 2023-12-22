#!/usr/bin/env python3

"""
Programme : Turtle.py
Auteur :    Marc-Étienne Gendron-Fontaine
Date :      22 décembre 2023
Brief :     Turtle.py est le programme d'exploration de la librairie Turtle. Il consiste à créer une fenêtre avec un fond rouge.
            Le programme écrit "Hello there!" puis bloque pendant 5 secondes. Le fond devient alors vert et il est écrit "BOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBO".
            Une flèche d'une longueur de cent pixels se dessine en dessous du message. Ne fait plus rien jusqu'à se que l'utilisateur clic dans la fenêtre
            pour fermer le programme.
"""




# Pour la fonction sleep (delay)
import time

# Importation de la librairie Turtle
import turtle
from turtle import *


# Création de la fenêtre
wn = turtle.Screen()
wn.bgcolor("red")
wn.title("Turtle")
skk = turtle.Turtle()


"""
Brief : Fonction principale pour l'affichage. Écrit "Hello there!"
        fait un délai de 5 secondes, efface l'affichage. Change
        la couleur de fond en vert, écris "BOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBO"
        puis trace une flèche de 100 pixels.
Param. : Rien
Retourne : Rien
"""
def affichage():
    write("Hello there!")
    time.sleep(5)
    turtle.clear()
    wn.bgcolor("light green")
    write("BOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBO")
    skk.forward(100)

    # Attends que l'utilisateur clique dans la fenêtre pour quitter
    turtle.exitonclick()



# Appel de la fonction d'affichage.
affichage()