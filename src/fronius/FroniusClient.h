#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "FroniusTypes.h"
#include "JsonHelpers.h"

namespace fronius {

class FroniusClient {
 public:
  bool readPowerFlow(const String& host, FlowData& out);
  bool readMeters(const String& host, const FlowData& flow, MeterData& out);
  bool readStorage(const String& host, StorageData& out);
  bool readBattInfo(const String& host, BattInfo& out);

 private:
  static bool fetchJson(const String& host, const char* path, JsonDocument& doc, int& lastHttp);
};

}  // namespace fronius
