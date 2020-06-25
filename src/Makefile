HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))
DEPS=$(patsubst %.o, %.d, $(OBJECTS))

TARGETS=a.out

COMPILE_FLAGS=-std=c++1z -g -O0 -Wall
LINK_FLAGS=

CXX=g++

all: $(TARGETS)

$(TARGETS): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LINK_FLAGS)

-include $(DEP)

.cpp.o:
	$(CXX) $(COMPILE_FLAGS) -MMD -c $<

.PHONY: clean
clean:
	rm -f $(TARGETS) $(OBJECTS) $(DEPS)
