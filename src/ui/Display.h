#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace ui {

enum class ScreenId : uint8_t {
  Flow,
  Detail,
  Settings,
  Error
};

struct ScreenState {
  ScreenId current = ScreenId::Flow;
  uint32_t lastInteractionMs = 0;
  bool redrawRequired = true;
  bool dimmed = false;
};

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
