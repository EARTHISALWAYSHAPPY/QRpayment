# QRpayment

**ESP32 + TFT : PromptPay QR Payment Display** — *promptpay*

## About This Project

QRpayment is an ESP32-based embedded project that drives a TFT display (ILI9341) to show a **PromptPay QR code** for accepting payments. It's designed for small, mobile, or low-cost point-of-sale scenarios — where a simple standalone device can display a scannable QR code for customers to pay via Thai PromptPay, without needing a phone, POS terminal, or internet-connected payment app running on a smartphone.

The device is built around:
- **ESP32** as the main microcontroller
- An **ILI9341 TFT display** (SPI interface) driven via the **TFT_eSPI** library, used to render the PromptPay QR code (and UI elements) on screen

The repository contains the firmware source code (`Source/UI_Promptpay`) and UI-related assets (`UI`) used to build and render the on-screen interface.

## Hardware Requirements

- ESP32 development board
- ILI9341 TFT LCD display (SPI)
- USB cable for flashing/power

## Library Setup (TFT_eSPI Configuration)

This project relies on the **[TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)** library. Because TFT_eSPI is configured at compile-time via header files, you must set it up correctly before building/flashing the firmware.

### Step 1 — Select the display setup

Open `User_Setup_Select.h` (inside the TFT_eSPI library folder) and **uncomment** the following line:

```cpp
#include <User_Setups/Setup42_ILI9341_ESP32.h>
```

### Step 2 — Configure the display setup file

Open `Setup42_ILI9341_ESP32.h` (inside `User_Setups/`) and replace its contents with the configuration below. This sets up the SPI pins, display driver, color order, fonts, and SPI clock speeds used by this project.

```cpp
// See SetupX_Template.h for all options available
#define USER_SETUP_ID 42

#define ILI9341_2_DRIVER

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 15  // Chip select control pin
#define TFT_DC 2   // Data Command control pin
#define TFT_RST 4  // Reset pin (could connect to RST pin)
//#define TFT_RST -1 // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST

// Optional touch screen chip select
// #define TOUCH_CS 5 // Chip select pin (T_CS) of touch screen

//#define TFT_INVERSION_OFF
#define TFT_RGB_ORDER TFT_BGR

#define LOAD_GLCD  // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2 // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4 // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6 // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7 // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:.
#define LOAD_FONT8 // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
#define LOAD_GFXFF // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SMOOTH_FONT

// TFT SPI clock frequency
// #define SPI_FREQUENCY  20000000
 #define SPI_FREQUENCY 27000000
// #define SPI_FREQUENCY  40000000
//#define SPI_FREQUENCY  80000000

// Optional reduced SPI frequency for reading TFT
#define SPI_READ_FREQUENCY 16000000

// SPI clock frequency for touch controller
#define SPI_TOUCH_FREQUENCY 2500000
```

### Wiring Reference (from the config above)

| TFT Pin | ESP32 GPIO|
|---------|-----------|
| MISO    | 19        |
| MOSI    | 23        |
| SCLK    | 18        |
| CS      | 15        |
| DC      | 2         |
| RST     | 4         |
| TOUCH_CS (optional) | 5 |

> **Note:** Touch screen support is included in the config but commented out by default (`TOUCH_CS`). Uncomment it if your display module has a touch controller you want to use.

## Getting Started

1. Install the **Arduino IDE** (or PlatformIO) with ESP32 board support.
2. Install the **TFT_eSPI** library.
3. Apply the library configuration described above (Steps 1 & 2).
4. Wire the ILI9341 display to the ESP32 according to the pinout table.
5. Open the project source from `Source/UI_Promptpay`, flash it to your ESP32, and power on the device.
6. The display will render the PromptPay QR code, ready for customers to scan and pay.

## Roadmap / Planned Features

- [ ] **Configurable payment amount** — allow the merchant to input/set a specific amount for each transaction, so the generated QR code reflects the exact amount the customer needs to pay (instead of a fixed/static QR code).
- [ ] **Payment database** — add local or cloud-based storage/logging of payment transactions, enabling transaction history tracking and basic reporting.

## Project Structure

```
src/
├── Tasks/
│   ├── Button/
│   │   ├── Button.cpp      # Button input handling logic
│   │   └── Button.h
│   └── ScreenSetup/
│       ├── Screen.cpp      # TFT screen initialization / setup logic
│       └── Screen.h
├── UI/
│   ├── Init.h               # UI initialization
│   └── Promptpay.h          # PromptPay QR code UI / generation logic
└── main.cpp                 # Entry point
```

## License

No license has been specified yet for this project. Please contact the repository owner for usage terms.

