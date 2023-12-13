//https://www.desmos.com/calculator/hj5zvalnlj

#include <math.h>

const double incr = 0.001;

class Oscilator {

  protected:
    double clock;
    double freq;
    double ampl;
    double phaz;

  public:
    double scalar;

    Oscilator() {}

    Oscilator add(Oscilator other) {
      scalar += other.scalar;
      return *this;
    }

    Oscilator mult(Oscilator other) {
      scalar = scalar * other.scalar;
      return *this;
    }

    Oscilator sub(Oscilator other) {
      scalar -= other.scalar;
      return *this;
    }

    Oscilator div(Oscilator other) {
      scalar = scalar / other.scalar;
      return *this;
    }

    Oscilator mod(Oscilator other) {
      scalar = fmod(scalar, other.scalar);
      return *this;
    }

    Oscilator freqAdd(Oscilator other) {
      freq = freq + other.scalar;
      return *this;
    }

    Oscilator freqModulate(Oscilator other) {
      freq = freq * other.scalar;
      return *this;
    }

    Oscilator phaseShift(Oscilator other) {
      phaz = phaz + other.scalar;
      return *this;
    }

    double map(double min, double max) {
      double a = ampl / -2;
      double b = ampl / 2;
      return scalar / (b - a) * (max - min) + min;
    }

    double getFreq() {
      return freq;
    }

    double getAmpl() {
      return ampl;
    }

    double getPhaz() {
      return phaz;
    }

    void setFreq(double f) {
      freq = f != 0 ? f : 1;
    }

    void setAmpl(double a) {
      ampl = a;
    }

    void setPhaz(double p) {
      phaz = p;
    }

    double tick() {
      return scalar;
    }

};

class Sine : public Oscilator {
  
  public:

    Sine(double f, double a, double p) {
      freq = f;
      ampl = a;
      phaz = p;
    }

    double tick() {
      clock += incr;
      scalar = ampl * cos(2 * PI * (1/freq) * (clock + phaz));
      return scalar;
    }

};

class Saw : public Oscilator {

  public:
    
    Saw(double f, double a, double p) {
      freq = f;
      ampl = a;
      phaz = p;
    }

    double tick() {
      clock += incr;
      double period = (clock + phaz) / freq;
      scalar = 2 * ampl * (period - floor(0.5 + period));
      return scalar;
    }

};

class Square : public Oscilator {

  public:

    Square(double f, double a, double p) {
      freq = f;
      ampl = a;
      phaz = p;
    }

    double tick() {
      clock += incr;
      double exponent = sin(2 * PI * (clock + phaz + PI/2) * freq);
      double denominator = pow(abs(pow(2, 16)), exponent) + 1;
      scalar = ((2 * ampl) / denominator) - ampl;
      return scalar;
    }

};

class Tri : public Oscilator {

  public:

    Tri(double f, double a, double p) {
      freq = f;
      ampl = a;
      phaz = p;
    }

    double tick() {
      clock += incr;
      double angle = abs((clock - fmod((freq / 4), freq)) - (freq / 2));
      scalar = ((4 * ampl) / freq) * angle - ampl;
      return scalar;
    }

};

