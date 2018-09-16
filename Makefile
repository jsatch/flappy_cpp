CXX = g++
SDL = -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 
SDL_IMAGE = -framework SDL2_image
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -std=c++11
LDFLAGS = $(SDL) $(SDL_IMAGE)
EXE = flappybird

output: flappybird.cpp screenmanager.o screen.o screen_menu.o sprites.o screen_play.o
	$(CXX) flappybird.cpp screenmanager.o screen.o screen_menu.cpp sprites.o screen_play.o $(LDFLAGS) $(CXXFLAGS)  -o $(EXE)

screen.o: screen.h screen.cpp
	$(CXX) -c screen.cpp $(CXXFLAGS) $(LDFLAGS)

screenmanager.o: screenmanager.h screenmanager.cpp
	$(CXX) -c screenmanager.cpp  $(LDFLAGS) $(CXXFLAGS)

screen_menu.o: screen_menu.h screen_menu.cpp
	$(CXX) -c screen_menu.cpp  $(CXXFLAGS) $(LDFLAGS)

sprites.o: sprites.h sprites.cpp
	$(CXX) -c sprites.cpp  $(CXXFLAGS) $(LDFLAGS)

screen_play.o: screen_play.h screen_play.cpp
	$(CXX) -c screen_play.cpp  $(CXXFLAGS) $(LDFLAGS)

clean:
	rm *.o  $(EXE)