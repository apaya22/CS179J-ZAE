#ifndef HOME_CONFIG_H
#define HOME_CONFIG_H

#include <Arduino.h>

// ========================
// DISPLAY CONFIGUARTION
// ========================
static const uint8_t TFT_ROT = 0;
static const uint8_t TS_ROT  = 0;
static const int SCREEN_W = 240;
static const int SCREEN_H = 320;

// =====================
// DISPLAY PIN CONFIGURATION
// =====================
#define TFT_CS    4
#define TFT_DC    15
#define TFT_RST   9
#define SCLK_PIN  12
#define MOSI_PIN  11
#define MISO_PIN  13

// ====================================
// GAMEPAD PIN CONFIGURATION (TODO:)
// ====================================

// =====================
// WIFI SETTINGS (TODO:)
// =====================


// =====================
// UI STATES
// =====================
enum UIState {
  STATE_HOME = 0
};

// =====================
// UI THEME - COLORS
// =====================
#define GAMEPOD_GREY   0xD6BA
#define GAMEPOD_BLUE   0x033F
#define GAMEPOD_DARK   0x2104
#define GAMEPOD_WHITE  0xFFFF
#define GAMEPOD_RED    0xF800
#define DARK_BG        0x0000
#define DARK_TEXT      0xFFFF

// =====================
// GAME LIST (TODO:)
// =====================


#endif // HOME_CONFIG_H