CXX =g++
CXXFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEPS = CelestialBody.h Universe.h
all: NBody

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

NBody: main.o CelestialBody.o Universe.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f NBody
