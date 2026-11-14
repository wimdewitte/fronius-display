#include "EnergyModel.h"

#include <algorithm>
#include <cmath>

namespace energy {

float householdLoadW(const PowerSnapshot& snapshot) {
  if (!snapshot.valid || std::isnan(snapshot.loadWApi)) return NAN;
  return std::fabs(snapshot.loadWApi);
}

float availableBatteryWh(const BatteryLimits& limits, float socPct) {
  if (std::isnan(socPct) || limits.capacityWh <= 0.0f) return NAN;

  const float soh = std::isfinite(limits.stateOfHealthPct)
                        ? std::clamp(limits.stateOfHealthPct, 0.0f, 100.0f)
                        : 100.0f;
  const float minSoc = std::isfinite(limits.minimumSocPct)
                           ? std::clamp(limits.minimumSocPct, 0.0f, 100.0f)
                           : 0.0f;
  const float usableCapacity = limits.capacityWh * soh / 100.0f;
  return usableCapacity * std::max(0.0f, socPct - minSoc) / 100.0f;
}

void integrate(const PowerSnapshot& snapshot, float elapsedHours, DailyTotals& totals) {
  if (!snapshot.valid || !std::isfinite(elapsedHours) || elapsedHours <= 0.0f) return;

  if (std::isfinite(snapshot.pvW) && snapshot.pvW > 0.0f)
    totals.pvWh += snapshot.pvW * elapsedHours;

  const float load = householdLoadW(snapshot);
  if (std::isfinite(load)) totals.loadWh += load * elapsedHours;

  if (std::isfinite(snapshot.batteryW)) {
    if (snapshot.batteryW > 0.0f)
      totals.batteryDischargeWh += snapshot.batteryW * elapsedHours;
    else
      totals.batteryChargeWh += -snapshot.batteryW * elapsedHours;
  }
}

} // namespace energy
