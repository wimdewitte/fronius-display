#pragma once

#include <Arduino.h>

namespace fronius {

struct FlowSector {
  bool gen = false;
  int loc = -1;
};

struct FlowData {
  double pPv = NAN;
  double pAkku = NAN;
  double pGrid = NAN;
  double pLoad = NAN;
  bool valid = false;
  double soc = NAN;
  bool hasBatt = false;
  String battMode;
  double eInvTotal = NAN;
  double pInv = NAN;
  int nSec = 0;
  FlowSector sec[8];
};

struct MeterData {
  double v[3] = {NAN, NAN, NAN};
  double a[3] = {NAN, NAN, NAN};
  double p[3] = {NAN, NAN, NAN};
  double freq = NAN;
  double eImp = NAN;
  double eExp = NAN;
  double eGen = NAN;
  String model;
  bool valid = false;
  bool genValid = false;
};

struct StorageData {
  double capWh = NAN;
  double designWh = NAN;
  double tempC = NAN;
  double voltDc = NAN;
  String model;
  bool valid = false;
};

struct BattInfo {
  bool valid = false;
};

}  // namespace fronius
