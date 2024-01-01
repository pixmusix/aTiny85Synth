class Slider {
  
  protected:
    byte pin;
    double val;
    double cache;

    void update() {
      val = analogRead(pin);
    }
  
  public:

    Slider() {}

    Slider(byte pin) {
      this->pin = pin;
      cache = 0;
      pinMode(pin, INPUT);
    }

    double getValue() {
      update();
      return val;
    }

    double getChange() {
      double k = cache - getValue();
      if (k != 0) {
        cache = getValue();
        return k;
      }
    }

};

/* A dial is just a slider where angle matters. */
class Dial : public Slider {

  private:
    float toRadians(int i) {
      return (i / 1023.0) * TWO_PI;
    }
  
  public:

    Dial(byte pin) : Slider { pin } {
      this->pin = pin;
      cache = 0;
      pinMode(pin, INPUT);
    }

    double getAngle() {
      update();
      return toRadians(val);
    }

    double getAngleChange() {
      int k = cache - getValue();
      if (k != 0) {
        cache = getValue();
        return toRadians(k);
      }
    }

};