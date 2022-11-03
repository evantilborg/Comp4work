CXX = g++
CXXFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window
DEPS = CircularBuffer.h StringSound.h stringsoundtest.cpp circularbuffertest.cpp
LINTFILES = CircularBuffer.cpp CircularBuffer.h KSGuitarSim.cpp StringSound.cpp StringSound.h stringsoundtest.cpp

all:KSGuitarSim ssboosttest cbboosttest lint 
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -I/opt/homebrew/Cellar/boost/1.78.0_1/include -c $<

KSGuitarSim: KSGuitarSim.o CircularBuffer.o StringSound.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -o $@ $^ $(LIBS)

ssboosttest: stringsoundtest.o CircularBuffer.o StringSound.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -o $@ $^ $(LIBS)

cbboosttest: circularbuffertest.o CircularBuffer.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -o $@ $^ $(LIBS)

lint: $(LINTFILES)
	cpplint $(LINTFILES)

clean:
	rm -f *.o 
	rm -f KSGuitarSim
	rm -f ssboosttest
