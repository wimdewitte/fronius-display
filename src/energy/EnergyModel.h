#pragma once

#include <math.h>
#include <stdint.h>

namespace energy {

// Snapshot of the four primary power-flow values. Fronius API signs are kept:
// grid > 0 means import, battery > 0 means discharge, and load is API-signed.
struct PowerSnapshot {
  bool valid = false;
  float pvW = NAN;
  float batteryW = NAN;
  float gridW = NAN;
  float loadWApi = NAN;
};

struct BatteryLimits {
  float capacityWh = 0.0f;
  float stateOfHealthPct = 100.0f;
  float minimumSocPct = 0.0f;
  float maximumSocPct = 100.0f;
};

struct DailyTotals {
  float pvWh = 0.0f;
  float loadWh = 0.0f;
  float batteryChargeWh = 0.0f;
  float batteryDischargeWh = 0.0f;
  float gridImportWh = NAN;
  float gridExportWh = NAN;
};

// Return the magnitude of household consumption from the API's negative P_Load.
float householdLoadW(const PowerSnapshot& snapshot);

// Stored energy that can still be discharged without crossing the configured
// minimum SOC. Invalid SOC yields NAN to preserve the caller's unknown state.
float availableBatteryWh(const BatteryLimits& limits, float socPct);

// Integrate a snapshot over elapsed hours. This helper only handles the values
// represented by the snapshot; meter-counter baselines remain the responsibility
// of the daily-statistics persistence layer.
void integrate(const PowerSnapshot& snapshot, float elapsedHours, DailyTotals& totals);

} // namespace energy
