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

  void spill() {
    shiftOut(DAT, CLK, MSBFIRST, value);
    toggleLatch();
  }

  void spill(uint16_t v) {
    value = v;
    spill();
  }
};

Bus initBus(Bus bus) {
  bus.value = 0;
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  bus.CLK = 2;
  bus.DAT = 0;
  bus.LTC = 1;
  return bus;
}