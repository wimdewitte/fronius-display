# Modular source layout

The existing firmware remains the behavioral reference while the refactor is performed incrementally. PlatformIO automatically compiles `.cpp` files under `src/`.

Planned ownership:

- `main.cpp`: Arduino entry points only (`setup()` and `loop()`).
- `app/`: top-level application lifecycle and coordination.
- `config/`: persisted settings and validation.
- `fronius/`: API client and Fronius data models.
- `energy/`: daily energy calculations and persistence.
- `network/`: Wi-Fi management and OTA updates.
- `ui/`: display rendering, screens, and touch navigation.

Keep hardware-independent calculations in `energy/`; keep display and network side effects in their respective modules. Preserve existing Preferences keys and API behavior during extraction. This commit adds the first extracted domain module; subsequent changes can migrate callers module by module without changing the user-visible behavior.
