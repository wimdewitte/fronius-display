#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>

namespace fronius {

inline double jd(JsonVariantConst v) {
  if (v.isNull()) return NAN;
  if (v.is<const char*>()) return atof(v.as<const char*>());
  return v.as<double>();
}

inline String js(JsonVariantConst v) {
  const char* p = v.as<const char*>();
  return p ? String(p) : String();
}

}  // namespace fronius
