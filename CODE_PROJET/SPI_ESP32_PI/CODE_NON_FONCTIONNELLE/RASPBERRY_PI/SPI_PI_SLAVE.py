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



# CONVERTI LES BYTES EN HEXA
def BytesToHex(Bytes):
      return ''.join(["0x%02X " % x for x in Bytes]).strip()


test = spi.xfer([0xBB])



try:
    while True:
            msg = spi.xfer([0xBB])  #spi.readbytes(1) #spi.readbytes(1)  # VA LIRE 1 OCTETS SUR LE BUS
            hexa =  msg
            print(msg)
            time.sleep(0.1)     # DELAY DE 100MS


finally:
      spi.close()   # ON FERME LE BUS SPI