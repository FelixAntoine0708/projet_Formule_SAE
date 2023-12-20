//#include "hal/spi_types.h"
#include <driver/spi_common.h>
#include "driver/gpio.h"
#include "driver/twai.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void configuration();
void reception();
void transmission();





void app_main()
{
    configuration();
    //setup();
    
    //while(1)
        //reception();


    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(2000));

        //Configure message to transmit
        twai_message_t message;
        message.identifier = 0xAA;
        message.rtr = 0;
        message.data_length_code = 8;
        message.data[0] = 'F';
        message.data[1] = 'I';
        message.data[2] = 'N';
        message.data[3] = 'A';
        message.data[4] = 'L';
        message.data[5] = 'L';
        message.data[6] = 'Y';
        message.data[7] = '!';

        //Queue message for transmission
        if (twai_transmit(&message, pdMS_TO_TICKS(1000)) == ESP_OK) {
            printf("Message queued for transmission\n");
        } else {
            printf("Failed to queue message for transmission\n");
        }
    }

}



void reception()
{
    twai_message_t message;
    
    int flag;
    
    flag = twai_receive(&message, pdMS_TO_TICKS(10000));
    
    //Wait for message to be received
    
    if (flag == ESP_OK)
        printf("Message received\n");
    else if (flag == ESP_ERR_TIMEOUT)
    {
        printf("TIME_OUT!!!!!\n");
        return;
    }
    else if(flag == ESP_ERR_INVALID_ARG)
    {
        printf("ARG_INVALIDE!!!!!\n");
        return;
    }
    else if(flag == ESP_ERR_INVALID_STATE)
    {
        printf("ETAT_INVALIDE!!!!!\n");
        return;
    }
    else
    {
        printf("Failed to receive message\n");
        return;
    }



    //Process received message
    if (message.extd) {
        printf("Message is in Extended Format\n");
    } else {
        printf("Message is in Standard Format\n");
    }
    printf("ID is %lu\n", message.identifier);
    
    for (int i = 0; i < message.data_length_code; i++)
        printf("%c\n", (char)message.data[i]);
    
    

}





void configuration()
{
        //Initialize configuration structures using macro initializers
    twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_9, GPIO_NUM_8, TWAI_MODE_NORMAL);
    twai_timing_config_t t_config = TWAI_TIMING_CONFIG_500KBITS();
    twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

    //Install TWAI driver
    if (twai_driver_install(&g_config, &t_config, &f_config) == ESP_OK) {
        printf("Driver installed\n");
    } else {
        printf("Failed to install driver\n");
        return;
    }

    //Start TWAI driver
    if (twai_start() == ESP_OK) {
        printf("Driver started\n");
    } else {
        printf("Failed to start driver\n");
        return;
    }

}





void transmission()
{
    //Configure message to transmit
    twai_message_t tx_message;
    tx_message.identifier = 0xAAAA;   // ID
    tx_message.extd = 1;            // ID sur 29 bits
    //tx_message.ss = 0;              
    //tx_message.self = 0;            // N'est pas Self Reception Request
    tx_message.data_length_code = 1;    // Longeur champ de donnée (1 octect)
    tx_message.data[0] = 0xBB;      // Donnée envoyer (oxBB)
    tx_message.rtr = 0;

    //for (int i = 0; i < 4; i++)
        //message.data[i] = 0;

    //Queue message for transmission
    if (twai_transmit(&tx_message, pdMS_TO_TICKS(1000)) == ESP_OK)
        printf("Message queued for transmission\n");
    else if(twai_transmit(&tx_message, pdMS_TO_TICKS(1000)) == ESP_ERR_INVALID_ARG)
        printf("INVALIDE_ARG!!!!!\n");
    else if(twai_transmit(&tx_message, pdMS_TO_TICKS(1000)) == ESP_ERR_TIMEOUT)
        printf("Failed to queue message for transmission\n");
    else if(twai_transmit(&tx_message, pdMS_TO_TICKS(1000)) == ESP_FAIL)
        printf("TX_DISABLE!!!!!!!\n");
    else if(twai_transmit(&tx_message, pdMS_TO_TICKS(1000)) == ESP_ERR_INVALID_STATE)
        printf("INVALIDE_STATE!!!!!\n");
    else if(twai_transmit(&tx_message, pdMS_TO_TICKS(1000)) == ESP_ERR_NOT_SUPPORTED)
        printf("MODE_ECOUTE_SEULEMENT!!!!!\n");
    else
        printf("Failed to queue message for transmission\n");

}





