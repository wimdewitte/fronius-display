# Modular firmware structure

This project is being migrated from the original single-file Arduino firmware into a modular layout while preserving the original behavior and settings keys.

Current structure:

- src/main.cpp
  - Arduino entry point (`setup()` / `loop()`) only
- src/app/
  - application lifecycle and runtime coordination
- src/config/
  - persisted settings and validation
- src/core/
  - shared constants and global runtime types
- src/energy/
  - power calculations and daily statistics
- src/fronius/
  - Fronius API client, JSON helpers and data structures
- src/network/
  - Wi-Fi and OTA/update management
- src/ui/
  - display state, screen manager, touch and rendering entry points

The original monolithic file remains the reference implementation while the refactor is staged gradually so builds remain stable.
