CXX = g++
CXXFLAGS = --std=c++11 --std=c++14 -Wall -Werror -pedantic
OBJECTS = FibLFSR.o test.o
TESTOBJ = FibLFSR.o main.o
LDLIBS = -lboost_unit_test_framework

all: ps1a main

ps1a: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o ps1a $(OBJECTS) $(LDLIBS)
FibLFSR.o: FibLFSR.cpp
	$(CXX) $(CXXFLAGS) -c FibLFSR.cpp -o FibLFSR.o
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

main: $(TESTOBJ)
	$(CXX) $(CXXFLAGS) -o main $(TESTOBJ)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	-rm ps1a main *.o