#include "Oscilator.h"
#include "Bus.h"
#include "Slider.h"

#define HC74595_DATA 0
#define HC74595_LATCH 1
#define HC74595_CLOCK 2
#define POT_LEFT A2
#define POT_RIGHT A3

Bus aux;
Dial leftPot = Dial(POT_LEFT);
Dial rightPot = Dial(POT_RIGHT);
Saw osc_saw = Saw(0.5, 20.0, 0.0);
Square osc_sq = Square(8.5, 0.5, 0.0);
Sine lfo = Sine(0.7, 0.76, 0.0);

void setup() {
  aux = initBus(
    aux, 
    HC74595_DATA, 
    HC74595_LATCH,
    HC74595_CLOCK
  );
}

void loop() {
  //get potentiometer values
  double lv = leftPot.getValue() / 1023.0 * 1.0;
  double rv = rightPot.getValue() / 1023.0 * 2.0;

  //manip saw oscilator
  osc_saw.setFreq(lv);
  osc_saw.setAmpl(rv);

  // //Synthesis
  // lfo.tick();
  // osc_saw.mult(lfo);
  // osc_sq.tick();
  // osc_saw.add(osc_sq);

  //write to auxiliary for output.
  //osc_saw.tick();
  aux.spill(osc_saw.tick());
}
