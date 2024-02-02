
#include "driver/gpio.h"
#include "driver/twai.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {

    //Initialize configuration structures using macro initializers
    twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_4, GPIO_NUM_5, TWAI_MODE_NORMAL);
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
    while(1)
    {
        vTaskDelay(pdMS_TO_TICKS(2000));

        //Configure message to transmit
        twai_message_t message;
        message.identifier = 0xAA;
        message.rtr = 0;
        message.data_length_code = 8;
        message.data[0] = 'H';
        message.data[1] = 'E';
        message.data[2] = 'L';
        message.data[3] = 'L';
        message.data[4] = 'O';
        message.data[5] = ' ';
        message.data[6] = '1';
        message.data[7] = '5';

        //Queue message for transmission
        if (twai_transmit(&message, pdMS_TO_TICKS(1000)) == ESP_OK) {
            printf("Message queued for transmission\n");
        } else {
            printf("Failed to queue message for transmission\n");
        }
    }
}