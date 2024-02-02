/*
Programme : main.c
Auteur :    Marc-Étienne Gendron-Fontaine
Brief :     Ce programme, qui est fait avec le framework Espressif32, doit envoyer
            les chiffres 1 à 6 en SPI. Le Pi devrait être celui qui les reçoit. Le
            ESP32-C3 est le master.
*/



// Sectoin des include
#include <driver/spi_common.h>
#include "driver/spi_master.h"
#include <string.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>



// Configurer les broches SPI
#define PIN_NUM_MISO 5
#define PIN_NUM_MOSI 6
#define PIN_NUM_CLK  4
#define PIN_NUM_CS   7



// Prototype des fonctions
void init_spi();
void test();

spi_device_handle_t handle; // Déclaration de ce qui sera le périphérique (le Pi)


void app_main()
{
    init_spi();
    
    while(1)
    {
      
      //printf("OK");
      
      // Données à envoyer
      uint8_t data[6] = {'1','2','3','4','5','6'};
      //char data[50] = {"SALUTATION_PI!!!"};

      // Configuration de la transaction SPI
      spi_transaction_t t;
      memset(&t, 0, sizeof(t));
      t.length = 8 * sizeof(data);  // 8 bits par octet

      //t.length = 8 * sizeof(data);  // 8 bits par octet
      t.tx_buffer = data;

      //spi_device_polling_transmit(handle, &t);


      // Transmettre les données
      esp_err_t ret = spi_device_transmit(handle, &t);
      
      if(ret == ESP_OK)
        printf("ESP_OK");
      else if(ret == ESP_ERR_INVALID_ARG)
        printf("INVALIDE_ARG");
      

      // Pause d'une seconde
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}



/*
Brief : Initialisation du bus SPI.
Param. : Aucun
Retourne : Rien
*/
void init_spi()
{
  
  // Initialise l'objet pour le bus SPI
  spi_bus_config_t buscfg = {
    .miso_io_num = PIN_NUM_MISO,
    .mosi_io_num = PIN_NUM_MOSI,
    .sclk_io_num = PIN_NUM_CLK,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = 6  // Taille maximale de la transmission en octets
  };

  // Initialise l'objet pour le périphérique (le Pi)
  spi_device_interface_config_t devcfg = {
    .clock_speed_hz = 2*1000*1000,           // Clock à 2 MHz
    .mode = 0,                               // Mode 0
    .spics_io_num = PIN_NUM_CS,               // Broche de sélection du périphérique esclave
    .queue_size = 7,                         // La taille de la file d'attente du pilote (peut être ajustée)
  };



  esp_err_t ret;



  // Initialiser le bus SPI
  ret = spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);
  
  // Regarde s'il y a des erreurs
  if(ret == ESP_OK)
    printf("OK");
  else if(ret == ESP_ERR_INVALID_ARG)
    printf("INVALIDE ARGUMENT");
  else if(ret == ESP_ERR_INVALID_STATE)
    printf("INVALID STATE");
  else if(ret == ESP_ERR_NOT_FOUND)
    printf("PAS DE CS DE LIBRE");
  else if(ret == ESP_ERR_NO_MEM)
    printf("PLUS DE MÉMOIRE");
  


  // Ajouter le périphérique SPI au bus
  ret = spi_bus_add_device(SPI2_HOST, &devcfg, &handle);
  
  // Regarde s'il y a des erreurs
  if(ret == ESP_OK)
    printf("OK");
  else if(ret == ESP_ERR_INVALID_ARG)
    printf("INVALIDE ARGUMENT");
  else if(ret == ESP_ERR_INVALID_STATE)
    printf("INVALID STATE");
  else if(ret == ESP_ERR_NOT_FOUND)
    printf("PAS DE CS DE LIBRE");
  else if(ret == ESP_ERR_NO_MEM)
    printf("PLUS DE MÉMOIRE");
}


/*
Brief : Affiche "OK" dans le terminal. Utile pour savoir quelle
        étape de l'initialisation passe sans problème.
Param. : Aucun
Retourne : Rien
*/
void test()
{
  while(1)
    printf("OK");
}
