include Make_linux.inc
#include Make_msys2.inc
#include Make_osx.inc

CXXFLAGS = -std=c++17 `sdl2-config --cflags`
ifdef DEBUG
CXXFLAGS += -g -O0 -Wall -fbounds-check -pedantic -D_GLIBCXX_DEBUG -DDEBUG
else
CXXFLAGS += -O3 -march=native -Wall
endif

INCLUDES = -I./header #pour dire que les .h sont dans le dossier header
OBJ_SIM = Simulation/centrale.o Simulation/circuit.o Simulation/circuitPrimaire.o Simulation/circuitSecondaire.o Simulation/reacteur.o Simulation/RND.o

default : $(OBJ_SIM)

clean :
	@rm -fr *.o *.exe Simulation/*.o Simulation/*~

test.exe : test.o Simulation/circuit.o 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o test.exe test.o Simulation/circuit.o 

test.o : test.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c test.cpp -o test.o





Simulation/centrale.o : Simulation/centrale.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Simulation/centrale.cpp -o Simulation/centrale.o

Simulation/circuit.o : Simulation/circuit.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Simulation/circuit.cpp -o Simulation/circuit.o

Simulation/circuitPrimaire.o : Simulation/circuitPrimaire.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Simulation/circuitPrimaire.cpp -o Simulation/circuitPrimaire.o

Simulation/circuitSecondaire.o : Simulation/circuitSecondaire.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Simulation/circuitSecondaire.cpp -o Simulation/circuitSecondaire.o

Simulation/reacteur.o : Simulation/reacteur.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Simulation/reacteur.cpp -o Simulation/reacteur.o

Simulation/RND.o : Simulation/RND.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Simulation/RND.cpp -o Simulation/RND.o



