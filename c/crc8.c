#include "crc8.h"

#include <stdio.h>

const uint8_t CRC8_POLYNOMIAL = 0xd5;

uint8_t crc_bitwise (uint8_t* data, size_t length, uint8_t polynomial)
{
  uint8_t rval = 0;

  while (length--) {
    uint8_t d = (*data ^ rval);
    for (int i = 0; i < 8; i++) {
      if (d & 0x80)
        d = (d << 1) ^ polynomial;
      else
        d = d <<= 1;
    }

    rval = d;
    data++;
  }

  return rval;
}

uint8_t crc_table (uint8_t* data, size_t length, uint8_t table[256])
{
  uint8_t rval = 0;
  while (length--) {
    rval = table[rval ^ *data];
    data++;
  }

  return rval;
}

void generate_table (uint8_t polynomial, uint8_t table[256])
{
  for (int i = 0; i < 256; i++) {
    uint8_t entry = i;

    for (int j = 0; j < 8; j++) {
      if (entry & 0x80)
        entry = (entry << 1) ^ polynomial;
      else
        entry <<= 1;
    }
    table[i] = entry;
  }
}

void generate_table_source (uint8_t polynomial)
{
  printf ("const uint8_t crc8_lut[256] = {\n");

  for (int i = 0; i < 256; i++) {
    uint8_t entry = i;

    for (int j = 0; j < 8; j++) {
      if (entry & 0x80)
        entry = (entry << 1) ^ polynomial;
      else
        entry <<= 1;
    }
    printf ("%02x", entry);
    if (i < 255)
      printf (", ");
    if ( (i + 1) % 12 == 0)
      printf ("\n");
  }
  printf ("};\n");
}


int main (void)
{
  uint8_t table[256];

  generate_table (CRC8_POLYNOMIAL, table);

  // test with a dead babe
  uint32_t x = 0xbebaadde;
  uint8_t* data = (uint8_t*) &x;
  generate_table_source (CRC8_POLYNOMIAL);
  printf ("data[0]=0x%02x\n", data[0]);
  printf ("data[1]=0x%02x\n", data[1]);
  printf ("data[2]=0x%02x\n", data[2]);
  printf ("data[3]=0x%02x\n", data[3]);
  printf ("crc_bitwise=0x%02x\n", crc_bitwise (data, 4, CRC8_POLYNOMIAL));
  printf ("crc_table=0x%02x\n", crc_table (data, 4, table));
}
