#pragma once

#include <Arduino.h>
#include <WiFi.h>

namespace network {

class WifiManager {
 public:
  bool begin(const String& ssid, const String& password, bool ipFixed = false,
             const String& ip = "", const String& mask = "", const String& gw = "",
             const String& dns = "", uint32_t timeoutMs = 20000);
  bool isConnected() const;
  int rssi() const;
  String localIp() const;
  String ssid() const;
  void disconnect();

 private:
  String ssid_;
  String password_;
};

}  // namespace network
