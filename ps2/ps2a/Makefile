CXX = g++
CXXFLAGS = --std=c++11 --std=c++14 -Wall -Werror -pedantic
OBJECTS = CelestialBody.o Universe.o main.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: NBody

NBody: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o NBody $(OBJECTS) $(SFML)
Universe.o: Universe.cpp
	$(CXX) $(CXXFLAGS) -c Universe.cpp -o Universe.o
CelestialBody.o: CelestialBody.cpp
	$(CXX) $(CXXFLAGS) -c CelestialBody.cpp -o CelestialBody.o 
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	-rm NBody *.o