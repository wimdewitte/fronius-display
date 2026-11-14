#include "FroniusClient.h"

namespace fronius {

bool FroniusClient::fetchJson(const String& host, const char* path, JsonDocument& doc, int& lastHttp) {
  if (WiFi.status() != WL_CONNECTED || host.length() == 0) {
    lastHttp = -1;
    return false;
  }

  HTTPClient http;
  http.useHTTP10(true);
  http.setTimeout(4000);
  http.setConnectTimeout(3000);
  if (!http.begin("http://" + host + path)) {
    lastHttp = -1;
    return false;
  }

  int code = http.GET();
  lastHttp = code;
  if (code != 200) {
    http.end();
    return false;
  }

  DeserializationError err = deserializeJson(doc, http.getStream());
  http.end();
  if (err) {
    lastHttp = -2;
    return false;
  }

  return true;
}

bool FroniusClient::readPowerFlow(const String& host, FlowData& out) {
  JsonDocument doc;
  int lastHttp = 0;
  if (!fetchJson(host, "/solar_api/v1/GetPowerFlowRealtimeData.fcgi", doc, lastHttp)) return false;

  JsonObjectConst d = doc["Body"]["Data"].as<JsonObjectConst>();
  if (d.isNull()) return false;

  JsonObjectConst site = d["Site"].as<JsonObjectConst>();
  out.pPv = jd(site["P_PV"]);
  out.pAkku = jd(site["P_Akku"]);
  out.pGrid = jd(site["P_Grid"]);
  out.pLoad = jd(site["P_Load"]);
  out.valid = true;

  for (JsonPairConst kv : d["Inverters"].as<JsonObjectConst>()) {
    JsonObjectConst inv = kv.value().as<JsonObjectConst>();
    double soc = jd(inv["SOC"]);
    if (!isnan(soc)) {
      out.soc = soc;
      out.hasBatt = true;
    }
    out.battMode = js(inv["Battery_Mode"]);
    double e = jd(inv["E_Total"]);
    if (!isnan(e)) out.eInvTotal = isnan(out.eInvTotal) ? e : out.eInvTotal + e;
    double p = jd(inv["P"]);
    if (!isnan(p)) out.pInv = isnan(out.pInv) ? p : out.pInv + p;
  }

  if (!isnan(out.pAkku)) out.hasBatt = true;
  return true;
}

bool FroniusClient::readMeters(const String& host, const FlowData& flow, MeterData& out) {
  JsonDocument doc;
  int lastHttp = 0;
  if (!fetchJson(host, "/solar_api/v1/GetMeterRealtimeData.cgi?Scope=System", doc, lastHttp)) return false;

  JsonObjectConst d = doc["Body"]["Data"].as<JsonObjectConst>();
  if (d.isNull()) return false;

  double eGen = 0;
  bool anyGen = false;
  for (JsonPairConst kv : d) {
    JsonObjectConst m = kv.value().as<JsonObjectConst>();
    double locD = jd(m["Meter_Location_Current"]);
    int loc = isnan(locD) ? -1 : (int)lround(locD);
    if (loc == 0 && !out.valid) {
      static const char* const V[3] = { "Voltage_AC_Phase_1", "Voltage_AC_Phase_2", "Voltage_AC_Phase_3" };
      static const char* const A[3] = { "Current_AC_Phase_1", "Current_AC_Phase_2", "Current_AC_Phase_3" };
      static const char* const P[3] = { "PowerReal_P_Phase_1", "PowerReal_P_Phase_2", "PowerReal_P_Phase_3" };
      for (int i = 0; i < 3; i++) {
        out.v[i] = jd(m[V[i]]);
        out.a[i] = jd(m[A[i]]);
        out.p[i] = jd(m[P[i]]);
      }
      out.freq = jd(m["Frequency_Phase_Average"]);
      out.eImp = jd(m["EnergyReal_WAC_Sum_Consumed"]);
      out.eExp = jd(m["EnergyReal_WAC_Sum_Produced"]);
      out.model = js(m["Details"]["Model"]);
      out.valid = !isnan(out.eImp) && !isnan(out.eExp);
    }
  }

  for (JsonPairConst kv : d) {
    JsonObjectConst m = kv.value().as<JsonObjectConst>();
    double locD = jd(m["Meter_Location_Current"]);
    int loc = isnan(locD) ? -1 : (int)lround(locD);
    bool isGen = false;
    for (int i = 0; i < flow.nSec; i++) {
      if (flow.sec[i].gen && flow.sec[i].loc == loc) { isGen = true; break; }
    }
    if (isGen) {
      double e = jd(m["EnergyReal_WAC_Sum_Produced"]);
      if (!isnan(e)) { eGen += e; anyGen = true; }
    }
  }

  out.genValid = anyGen;
  out.eGen = anyGen ? eGen : NAN;
  return true;
}

bool FroniusClient::readStorage(const String& host, StorageData& out) {
  JsonDocument doc;
  int lastHttp = 0;
  if (!fetchJson(host, "/solar_api/v1/GetStorageRealtimeData.cgi?Scope=System", doc, lastHttp)) return false;

  for (JsonPairConst kv : doc["Body"]["Data"].as<JsonObjectConst>()) {
    JsonObjectConst c = kv.value()["Controller"].as<JsonObjectConst>();
    if (c.isNull()) continue;
    out.capWh = jd(c["Capacity_Maximum"]);
    out.designWh = jd(c["DesignedCapacity"]);
    out.tempC = jd(c["Temperature_Cell"]);
    out.voltDc = jd(c["Voltage_DC"]);
    out.model = js(c["Details"]["Model"]);
    out.model.trim();
    if (!out.model.length()) out.model = js(c["Details"]["Manufacturer"]);
    out.valid = true;
    return true;
  }
  return false;
}

bool FroniusClient::readBattInfo(const String& host, BattInfo& out) {
  (void)host;
  out.valid = false;
  return false;
}

}  // namespace fronius
