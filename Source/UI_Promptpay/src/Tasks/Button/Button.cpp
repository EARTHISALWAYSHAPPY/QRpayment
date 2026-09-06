#include "Button.h"
#include <Arduino.h>

#include <UI/Init.h>
#include <UI/Promptpay.h>

#include <TFT_eSPI.h>


extern TFT_eSPI tft;

#define BUTTON_PIN 0

void qr_button_task(void *pvParameters)
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    while (1)
    {
        if (digitalRead(BUTTON_PIN) == LOW)
        {

            tft.pushImage(0, 0, 320, 240, UI);

            vTaskDelay(pdMS_TO_TICKS(20000));

            tft.pushImage(0, 0, 320, 240, UI_init);
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}