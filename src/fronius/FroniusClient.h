#pragma once

#include <Arduino.h>

namespace fronius {

struct SecMeter {
  String label;
  float p = NAN;
  int loc = -1;
  bool gen = false;
};

struct FlowData {
  bool valid = false;
  float pPv = NAN, pAkku = NAN, pGrid = NAN, pLoad = NAN;
  float soc = NAN;
  bool hasBatt = false;
  String battMode;
  bool battStandby = false;
  double eInvTotal = NAN;
  float pInv = NAN;
  int nSec = 0;
  SecMeter sec[4];
  int nOhm = 0;
  float ohmP[2] = { NAN, NAN };
  float ohmTemp[2] = { NAN, NAN };
};

struct MeterData {
  bool valid = false;
  float v[3] = { NAN, NAN, NAN };
  float a[3] = { NAN, NAN, NAN };
  float p[3] = { NAN, NAN, NAN };
  float freq = NAN;
  double eImp = NAN, eExp = NAN;
  bool genValid = false;
  double eGen = NAN;
  String model;
};

struct StorageData {
  bool valid = false;
  float capWh = NAN;
  float designWh = NAN;
  float tempC = NAN;
  float voltDc = NAN;
  String model;
};

struct BattInfo {
  bool valid = false;
  float capWh = NAN;
  float minSoc = NAN;
  float maxSoc = NAN;
  float soh = NAN;
};

struct PollResult {
  bool ok = false;
  FlowData flow;
  bool meterOk = false;
  MeterData meter;
  bool storOk = false;
  StorageData storage;
  bool battInfoOk = false;
  BattInfo battInfo;
};

}  // namespace fronius
