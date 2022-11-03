CXX = g++
CXXFLAGS = -Wall -Werror -pedantic --std=c++17
LIBS = -lboost_unit_test_framework
DEPS = CircularBuffer.h test.cpp
LINTFILES = CircularBuffer.cpp CircularBuffer.h test.cpp

all:ps4a lint
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I/opt/homebrew/Cellar/boost/1.78.0_1/include -c $<


ps4a: test.o CircularBuffer.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -o $@ $^ $(LIBS)

lint: $(LINTFILES)
	cpplint $(LINTFILES)

clean:
	rm -f *.o 
	rm -f ps4a
