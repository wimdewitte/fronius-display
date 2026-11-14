#include "RuntimeCoordinator.h"

namespace app {

void RuntimeCoordinator::setup() {
  redrawRequested_ = true;
  lastUiTickMs_ = millis();
}

void RuntimeCoordinator::loop() {
  // Placeholder: call poll/update functions in the same order as the original main loop.
}

void RuntimeCoordinator::updateTimers() {
  // Placeholder: timer-based logic for display refresh, updates, and sleep/dim state.
}

void RuntimeCoordinator::requestRedraw() {
  redrawRequested_ = true;
}

}  // namespace app
