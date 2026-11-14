# Fronius-Display

[![License: MIT](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![Buy me a coffee](https://img.shields.io/badge/Buy%20me%20a%20coffee-%E2%98%95-yellow)](https://buymeacoffee.com/alpi_brv)

<a href="https://buymeacoffee.com/alpi_brv"><img src="docs/images/coffee.png" alt="Buy me a coffee" width="200"></a>

Standalone touch display for **Fronius inverters** (tested: Symo GEN24) –
run on a cheap ESP32-S3 display, without ioBroker, Home Assistant, or a server.
The display fetches values directly from the inverter via Wi‑Fi using the Fronius Solar API.

> **Not an official Fronius product.** For questions about the display, please open an issue in this
> repository, not with Fronius. Use at your own risk.

💬 **Discussion:** [Thread in the photovoltaic forum](https://www.photovoltaikforum.com/thread/265604-eigenst%C3%A4ndiges-touch-display-f%C3%BCr-fronius-gen24-open-source-ohne-server/)

> **Status: 0.1.x – first test versions.** Runs on the 5" on a Symo GEN24 with a
> BYD battery and an additional Hoymiles inverter.

## Installation

1. Connect the display via USB-C.
2. Open the **[web installer](https://alpi-brv.github.io/fronius-display/)** in Chrome or Edge.
3. Click the button for **your size** (5" or 7"), choose the connection, and you're done.

After that, the display opens the settings: select Wi‑Fi, enter the inverter IP in the **Fronius** tab,
then click **Save**.

## Images

![Energy flow](docs/images/energiefluss.jpg)

*Home screen on the 5" – energy flow and daily values*

| Photovoltaics | Grid with phases |
|---|---|
| ![Photovoltaics](docs/images/pv.jpg) | ![Grid](docs/images/netz.jpg) |

| Battery | Consumers |
|---|---|
| ![Battery](docs/images/batterie.jpg) | ![Consumers](docs/images/verbraucher.jpg) |

<details>
<summary>Settings (images)</summary>

| Fronius | Wi‑Fi |
|---|---|
| ![Fronius settings](docs/images/einstellungen-fronius.jpg) | ![Wi‑Fi](docs/images/wlan.jpg) |

| IP | Display |
|---|---|
| ![IP](docs/images/ip.jpg) | ![Display](docs/images/anzeige.jpg) |

| System | |
|---|---|
| ![System](docs/images/system.jpg) | |

</details>

## Features

- **Energy flow** as in Solar.web: PV, consumers, grid, and battery as segmented rings
  around the inverter; arrows (or moving dots on request) show the direction of flow
- **Tap opens details:**
  - PV – split by inverter (e.g. GEN24 + additional inverter via Fronius Smart Meter), later strings via Modbus
  - Grid – phases L1–L3 with voltage, current, power, frequency
  - Battery – state of charge, charge/discharge power, energy still available, “empty in approx …” /
    “full in approx …”. On the GEN24, discharge limit (min_soc) and battery state (SOH)
    are automatically considered: usable = capacity × SOH × (charge level − discharge limit)
  - Consumers – home, later Wallbox (Wattpilot) and electric heating element (Ohmpilot) separately
- **Daily values:** PV yield, consumption, grid import, feed-in, battery charging,
  self-sufficiency, own consumption – calculated from meter readings themselves
  (the GEN24 provides no daily values)
- **Orientation selectable:** USB connection left or right (rotation by 180°) –
  takes effect immediately, image and touch rotate together
- **Setup fully on the display:** Wi‑Fi, fixed IP or DHCP, inverter IP,
  PV power (kWp, ring overshoot), battery capacity (for the remaining time; a value entered here takes precedence over the storage-reported one, e.g. after changing the BMS parameter table)
- **Updates over Wi‑Fi** and installation in the browser – as with the
  [Violet Pool Display](https://github.com/AlPi-BRV/violet-display)
- After 5 minutes without touch input, optionally dim or go fully black (Settings → Brightness & Contrast); on a fault, the error screen remains dimly visible. Details and settings remain accessible.
- **Night mode:** in a time window (e.g. 00:00–06:30) at most 10% or 20% brightness
  or fully off (Settings → System → Night mode). When set to Off, the display lights up at 20% after touch.
- **Grid charging:** If the battery is also charged from the grid (e.g. at night with dynamic tariffs
  or forced charging), choose “Yes” under Settings → Display → Grid charging. Then the charge from the grid is not counted as household consumption, and self-sufficiency is calculated without grid power for the battery. On the grid page, “into the battery” is shown additionally.
- **Faults at a glance:** If Wi‑Fi disappears, a large crossed-out Wi‑Fi symbol appears,
  and if the inverter does not respond, the crossed-out inverter symbol appears. Outdated values remain hidden for as long as needed. The display reconnects automatically, even if the router comes back later after a power outage.

### Planned

- Statistics for day, month, year; optionally with **SD card** also daily histories
- Strings (MPPT) via Modbus TCP
- Wallbox (Wattpilot) with its own query
- Additional Smart Meter integrations
- More optimization and detail views
