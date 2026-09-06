#include <Arduino.h>
#include <TFT_eSPI.h>

#include "tasks/ScreenSetup/Screen.h"
#include "tasks/Button/Button.h"

/**
 * ============================================================
 *  QRpayment — ESP32 + TFT PromptPay Payment Display
 * ============================================================
 *  Version      : v0.1 (First Release)
 *  Release Date : 2026-09-06
 *  Author       : EARTHISALWAYSHAPPY
 *
 *  Description:
 *  Initial release of the QRpayment firmware. This version
 *  brings up the core building blocks of the device — TFT
 *  screen setup, button input handling, and the PromptPay QR
 *  code UI — running on an ESP32 with an ILI9341 display.
 *
 *  Changelog (v0.1):
 *   - Initial project structure (Tasks/Button, Tasks/ScreenSetup, UI)
 *   - TFT screen initialization (Screen.cpp / Screen.h)
 *   - Basic button input handling (Button.cpp / Button.h)
 *   - UI initialization routine (UI/Init.h)
 *   - PromptPay QR code display on screen (UI/Promptpay.h)
 *
 *  Known Limitations:
 *   - Payment amount is currently static (not yet configurable)
 *   - No transaction logging / database support yet
 * ============================================================
 */

TFT_eSPI tft = TFT_eSPI(); 

void setup() {
    // Serial.begin(115200);
    
    xTaskCreate(tft_setup_task, "TFT_Setup", 2048, NULL, 2, NULL);
    
    xTaskCreate(qr_button_task, "QR_Button", 4096, NULL, 1, NULL);
}

void loop() {
    
}