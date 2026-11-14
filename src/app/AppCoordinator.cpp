#include "AppCoordinator.h"

namespace app {

AppCoordinator gApp;

void AppCoordinator::begin() {
  settings_ = config::gSettings.load();
  display_.begin();
  connectWifi();
  initialized_ = true;
}

void AppCoordinator::connectWifi() {
  if (settings_.wifiSsid.length() == 0) return;
  wifi_.begin(settings_.wifiSsid, settings_.wifiPass, settings_.ipFixed,
              settings_.ipAddr, settings_.ipMask, settings_.ipGw, settings_.ipDns,
              20000);
}

void AppCoordinator::refreshUi() {
  display_.update();
}

bool AppCoordinator::runPollCycle() {
  if (!wifi_.isConnected()) return false;
  return true;
}

void AppCoordinator::loop() {
  if (!initialized_) begin();

  if (wifi_.isConnected()) {
    // This is the place where the Fronius polling loop and renderer updates would run.
  }

  refreshUi();
}

}  // namespace app
