#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#include "crc8.h"
#include "hex_output.h"

typedef CRC8<0xd5> crc8;

int main (void)
{
  crc8& crc = crc8::instance();

  // test with a dead babe
  uint32_t x = 0xdeadbabe;
  std::cout << "deadbabe crc=" << hex (2) <<
            (int) crc.calculate_running (0, x) << std::endl;

  // test with stdin
  uint8_t checksum = 0;

  std::vector<char> v;
  char input = 0;
  while (std::cin.get (input)) {
    v.push_back (input);
    checksum = crc.calculate_running (checksum, input);
    std::cout << "checksum: " << hex (2) <<
              (int) checksum << std::endl;
  }
  std::cout << "checksum(v): " << hex (2) <<
            (int) crc.calculate (v.begin(), v.end()) << std::endl;
}
