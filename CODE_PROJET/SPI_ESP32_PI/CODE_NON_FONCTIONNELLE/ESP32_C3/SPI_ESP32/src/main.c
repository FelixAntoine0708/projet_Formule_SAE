/*

CE PROGRAMME FAIT AVEC LE FRAMEWORK ESPRESSIF32 DEVAIT ENVOYER LES CHIFFRES DE 1 À 6
EN SPI. TOUJOURS DES PROBLÈMES DANS LA CONFIGURATION DU SPI.


*/




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

void init_spi();
void test();

spi_device_handle_t handle;

/*void setup()
{
  //Serial.begin(115200);

    spi_device_handle_t handle;
    esp_err_t ret;


  spi_bus_config_t buscfg = {
    .miso_io_num = PIN_NUM_MISO,
    .mosi_io_num = PIN_NUM_MOSI,
    .sclk_io_num = PIN_NUM_CLK,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = 6  // Taille maximale de la transmission en octets
  };


    //ret = spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);
    //ESP_ERROR_CHECK(ret);


  spi_device_interface_config_t devcfg = {
    .clock_speed_hz = 1*1000*1000,           // Clock à 1 MHz
    .mode = 0,                               // Mode 0
    .spics_io_num = PIN_NUM_CS,               // Broche de sélection du périphérique esclave
    .queue_size = 7,                         // La taille de la file d'attente du pilote (peut être ajustée)
  };


  


  // Initialiser le bus SPI
  ret = spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);
  assert(ret == ESP_OK);

  // Ajouter le périphérique SPI au bus
  ret = spi_bus_add_device(SPI2_HOST, &devcfg, &handle);
  
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
  
  while(1)
  {
    printf("OK");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
    
  //assert(ret == ESP_OK);
}*/



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
      
      //assert(ret == ESP_OK);

       // Pause d'une seconde
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}




void init_spi()
{
  spi_bus_config_t buscfg = {
    .miso_io_num = PIN_NUM_MISO,
    .mosi_io_num = PIN_NUM_MOSI,
    .sclk_io_num = PIN_NUM_CLK,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = 6  // Taille maximale de la transmission en octets
  };


  spi_device_interface_config_t devcfg = {
    .clock_speed_hz = 2*1000*1000,           // Clock à 2 MHz
    .mode = 0,                               // Mode 0
    .spics_io_num = PIN_NUM_CS,               // Broche de sélection du périphérique esclave
    .queue_size = 7,                         // La taille de la file d'attente du pilote (peut être ajustée)
  };



  esp_err_t ret;



    // Initialiser le bus SPI
  ret = spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);
  
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
  
  
  
  //assert(ret == ESP_OK);

  // Ajouter le périphérique SPI au bus
  ret = spi_bus_add_device(SPI2_HOST, &devcfg, &handle);
  
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



void test()
{
  while(1)
  {
    printf("OK");
    //vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
