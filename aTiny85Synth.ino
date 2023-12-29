#include "Oscilator.h"
#include "Bus.h"

double f;

Bus aux;
Tri osc_tri = Tri(0.00003, 1, 0.0);
Saw osc_saw = Saw(0.003, 1.2, 0.314);
Sine LFO = Sine(0.00002, 1.0, 0.0);

void setup() {
  aux = initBus(aux);
  f = 1.1;
}

void loop() {
  osc_tri.setPhaz(LFO.tick());
  osc_tri.tick();
  
  // f = f - 0.00001;
  // osc_saw.setFreq(f);
  osc_saw.tick();

  osc_tri.add(osc_saw);
  aux.spill(osc_tri.map(0.0, 255.0)); 
}
