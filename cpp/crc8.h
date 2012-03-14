#ifndef CRC8__H
#define CRC8__H

#include <cstddef> // size_t
#include <stdint.h>

class CRC8
{
public:
  static uint8_t calculate (uint8_t* data, size_t length);
private:
  CRC8() {}
  static const uint8_t _lut[256];
};

#endif /* CRC8__H */
