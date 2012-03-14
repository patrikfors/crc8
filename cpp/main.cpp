#include <iomanip>
#include <iostream>
using namespace std;

#include "crc8.h"
typedef CRC8<0xd5> crc8;

int main (void)
{

  // test with a dead babe
  uint32_t x = 0xbebaadde;
  uint8_t* data = (uint8_t*) &x;

  // template singleton version
  crc8& crc = crc8::instance();
  cout << "crc=0x" << hex << setw (2) << setfill ('0') <<
       (int) crc.calculate (data, 4) << endl;
}
