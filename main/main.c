#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "driver/gpio.h"


void print_student(void * pvParameters ){
	for(;;){
		printf("2014722\n");
//		vTaskDelay(pdMS_TO_TICKS( 1000 ));
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
	 vTaskDelete ( NULL );
}

void app_main(void)
{
	 xTaskCreate(print_student,"print_student", 1024, NULL , 5, NULL);
	 while(1){
		 printf("Hello\n");
//		 vTaskDelay(pdMS_TO_TICKS( 1000 ));
		 vTaskDelay(1000/portTICK_PERIOD_MS);
	 }
	 vTaskStartScheduler();
	 for( ;; );
}
