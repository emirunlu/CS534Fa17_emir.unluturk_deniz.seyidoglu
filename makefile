appname := cartagena

CXX := g++
CXXFLAGS := -std=c++11 -Wall

srcfiles := $(shell find . \
				! -name "gameState.cpp" \
				! -name "imageManager.cpp" \
				! -name "menuState.cpp" \
				! -name "sdl.cpp" \
				! -name "stateManager.cpp" \
				! -name "tcpcon.cpp" \
				-name "*.cpp")
objects  := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) -o $(appname) $(objects)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend