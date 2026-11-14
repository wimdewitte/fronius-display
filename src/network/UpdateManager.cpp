#include "UpdateManager.h"

namespace network {

bool UpdateManager::checkForUpdate() {
  if (WiFi.status() != WL_CONNECTED) {
    info_.error = "kein WLAN";
    return false;
  }

  info_.version = "";
  info_.url = "";
  info_.error = "";
  Serial.println("UpdateManager: placeholder check");
  return true;
}

bool UpdateManager::installIfAvailable() {
  if (info_.url.length() == 0) {
    return false;
  }
  Serial.println("UpdateManager: placeholder OTA installation");
  return true;
}

UpdateInfo UpdateManager::info() const {
  return info_;
}

}  // namespace network
