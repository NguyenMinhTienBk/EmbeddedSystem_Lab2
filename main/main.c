#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUTTON_GPIO GPIO_NUM_17

bool button_pressed = false;

void button_task(void *pvParameters) {
    gpio_pad_select_gpio(BUTTON_GPIO);
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BUTTON_GPIO, GPIO_PULLUP_ONLY);

    while (1) {
        int button_state = gpio_get_level(BUTTON_GPIO);

        if (button_state == 0 && !button_pressed) {
			printf("ESP32\n");
			button_pressed = true; // Đánh dấu nút đã được nhấn
		}
		else if (button_state == 1 && button_pressed) {
			button_pressed = false; // Đánh dấu nút đã được thả ra
		}
        vTaskDelay(10 / portTICK_PERIOD_MS); // Đợi một khoảng thời gian ngắn trước khi đọc trạng thái nút bấm lại
    }
}

void print_student(void * pvParameters ){
	for(;;){
		printf("2014722");
//		vTaskDelay(pdMS_TO_TICKS( 1000 ));
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
	 vTaskDelete ( NULL );
}

void app_main(void)
{
	 xTaskCreate(print_student,"print_student", 1024, NULL , 5, NULL);
	 xTaskCreate(button_task, "button_task", 1024, NULL, 2, NULL);
//	 while(1){
//		 vTaskDelay(1000/portTICK_PERIOD_MS);
//	 }
//	 vTaskStartScheduler();
}
