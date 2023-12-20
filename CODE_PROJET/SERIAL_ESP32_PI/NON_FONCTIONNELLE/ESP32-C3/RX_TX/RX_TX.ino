#include <HardwareSerial.h>

#define RX_PIN 20 // GPIO pour la réception
#define TX_PIN 21 // GPIO pour la transmission
#define BAUD_RATE 9600 // Vitesse de communication en bauds

HardwareSerial SerialESP32(0); // Utilisez le port matériel 0 sur l'ESP32-C3

void setup() {
  SerialESP32.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);
}

void loop() {
  // Envoyer une chaîne de caractères
  SerialESP32.write("Hello, Raspberry Pi!");

  // Attendre un moment
  delay(1000);
}