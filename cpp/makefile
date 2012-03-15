.phony: all clean

all: crc8

clean:
	rm -f crc8 *.o *.orig

crc8: main.o
	$(CXX) -o $@ $+

main.o: main.cpp crc8.h crc8.ipp hex_output.h

