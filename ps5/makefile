CXX = g++
CXXFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-system
DEPS = EDistance.h
LINTFILES = EDistance.h EDistance.cpp main.cpp

all:EDistance lint 
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

EDistance: main.o EDistance.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)

lint: $(LINTFILES)
	cpplint $(LINTFILES)

clean:
	rm -f *.o
	rm -f EDistance
