#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace ui {

struct FlowRenderState {
  bool online = false;
  bool wifiConnected = false;
  bool dimmed = false;
  String timeText;
  String statusText;
};

class DisplayRenderer {
 public:
  void begin();
  void renderFlow(const FlowRenderState& state);
  void renderDetail(int detailIndex);
  void renderSettings(int tabIndex);
  void renderError(bool wifiError);
  void renderDialog(const String& line1, const String& line2);
};

}  // namespace ui
