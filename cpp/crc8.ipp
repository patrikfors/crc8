#include <numeric>

// function object.. wasn't able to use it as member function
struct crc8_calculator {
  crc8_calculator (uint8_t (&table) [256]) : xlut (table) { }
  uint8_t operator() (uint8_t initial, uint8_t data) {
    return xlut[initial ^ data];
  }
private:
  uint8_t (&xlut) [256];
};


template<uint8_t POLYNOMIAL>
CRC8<POLYNOMIAL>& CRC8<POLYNOMIAL>::instance()
{
  static CRC8 singleton;
  return singleton;
}

template<uint8_t POLYNOMIAL> template<typename InputIterator>
uint8_t CRC8<POLYNOMIAL>::calculate (
  InputIterator first,
  InputIterator last,
  uint8_t initial)
{
  return std::accumulate (first, last, initial, crc8_calculator (_lut));
}

template<uint8_t POLYNOMIAL>  template <typename Integral>
uint8_t CRC8<POLYNOMIAL>::calculate_running (uint8_t prev, Integral s)
{
#if defined(LITTLE_ENDIAN)
  typedef std::reverse_iterator<const uint8_t*> rit;
  return calculate (rit ( (uint8_t*) &s + sizeof (s)), rit ( (uint8_t*) &s), prev);
#elif defined(BIG_ENDIAN)
  return calculate ( (uint8_t*) &s, (uint8_t*) &s + sizeof (s), prev);
#else
# error "Unsupported endianness."
#endif
}

template<uint8_t POLYNOMIAL>
CRC8<POLYNOMIAL>::CRC8()
{
  for (int i = 0; i < 256; i++) {
    uint8_t entry = i;

    for (int j = 0; j < 8; j++) {
      if (entry & 0x80)
        entry = (entry << 1) ^ POLYNOMIAL;
      else
        entry <<= 1;
    }
    _lut[i] = entry;
  }
}
