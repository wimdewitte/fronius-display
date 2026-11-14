#include "DayStatistics.h"

namespace energy {

void DayStatistics::reset() {
  data_ = DayStore();
}

void DayStatistics::loadFromNvs() {
  // Placeholder: migrate the original dayS logic here.
}

void DayStatistics::saveToNvs() {
  // Placeholder: persist the DayStore in Preferences.
}

void DayStatistics::updateFromNow(float elapsedHours, const float pvW, const float loadW,
                                 const float batteryW) {
  if (elapsedHours <= 0.0f) return;

  if (pvW > 0.0f) data_.pvWh += pvW * elapsedHours;
  if (!isnan(loadW)) data_.loadWh += fabsf(loadW) * elapsedHours;
  if (!isnan(batteryW)) {
    if (batteryW > 0.0f) data_.battOutWh += batteryW * elapsedHours;
    else data_.battInWh += -batteryW * elapsedHours;
  }
}

DayStore& DayStatistics::data() {
  return data_;
}

const DayStore& DayStatistics::data() const {
  return data_;
}

}  // namespace energy
