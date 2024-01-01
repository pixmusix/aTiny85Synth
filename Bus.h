struct Bus {
  byte DAT;
  byte CLK;
  byte LTC;

  uint16_t value;

  void toggleLatch() {
    digitalWrite(LTC, LOW);
    digitalWrite(LTC, HIGH);
    digitalWrite(LTC, LOW);
  }

  uint16_t wrap(uint16_t v) {
    return v % 256;
  }

  void spill() {
    shiftOut(DAT, CLK, MSBFIRST, value);
    toggleLatch();
  }

  void spill(uint16_t v) {
    value = wrap(v);
    spill();
  }
};

Bus initBus(Bus bus, int data, int latch, int clock) {
  bus.value = 0;
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  bus.CLK = clock;
  bus.DAT = data;
  bus.LTC = latch;
  return bus;
}