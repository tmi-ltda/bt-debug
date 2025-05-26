#pragma once

#include <Arduino.h>
#include <BluetoothSerial.h>

class BTDebug : public Print {
  private:
    HardwareSerial& _primary;
    BluetoothSerial& _secondary;

  public:
    BTDebug(HardwareSerial& p, BluetoothSerial& s) : _primary(p), _secondary(s) {}

    void begin(unsigned long baud, const char* name) {
      _primary.begin(baud);
      _secondary.begin(name);
    }

    size_t write(uint8_t c) override {
      _primary.write(c);
      _secondary.write(c);
      return 1;
    }

    using Print::write;
};