#pragma once

#include <Arduino.h>

namespace ui {

struct TouchPoint {
  int32_t x = 0;
  int32_t y = 0;
};

class TouchController {
 public:
  bool poll(TouchPoint& point) const;
  void setTapDeadZone(int dx, int dy);

 private:
  int deadZoneX_ = 40;
  int deadZoneY_ = 40;
};

}  // namespace ui
