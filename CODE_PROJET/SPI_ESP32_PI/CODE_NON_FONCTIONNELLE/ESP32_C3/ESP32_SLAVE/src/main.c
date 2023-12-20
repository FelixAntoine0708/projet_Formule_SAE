/*

CE PROGRAMME NON-FONCTIONNELLE FAIT AVEC LE FRAMEWORK ESPRESSIF32 DEVAIT RECEVOIRE
DES DONNÉES EN SPI. IL Y A DES PROBLÈMES DANS LA CONFIGURATION DU SPI.


*/


#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"

#define PIN_NUM_MISO 5
#define PIN_NUM_MOSI 6
#define PIN_NUM_CLK  4
#define PIN_NUM_CS   7





void app_main(void)
{
    spi_device_handle_t spi;
    spi_bus_config_t bus_config = {
        .miso_io_num = PIN_NUM_MISO,
        .mosi_io_num = PIN_NUM_MOSI,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1
    };

    spi_device_interface_config_t dev_config = {
        .mode = 0,
        .clock_speed_hz = 1000000,
        .spics_io_num = PIN_NUM_CS,
        .queue_size = 1
    };

    // Initialisation du bus SPI
    spi_bus_initialize(SPI2_HOST, &bus_config, SPI_DMA_CH_AUTO);

    // Ajout du périphérique SPI
    spi_bus_add_device(SPI2_HOST, &dev_config, &spi);

    while (1) {
        // Attente de la réception de données
        spi_transaction_t t = {
            .length = 24,  // Longueur des données à recevoir en bits
        };
        spi_device_polling_transmit(spi, &t);  // Effectuez la transaction SPI

        // Traitement des données reçues
        printf("Données reçues: %x\n", t.rx_data[0]);

        vTaskDelay(1000 / portTICK_PERIOD_MS);  // Attendez 1 seconde
    }
}
