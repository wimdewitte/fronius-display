#pragma once

#include <Arduino.h>
#include <stdint.h>

#include "ScreenManager.h"

namespace ui {

class DisplayController {
 public:
  void begin();
  void update();
  void setBrightness(uint8_t pct);
  void setScreen(ScreenId screen);
  ScreenId screen() const;

 private:
  ScreenState state_;
};

}  // namespace ui
