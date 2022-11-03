CXX =g++
CXXFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
DEPS = Triangle.h
all: TFractal

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -c $<

TFractal: TFractal.o Triangle.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -o $@ $^ $(LIBS)

clean:
	rm -f *.o
	rm -f TFractal
