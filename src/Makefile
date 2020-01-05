CXX=gcc
CXXFLAGS=-Wall -Wextra -Wpedantic
qr: main.o setup.o
	$(CXX) main.o setup.o -o qr

main.o: main.c settings.h
	$(CXX) $(CXXFLAGS) -c main.c

setup.o: setup.c settings.h
	$(CXX) $(CXXFLAGS) -c setup.c
