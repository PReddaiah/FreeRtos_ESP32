#include <stdio.h>
#include "freertos/freertos.h"
#include "freertos/task.h"
#include "esp_log.h"

const char * TAG = "freeRtos_ESP32";

int num = 100;

void vTask_a(void *para){
    while (true)
    {
       ESP_LOGI(TAG,"Hello from task a with %d + subs",*(int *)para);

       vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void)
{
    xTaskCreate(vTask_a,"Task A",3000,(void *)&num,1,NULL);
}
