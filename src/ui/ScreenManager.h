#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace ui {

enum class ScreenId : uint8_t {
  Flow,
  Detail,
  Settings,
  Error,
};

struct ScreenState {
  ScreenId current = ScreenId::Flow;
  uint32_t lastInteractionMs = 0;
  bool redrawRequired = true;
  bool dimmed = false;
};

class ScreenManager {
 public:
  void activate(ScreenId screen);
  ScreenId active() const;
  void markDirty();
  bool needsRedraw() const;

 private:
  ScreenState state_;
};

}  // namespace ui
