CXX=g++
CXXFLAGS=-O2 -c -std=c++11 -Wall
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE= simulation

all: $(SOURCES) $(EXECUTABLE) cleanobj

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

cleanobj:
	rm -rf $(OBJECTS)

rebuild: clean $(EXECUTABLE) cleanobj
