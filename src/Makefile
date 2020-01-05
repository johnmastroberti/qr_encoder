CXX=gcc
CXXFLAGS=-Wall -Wextra -Wpedantic
qr: main.o
	$(CXX) main.o -o qr

main.o: main.c
	$(CXX) $(CXXFLAGS) -c main.c
