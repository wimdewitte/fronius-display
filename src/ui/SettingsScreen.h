#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace ui {

enum class SettingTab : uint8_t {
  Fronius,
  Wifi,
  Ip,
  Display,
  System,
};

struct SettingsState {
  SettingTab tab = SettingTab::Fronius;
  bool dirty = false;
};

class SettingsScreen {
 public:
  void begin();
  void render(const SettingsState& state);
  void handleTap(int x, int y);
};

}  // namespace ui
