#pragma once

#include <Arduino.h>
#include <WiFi.h>

namespace network {

struct UpdateInfo {
  String version;
  String url;
  String error;
};

class UpdateManager {
 public:
  bool checkForUpdate();
  bool installIfAvailable();
  UpdateInfo info() const;

 private:
  UpdateInfo info_;
};

}  // namespace network
