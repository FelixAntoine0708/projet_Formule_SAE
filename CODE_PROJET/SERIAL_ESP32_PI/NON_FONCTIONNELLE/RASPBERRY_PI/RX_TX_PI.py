#!/usr/bin/env python3


import serial
import turtle
from turtle import *
import time


ser = serial.Serial('/dev/ttyAMA0', 9600)  # Assurez-vous que le port série est correct


wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()



def AFF(data):
    turtle.clear()
    write(data)


AFF("HELLO_WORLD!!!!!")


while True:
    
    

    if ser.in_waiting > 0:
        received_data = ser.readline().decode('utf-8').rstrip()
        #print("Données reçues du ESP32-C3:", received_data)
        msg = "Données reçues du ESP32-C3:" + received_data
        AFF(msg)

    # Attendre un certain temps
    time.sleep(0.1)    