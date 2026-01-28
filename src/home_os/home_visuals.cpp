#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

#include "home_config.h"
#include "ui_renderer.h"

// =====================
// GLOBAL VARIABLES
// =====================
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST); // PINS DECLARATION

bool darkModeEnabled = false;

unsigned long lastFrameTime = 0;




// =====================
// SETUP
// =====================
void setup() {
  Serial.begin(115200);

  SPI.begin(SCLK_PIN, MISO_PIN, MOSI_PIN);

  tft.begin();
  tft.setRotation(TFT_ROT);

  renderHome();
}


// =====================
// MAIN LOOP
// =====================
void loop() {
  // Frame rate limiting (~30fps)
  unsigned long now = millis();
  if (now - lastFrameTime < 33) {
    return;
  }
  lastFrameTime = now;
}
