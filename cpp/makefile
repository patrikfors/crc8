CC=gcc
CXXFLAGS=-g -DMAIN

.phony: all clean

all: crc8

clean:
	rm -f crc8 *.o *.orig

crc8: main.o
	$(CXX) -o $@ $+

main.o: crc8.h crc8.ipp
