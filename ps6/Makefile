CXX = g++
CXXFLAGS = -g -Wall -Werror -pedantic --std=c++17
LIBS = -lboost_unit_test_framework
DEPS = RandWriter.h
LINTFILES = RandWriter.h RandWriter.cpp TextWriter.cpp test.cpp

all:TextWriter BoostTest lint 
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -I/opt/homebrew/Cellar/boost/1.78.0_1/include -c $<

TextWriter: TextWriter.o RandWriter.o
	$(CXX) $(CXXFLAGS) -o $@ $^

BoostTest: test.o RandWriter.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -o $@ $^ $(LIBS)

lint: $(LINTFILES)
	cpplint $(LINTFILES)

clean:
	rm -f *.o
	rm -f TextWriter
	rm -f BoostTest
