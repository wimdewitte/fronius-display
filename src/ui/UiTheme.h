#include "FroniusClient.h"

namespace fronius {

bool FroniusClient::readPowerFlow(const String& host, FlowData& out) {
  (void)host;
  out.valid = false;
  return false;
}

bool FroniusClient::readMeters(const String& host, FlowData& flow, MeterData& out) {
  (void)host;
  (void)flow;
  out.valid = false;
  return false;
}

bool FroniusClient::readStorage(const String& host, StorageData& out) {
  (void)host;
  out.valid = false;
  return false;
}

bool FroniusClient::readBattInfo(const String& host, BattInfo& out) {
  (void)host;
  out.valid = false;
  return false;
}

}  // namespace fronius
