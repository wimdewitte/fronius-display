#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace core {

struct DisplayMetrics {
  static constexpr int W = 800;
  static constexpr int H = 480;
};

struct PowerFlowMetrics {
  static constexpr float FlowMinW = 30.0f;
  static constexpr float PvDefaultMaxW = 10000.0f;
};

struct UpdateTiming {
  static constexpr uint32_t CheckEveryMs = 24UL * 60UL * 60UL * 1000UL;
  static constexpr uint32_t FirstCheckMs = 60UL * 1000UL;
  static constexpr uint32_t RetryMs = 15UL * 60UL * 1000UL;
};

}  // namespace core
