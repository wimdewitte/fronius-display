#include "Display.h"

namespace ui {

void DisplayController::begin() {
  // The original project initializes LovyanGFX and display hardware here.
  // This modular wrapper keeps the entry point isolated from the one-file implementation.
  Serial.println("Display controller initialized");
}

void DisplayController::update() {
  // Main render loop is delegated to the display-specific screen modules.
}

void DisplayController::setBrightness(uint8_t pct) {
  (void)pct;
}

void DisplayController::setScreen(ScreenId screen) {
  state_.current = screen;
  state_.redrawRequired = true;
}

ScreenId DisplayController::screen() const {
  return state_.current;
}

}  // namespace ui
