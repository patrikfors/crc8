#ifndef CRC8__H
#define CRC8__H

#include <cstddef> // size_t
#include <iterator>
#include <stdint.h>

template<uint8_t POLYNOMIAL>
class CRC8
{
public:
  static CRC8& instance();

  template <typename InputIterator>
  uint8_t calculate (
    InputIterator first,
    InputIterator last,
    uint8_t initial = 0);

  template <typename Integral>
  uint8_t calculate_running (uint8_t prev, Integral s);

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
