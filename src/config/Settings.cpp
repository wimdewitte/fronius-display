#include "Settings.h"

namespace config {

SettingsStore gSettings;

Settings SettingsStore::load() {
  Settings settings;
  Preferences prefs;
  prefs.begin(kNvsNamespace, true);

  settings.froniusHost = prefs.getString("host", settings.froniusHost);
  settings.wifiSsid = prefs.getString("ssid", settings.wifiSsid);
  settings.wifiPass = prefs.getString("wpass", settings.wifiPass);
  settings.ipFixed = prefs.getBool("ipfix", settings.ipFixed);
  settings.ipAddr = prefs.getString("ip", settings.ipAddr);
  settings.ipMask = prefs.getString("mask", settings.ipMask);
  settings.ipGw = prefs.getString("gw", settings.ipGw);
  settings.ipDns = prefs.getString("dns", settings.ipDns);
  settings.pollMs = prefs.getUInt("poll", settings.pollMs);
  settings.pvMaxW = prefs.getUInt("pvmax", settings.pvMaxW);
  settings.battWh = prefs.getUInt("battwh", settings.battWh);
  settings.rot180 = prefs.getBool("rot180", settings.rot180);
  settings.animOn = prefs.getBool("anim2", settings.animOn);
  settings.brightPct = prefs.getUChar("bright", settings.brightPct);
  settings.sleepBlack = prefs.getBool("sleepblk", settings.sleepBlack);
  settings.contrastLvl = prefs.getUChar("contrast", settings.contrastLvl);
  settings.nightOn = prefs.getBool("nighton", settings.nightOn);
  settings.nightFrom = prefs.getUShort("nightfrom", settings.nightFrom);
  settings.nightTo = prefs.getUShort("nightto", settings.nightTo);
  settings.nightLvl = prefs.getUChar("nightlvl", settings.nightLvl);
  settings.gridChg = prefs.getBool("gridchg", settings.gridChg);

  prefs.end();
  validate(settings);
  return settings;
}

bool SettingsStore::save(const Settings& settings) {
  Preferences prefs;
  prefs.begin(kNvsNamespace, false);

  prefs.putString("host", settings.froniusHost);
  prefs.putString("ssid", settings.wifiSsid);
  prefs.putString("wpass", settings.wifiPass);
  prefs.putBool("ipfix", settings.ipFixed);
  prefs.putString("ip", settings.ipAddr);
  prefs.putString("mask", settings.ipMask);
  prefs.putString("gw", settings.ipGw);
  prefs.putString("dns", settings.ipDns);
  prefs.putUInt("poll", settings.pollMs);
  prefs.putUInt("pvmax", settings.pvMaxW);
  prefs.putUInt("battwh", settings.battWh);
  prefs.putBool("rot180", settings.rot180);
  prefs.putBool("anim2", settings.animOn);
  prefs.putUChar("bright", settings.brightPct);
  prefs.putBool("sleepblk", settings.sleepBlack);
  prefs.putUChar("contrast", settings.contrastLvl);
  prefs.putBool("nighton", settings.nightOn);
  prefs.putUShort("nightfrom", settings.nightFrom);
  prefs.putUShort("nightto", settings.nightTo);
  prefs.putUChar("nightlvl", settings.nightLvl);
  prefs.putBool("gridchg", settings.gridChg);

  prefs.end();
  return true;
}

bool SettingsStore::validate(Settings& settings) const {
  if (settings.pollMs < 2000) settings.pollMs = 2000;
  if (settings.brightPct < 10 || settings.brightPct > 100) settings.brightPct = 100;
  if (settings.nightFrom >= 1440) settings.nightFrom = 22 * 60;
  if (settings.nightTo >= 1440) settings.nightTo = 6 * 60;
  if (settings.nightLvl > 2) settings.nightLvl = 0;
  if (settings.contrastLvl > 3) settings.contrastLvl = 0;
  return true;
}

void SettingsStore::clear() {
  Preferences prefs;
  prefs.begin(kNvsNamespace, false);
  prefs.clear();
  prefs.end();
}

}  // namespace config
