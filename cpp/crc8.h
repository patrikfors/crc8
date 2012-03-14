#ifndef CRC8__H
#define CRC8__H

#include <cstddef> // size_t
#include <stdint.h>

template<uint8_t POLYNOMIAL>
class CRC8
{
public:
  uint8_t calculate (uint8_t* data, size_t length);
  static CRC8& instance();

private:
  CRC8();
  ~CRC8() {}
  CRC8& operator= (const CRC8&);
  CRC8 (const CRC8&);

  uint8_t _lut[256];
};

#include "crc8.ipp"

// explicit instantiation of template
/* x^8+x^7+x^6+x^4+x^2+1 */
//template class CRC8<0xd5>;

#endif /* CRC8__H */
