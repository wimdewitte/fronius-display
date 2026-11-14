#include "WifiManager.h"

namespace network {

bool WifiManager::begin(const String& ssid, const String& password, bool ipFixed,
                       const String& ip, const String& mask, const String& gw,
                       const String& dns, uint32_t timeoutMs) {
  ssid_ = ssid;
  password_ = password;

  WiFi.disconnect();
  delay(100);

  if (ipFixed) {
    IPAddress ipa, ipMask, ipGw, ipDns;
    if (ipa.fromString(ip) && ipMask.fromString(mask) && ipGw.fromString(gw)) {
      if (!ipDns.fromString(dns)) ipDns = ipGw;
      WiFi.config(ipa, ipGw, ipMask, ipDns);
    }
  }

  WiFi.begin(ssid_.c_str(), password_.c_str());
  uint32_t t0 = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - t0 < timeoutMs) {
    delay(250);
  }

  return WiFi.status() == WL_CONNECTED;
}

bool WifiManager::isConnected() const {
  return WiFi.status() == WL_CONNECTED;
}

int WifiManager::rssi() const {
  return WiFi.status() == WL_CONNECTED ? WiFi.RSSI() : -999;
}

String WifiManager::localIp() const {
  return WiFi.localIP().toString();
}

String WifiManager::ssid() const {
  return WiFi.SSID();
}

void WifiManager::disconnect() {
  WiFi.disconnect();
}

}  // namespace network
