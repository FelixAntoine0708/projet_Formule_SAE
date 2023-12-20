#!/usr/bin/env python3

import can
import time

import turtle
from turtle import *


wn = turtle.Screen()
wn.bgcolor("light green")
wn.title("Turtle")
skk = turtle.Turtle()

# Initialiser le bus CAN
bus = can.interface.Bus(channel='can0', bustype='socketcan')



def AFF(msg):
    skk.clear()
    skk.write(msg)
    time.sleep(1)


def can_receive():
    while True:
        try:
            
            AFF("Attente de messages CAN...")


            message = bus.recv(timeout=1.0)
            if message:
                AFF("ID: 0x{:x} DLC: {} Data: {}".format(message.arbitration_id, message.dlc, message.data))

        except KeyboardInterrupt:
            break


if __name__ == "__main__":
    can_receive()
