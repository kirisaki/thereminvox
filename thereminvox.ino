#include <Seeed_Arduino_FreeRTOS.h>
#include <LovyanGFX.hpp>

static LGFX lcd;
TaskHandle_t Handle_graphicTask;
TaskHandle_t Handle_soundTask;
 
static void graphicThread(void* pvParameters) {
    while(1){
        delay(100);
    }
}
 
static void soundThread(void* pvParameters) {
    while(1) {
        analogWrite(WIO_BUZZER, 128);
        delay(1000);
        analogWrite(WIO_BUZZER, 0);
        delay(1000);
    }
}
 
void setup() {
    lcd.init();
    lcd.setRotation(1);
    lcd.setColorDepth(16);
    lcd.startWrite();
    lcd.fillScreen(TFT_RED);
    pinMode(WIO_BUZZER, OUTPUT);

    xTaskCreate(graphicThread, "Graphic task", 256, NULL, tskIDLE_PRIORITY + 2, &Handle_graphicTask);
    xTaskCreate(soundThread, "Sound task", 256, NULL, tskIDLE_PRIORITY + 1, &Handle_soundTask);
    vTaskStartScheduler();
}
 
void loop() {
}

