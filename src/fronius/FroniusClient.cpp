#pragma once

#include <Arduino.h>
#include "FroniusTypes.h"

namespace fronius {

class FroniusClient {
 public:
  bool readPowerFlow(const String& host, FlowData& out);
  bool readMeters(const String& host, FlowData& flow, MeterData& out);
  bool readStorage(const String& host, StorageData& out);
  bool readBattInfo(const String& host, BattInfo& out);
};

}  // namespace fronius
