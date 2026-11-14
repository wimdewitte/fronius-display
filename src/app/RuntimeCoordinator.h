#pragma once

#include <Arduino.h>

namespace app {

class RuntimeCoordinator {
 public:
  void setup();
  void loop();
  void updateTimers();
  void requestRedraw();

 private:
  bool redrawRequested_ = true;
  uint32_t lastUiTickMs_ = 0;
};

}  // namespace app
