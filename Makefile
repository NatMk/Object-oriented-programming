
# Makefile for robots
CXXFLAGS = -std=c++11
LDFLAGS = -L/usr/local/lib -lfltk -lXext -lX11 -lm

all: gui

debug: CXXFLAGS += -g
debug: gui

rebuild: clean gui

gui: main.cpp
	$(CXX) $(CXXFLAGS) $(fltk-config --cxxflags) -o gui main.cpp $(LDFLAGS)

clean:
	-rm -f *.o gui cli




