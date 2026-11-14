#include <Arduino.h>

#include "app/AppCoordinator.h"

namespace {
app::AppCoordinator gCoordinator;
}

void setup() {
  gCoordinator.begin();
}

void loop() {
  gCoordinator.loop();
}
