#pragma once

#include <Arduino.h>
#include <BluetoothSerial.h>

class BTDebug : public Print {
  private:
    HardwareSerial& _serial;
    BluetoothSerial& _bt;

  public:
    BTDebug(HardwareSerial& serial, BluetoothSerial& bt) 
      : _serial(serial), _bt(bt) { }

    void begin(unsigned long baudrate) {
      _serial.begin(baudrate);
    }

    void btBegin(const char* name) {
      _bt.begin(name);
    }

    size_t write(uint8_t c) override {
      _serial.write(c);
      _bt.write(c);
      return 1;
    }

    size_t write(const uint8_t *buffer, size_t size) override {
      _serial.write(buffer, size);
      _bt.write(buffer, size);
      return size;
    }

    using Print::write;

    int available() {
      return _serial.available();
    }

    int read() {
      return _serial.read();
    }

    int peek() {
      return _serial.peek();
    }

    void flush() {
      _serial.flush();
    }
};
