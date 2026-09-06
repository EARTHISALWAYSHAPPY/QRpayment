#include "Screen.h"
#include <TFT_eSPI.h>

#include <UI/Init.h>

extern TFT_eSPI tft;

void tft_setup_task(void *pvParameters)
{
    // Serial.begin(115200);
    tft.init();
    tft.setRotation(3);
    tft.setSwapBytes(true);
    tft.invertDisplay(true);
    Serial.println("Image Displayed!");
    tft.pushImage(0, 0, 320, 240, UI_init);
    vTaskDelete(NULL);
}