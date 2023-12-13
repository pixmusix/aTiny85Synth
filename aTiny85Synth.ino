#include "Oscilator.h"
#include "Bus.h"

Bus aux;
Tri osc2 = Tri(20, 0.1, 0.0);
Sine osc = Sine(10, 1.0, 0.2);

void setup() {
  aux = initBus(aux);
}

void loop() {
  osc.tick();
  // osc2.tick();
  // osc.add(osc2);
  aux.spill(osc.map(0.0, 255.0)); 
}
