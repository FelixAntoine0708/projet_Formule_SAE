#include "driver/gpio.h"
#include "driver/twai.h"


#define DELAY 1000000 // 1000ms


void configuration();
void transmission();
void reception();
void stop();
void erreur();


void app_main()
{
    
    // Configuration et installation--------------------------------------------------------------------------------------
    configuration();
    
    //esp_rom_delay_us(DELAY);

    // Transmission de messages --------------------------------------------------------


    while (1)
    {
        transmission();
        //esp_rom_delay_us(DELAY);
    }
    
    
    //
    //
        
    
    //esp_rom_delay_us(DELAY);


    // ERREUR -----------------------------------------------
    //erreur();



    // Réception du message ---------------------------------------------------------------
    //reception();

    //esp_rom_delay_us(DELAY);


    


    // Arrêtez-vous et désinstallez ------------------------------------------------------
    stop();

    
}



void configuration()
{
        //Initialize configuration structures using macro initializers
    twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_1, GPIO_NUM_2, TWAI_MODE_NORMAL);
    twai_timing_config_t t_config = TWAI_TIMING_CONFIG_250KBITS();
    twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();        // -------------------------------------------

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




void reception()
{
    twai_message_t message;
    
    int flag;
    
    flag = twai_receive(&message, pdMS_TO_TICKS(0));
    
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
    if (!(message.rtr)) {
        for (int i = 0; i < message.data_length_code; i++) {
            printf("Data byte %d = %d\n", i, message.data[i]);
        }
    }

}



void stop()
{
    //Stop the TWAI driver
    if (twai_stop() == ESP_OK) {
        printf("Driver stopped\n");
    } else {
        printf("Failed to stop driver\n");
        return;
    }

    //Uninstall the TWAI driver
    if (twai_driver_uninstall() == ESP_OK) {
        printf("Driver uninstalled\n");
    } else {
        printf("Failed to uninstall driver\n");
        return;
    }
}




void erreur()
{
    //Reconfigure alerts to detect Error Passive and Bus-Off error states
    uint32_t alerts_to_enable = TWAI_ALERT_ERR_PASS | TWAI_ALERT_BUS_OFF;
    if (twai_reconfigure_alerts(alerts_to_enable, NULL) == ESP_OK) {
        printf("Alerts reconfigured\n");
    } else {
        printf("Failed to reconfigure alerts");
    }

    //Block indefinitely until an alert occurs
    uint32_t alerts_triggered;
    twai_read_alerts(&alerts_triggered, portMAX_DELAY);
}