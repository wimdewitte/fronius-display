#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace ui {

struct FlowMetrics {
  float pv = NAN;
  float load = NAN;
  float grid = NAN;
  float battery = NAN;
  float soc = NAN;
};

class FlowScreen {
 public:
  void begin();
  void render(const FlowMetrics& metrics);
  void update();
};

}  // namespace ui
