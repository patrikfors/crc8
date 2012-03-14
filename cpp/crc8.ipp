template<uint8_t POLYNOMIAL>
CRC8<POLYNOMIAL>& CRC8<POLYNOMIAL>::instance()
{
  static CRC8 singleton;
  return singleton;
}

template<uint8_t POLYNOMIAL>
uint8_t CRC8<POLYNOMIAL>::calculate (uint8_t* data, size_t length)
{
  uint8_t rval = 0;
  while (length--) {
    rval = _lut[rval ^ *data];
    data++;
  }

  return rval;
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
