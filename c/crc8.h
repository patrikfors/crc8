#ifndef CRC8__H
#define CRC8__H

#include <stdint.h>
#include <stdlib.h> // size_t

void generate_table (uint8_t polynomial, uint8_t table[256]);
uint8_t crc_table (uint8_t* data, size_t length, uint8_t table[256]);
uint8_t crc_bitwise (uint8_t* data, size_t length, uint8_t polynomial);

#endif /* CRC8__H */
