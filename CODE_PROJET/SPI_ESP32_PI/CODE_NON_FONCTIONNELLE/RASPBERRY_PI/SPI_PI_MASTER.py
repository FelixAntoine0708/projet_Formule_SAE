#!/usr/bin/env python3


import time
import spidev


bus = 0     # BUS SPI


device = 1  # CS0


spi = spidev.SpiDev()   # Enable SPI

spi.open(bus, device)   # ON OUVRE LA CONNECTION SPI SUR LE BUS 0 ET LE CS0 (CE0)

# VITESSE SPI DE 500Kbs ET MODE 0
spi.max_speed_hz = 500000
spi.mode = 0
spi.bits_per_word = 8
spi.cshigh = False
spi.lsbfirst = False
spi.threewire = False





try:
    while True:
        spi.writebytes([0xAA])
        print("MESSAGE_ENVOYE!!!")
        time.sleep(0.1)


finally:
    spi.close() 