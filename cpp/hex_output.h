#ifndef HEX_OUTPUT__H
#define HEX_OUTPUT__H

#include <iostream>

/*
Also works but its more conventient to use hex(n) than hex<n>

template <unsigned int N>
std::ostream& formatted_hex (std::ostream& out)
{
  out << "0x" << std::hex << std::setw (N) << std::setfill ('0');
  return out;
}
*/
struct HexWidthStruct {
  unsigned int width;
  HexWidthStruct (unsigned int w) : width (w) {}
};

inline std::ostream& operator<< (std::ostream& o, const HexWidthStruct& hs)
{
  o << "0x" << std::hex << std::setw (hs.width) << std::setfill ('0');
  return o;
}

inline HexWidthStruct hex (unsigned int w)
{
  return HexWidthStruct (w);
}

#endif /* HEX_OUTPUT__H */
