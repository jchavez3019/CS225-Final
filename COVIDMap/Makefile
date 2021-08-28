CC = g++
CFLAGS = -Wall -g

COVIDMap: main.o ReadFile.o MapOutput.o hashes.o
	$(CC) $(CFLAGS) -o COVIDMap main.o ReadFile.o MapOutput.o hashes.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -std=c++11 -c main.cpp

ReadFile.o: ReadFile.cpp 
	$(CC) $(CFLAGS) -std=c++11 -c ReadFile.cpp 

MapOutput.o: MapOutput.cpp 
	$(CC) $(CFLAGS) -std=c++11 -c MapOutput.cpp 
hashes.o: hashes.cpp
	$(CC) $(CFLAGS) -std=c++11 -c hashes.cpp 

# Use the cs225 makefile template:
include cs225/make/cs225.mk

