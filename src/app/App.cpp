#include "App.h"

namespace app {

Application gApp;

void Application::setup() {
  state_.initialized = true;
  Serial.println("Application setup");
}

void Application::loop() {
  if (!state_.initialized) {
    setup();
  }
}

void Application::begin() {
  setup();
}

void Application::stop() {
  state_.initialized = false;
}

RuntimeState& Application::state() {
  return state_;
}

}  // namespace app
