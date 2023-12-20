#!/usr/bin/env python3


#import turtle
#from turtle import *

import can
import time

def can_receive():
    # Initialiser le bus CAN
    bus = can.interface.Bus(channel='can0', bustype='socketcan')

    print("Attente de messages CAN...")

    while True:
        try:
            message = bus.recv(timeout=1.0)
            if message:
                print("ID: 0x{:x} DLC: {} Data: {}".format(message.arbitration_id, message.dlc, message.data))
        except KeyboardInterrupt:
            break

if __name__ == "__main__":
    can_receive()
