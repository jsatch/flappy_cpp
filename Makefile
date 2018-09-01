CXX = g++
SDL = -framework SDL2 -framework SDL2_image
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
EXE = flappybird

output: flappybird.cpp screenmanager.o
	$(CXX) flappybird.cpp $(LDFLAGS) -o $(EXE)

screenmanager.o: screenmanager.h screenmanager.cpp
	$(CXX) -c screenmanager.cpp 

clean:
	rm *.o  $(EXE)