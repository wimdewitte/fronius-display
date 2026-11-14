#pragma once

#include <Arduino.h>
#include <Preferences.h>

namespace config {

struct Settings {
  String froniusHost = "";
  String wifiSsid = "";
  String wifiPass = "";
  bool ipFixed = false;
  String ipAddr = "";
  String ipMask = "255.255.255.0";
  String ipGw = "";
  String ipDns = "";
  uint32_t pollMs = 5000;
  uint32_t pvMaxW = 0;
  uint32_t battWh = 0;
  bool rot180 = false;
  bool animOn = false;
  uint8_t brightPct = 100;
  bool sleepBlack = false;
  bool nightOn = false;
  uint16_t nightFrom = 22 * 60;
  uint16_t nightTo = 6 * 60;
  uint8_t nightLvl = 0;
  bool gridChg = false;
  uint8_t contrastLvl = 0;
};

class SettingsStore {
 public:
  Settings load();
  bool save(const Settings& settings);
  bool validate(Settings& settings) const;
  void clear();

 private:
  static constexpr const char* kNvsNamespace = "fronidisp";
};

extern SettingsStore gSettings;

}  // namespace config
