CXX = g++
CXXFLAGS = --std=c++11 --std=c++14 -Wall -Werror -pedantic
OBJECTS = FibLFSR.o photomagic.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: photomagic

photomagic: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o photomagic $(OBJECTS) $(SFML)
photomagic.o: photomagic.cpp
	$(CXX) $(CXXFLAGS) -c photomagic.cpp -o photomagic.o 
FibLFSR.o: FibLFSR.cpp
	$(CXX) $(CXXFLAGS) -c FibLFSR.cpp -o FibLFSR.o

clean:
	-rm photomagic *.o