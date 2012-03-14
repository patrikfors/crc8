CC=gcc
CXXFLAGS=-DMAIN

.phony: all clean

all: crc8

clean:
	rm -f crc8 *.o *.orig

crc8: crc8.o
	$(CXX) -o $@ $<
