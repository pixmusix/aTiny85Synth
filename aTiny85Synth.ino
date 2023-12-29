#include "Oscilator.h"
#include "Bus.h"

Bus aux;
Saw osc_saw = Saw(0.5, 1.0, 0.0);
Square osc_sq = Square(8.5, 0.5, 0.0);
Sine LFO = Sine(0.7, 0.76, 0.0);

void setup() {
  aux = initBus(aux);
}

void loop() {
  osc_saw.tick();
  LFO.tick();
  osc_sq.tick();
  osc_saw.mult(LFO);
  osc_saw.add(osc_sq);
  aux.spill(osc_saw.map(0, 250.5));
}
