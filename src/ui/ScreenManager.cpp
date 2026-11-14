#include "ScreenManager.h"

namespace ui {

void ScreenManager::activate(ScreenId screen) {
  state_.current = screen;
  state_.redrawRequired = true;
}

ScreenId ScreenManager::active() const {
  return state_.current;
}

void ScreenManager::markDirty() {
  state_.redrawRequired = true;
}

bool ScreenManager::needsRedraw() const {
  return state_.redrawRequired;
}

}  // namespace ui
