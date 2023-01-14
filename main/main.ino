#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"


void app_main(){
  nvs_flash_init();
  xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL);
}

void setup()
{
  app_main();
}

void loop()
{  
}


void hello_task(void *pvParameter)
{
}