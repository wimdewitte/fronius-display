#include "Touch.h"

namespace ui {

bool TouchController::poll(TouchPoint& point) const {
  (void)point;
  // Placeholder: delegate to LovyanGFX touch driver here.
  return false;
}

void TouchController::setTapDeadZone(int dx, int dy) {
  deadZoneX_ = dx;
  deadZoneY_ = dy;
}

}  // namespace ui
