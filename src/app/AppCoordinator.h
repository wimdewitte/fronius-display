#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace app {

struct RuntimeState {
  bool initialized = false;
  uint32_t lastPollMs = 0;
  uint32_t lastTouchMs = 0;
};

class AppCoordinator {
 public:
  void begin();
  void loop();
  void refresh();
  RuntimeState& state();

 private:
  RuntimeState runtime_;
};

extern AppCoordinator gApp;

}  // namespace app
