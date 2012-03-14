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
  uint32_t x2 = 0xdeadbabe;
  uint8_t* data2 = (uint8_t*) &x2;

  // template singleton version
  crc8& crc = crc8::instance();
  typedef reverse_iterator<const uint8_t*> rit;

  /*
  uint8_t running_crc=0;
  for(rit i=rit(data2+4);i!=rit(data2);i++)
    running_crc=crc.calculate(running_crc, *i);
  cout << "rcrc=0x" << hex << setw (2) << setfill ('0') << (int) running_crc << endl;
  */
  cout << "xxxx=0x" << hex << setw (2) << setfill ('0') << (int) crc.calculate (data, data + 4) << endl;

}
