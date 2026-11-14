#pragma once

#include <Arduino.h>
#include <stdint.h>

namespace energy {

struct DayStore {
  uint32_t day = 0;
  uint16_t startMin = 0;
  uint16_t ver = 2;
  double eImp = NAN;
  double eExp = NAN;
  double eGen = NAN;
  double eInv = NAN;
  float pvWh = 0.0f;
  float loadWh = 0.0f;
  float battInWh = 0.0f;
  float battOutWh = 0.0f;
  float acInWh = 0.0f;
  float gridBattWh = 0.0f;
};

class DayStatistics {
 public:
  void reset();
  void loadFromNvs();
  void saveToNvs();
  void updateFromNow(float elapsedHours, const float pvW, const float loadW,
                     const float batteryW);
  DayStore& data();
  const DayStore& data() const;

 private:
  DayStore data_;
};

}  // namespace energy
