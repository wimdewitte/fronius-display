#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace app {

struct RuntimeState {
  bool initialized = false;
  uint32_t lastPollMs = 0;
  uint32_t lastTouchMs = 0;
};

class Application {
 public:
  void setup();
  void loop();
  void begin();
  void stop();
  RuntimeState& state();

 private:
  RuntimeState state_;
};

}  // namespace app
