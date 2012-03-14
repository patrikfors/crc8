#ifndef CRC8__H
#define CRC8__H

#include <cstddef> // size_t
#include <iterator>
#include <stdint.h>

struct crc8_calculator {
  crc8_calculator (uint8_t (&table) [256]) : xlut (table) { }
  uint8_t operator() (uint8_t initial, uint8_t data) {
    return xlut[initial ^ data];
  }
private:
  uint8_t (&xlut) [256];
};


template<uint8_t POLYNOMIAL>
class CRC8
{
public:
//  uint8_t calculate (uint8_t* data, size_t length);
//  uint8_t calculatex (uint8_t prev, uint8_t data);

  template <typename InputIterator>
  uint8_t calculate (InputIterator first, InputIterator last);

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
