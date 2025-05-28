#pragma once

#include <Arduino.h>
#include <BluetoothSerial.h>

class BTDebug : public HardwareSerial {
  private:
    BluetoothSerial& _bt;

  public:
    BTDebug(int uart_num, BluetoothSerial& bt) : _bt(bt) {}

    size_t write(uint8_t c) override {
      _bt.write(c);

      return HardwareSerial::write(c);
    }

    size_t write(const uint8_t *buffer, size_t size) override {
        _bt.write(buffer, size);
        
        return HardwareSerial::write(buffer, size);
    }

    using HardwareSerial::write;
};