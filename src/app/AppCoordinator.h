#pragma once

#include <Arduino.h>
#include "../config/Settings.h"
#include "../network/WifiManager.h"
#include "../network/UpdateManager.h"
#include "../ui/Display.h"

namespace app {

class AppCoordinator {
 public:
  void begin();
  void loop();
  void connectWifi();
  void refreshUi();
  bool runPollCycle();

 private:
  config::Settings settings_;
  network::WifiManager wifi_;
  network::UpdateManager updates_;
  ui::DisplayController display_;
  bool initialized_ = false;
};

extern AppCoordinator gApp;

}  // namespace app
