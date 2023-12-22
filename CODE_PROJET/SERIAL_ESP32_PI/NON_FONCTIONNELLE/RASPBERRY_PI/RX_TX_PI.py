#!/usr/bin/env python3

'''
Auter : Marc-Étienne Gendron-Fontaine
Date :  22 décembre 2023
@Breif:
Ce code était un test de serial Rx, Tx vers le ESP32.
C'était une idée Back-up au cas ou le SPI du Raspberry Pi
ne fonctionnait pas. 
'''

#include 
import serial
import turtle
from turtle import *
import time


ser = serial.Serial('/dev/ttyAMA0', 9600)  # Assurez-vous que le port série est correct

# initialisation Turtle pour écrire sur l'écran
wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()


'''
@Breif:
fonction qui affiche sur l'écran
'''
def AFF(data):
    turtle.clear()
    write(data)


AFF("HELLO_WORLD!!!!!") # affiche sur l'écran


while True: # boucle infinit

    if ser.in_waiting > 0:  #si le délaie d'attente était plus grand que 0  
        received_data = ser.readline().decode('utf-8').rstrip() # lecture et décode des données reçu
        msg = "Données reçues du ESP32-C3:" + received_data # variable du message
        AFF(msg)    # affiche le message

    # Attendre un certain temps
    time.sleep(0.1)    