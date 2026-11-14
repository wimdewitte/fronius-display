#include "AppCoordinator.h"

#include "../config/Settings.h"
#include "../network/WifiManager.h"
#include "../ui/ScreenManager.h"

namespace app {

AppCoordinator gApp;

void AppCoordinator::begin() {
  runtime_.initialized = true;
  runtime_.lastPollMs = millis();
  runtime_.lastTouchMs = millis();
}

void AppCoordinator::loop() {
  if (!runtime_.initialized) begin();
  refresh();
}

void AppCoordinator::refresh() {
  // This module is intentionally thin while the rest of the monolith is being extracted.
}

RuntimeState& AppCoordinator::state() {
  return runtime_;
}

}  // namespace app
