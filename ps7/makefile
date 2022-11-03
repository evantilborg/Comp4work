CXX = g++
CXXFLAGS = -g -Wall -Werror -pedantic --std=c++17
LIBS = -lboost_regex -lboost_date_time
LINTFILES = main.cpp 

all:ps7 lint 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I/opt/homebrew/Cellar/boost/1.78.0_1/include -c $<

ps7: main.o
	$(CXX) $(CXXFLAGS) -L/opt/homebrew/Cellar/boost/1.78.0_1/lib -o $@ $^ $(LIBS)

lint: $(LINTFILES)
	cpplint $(LINTFILES)

clean:
	rm -f *.o
	rm -f ps7
