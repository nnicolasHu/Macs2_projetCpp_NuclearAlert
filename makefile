#include Make_linux.inc
#include Make_msys2.inc
include Make_osx.inc

CXXFLAGS = -std=c++17 `sdl2-config --cflags`
ifdef DEBUG
CXXFLAGS += -g -O0 -Wall -fbounds-check -pedantic -D_GLIBCXX_DEBUG -DDEBUG
else
CXXFLAGS += -O3 -march=native -Wall
endif

LIBS = $(LIB) `sdl2-config --cflags` -lSDL2_ttf -lSDL2_image  `sdl2-config --libs` 

INCLUDES = -I./header #pour dire que les .h sont dans le dossier header
OBJ_SIM = Simulation/centrale.o Simulation/circuit.o Simulation/circuitPrimaire.o Simulation/circuitSecondaire.o Simulation/reacteur.o Simulation/RND.o Simulation/ouvriers.o
#les .o pour le dossier Simulation

OBJ_SDL = Graphic/SDL2/sdl2.o Graphic/SDL2/geometry.o Graphic/SDL2/window.o Graphic/SDL2/font.o Graphic/SDL2/event.o Graphic/SDL2/texte.o Graphic/SDL2/image.o Graphic/SDL2/formated_text.o
#les .o pour la SDL2

OBJ_GRAPH =  Graphic/Fenetre_acceuil.o Graphic/Commande.o Graphic/Choix_Niveau.o Graphic/Centrale_tab.o Niveau1.o Graphic/Cadre.o Graphic/Radioprotection_win.o Graphic/arrondi.o

default : testSquelette.exe 

clean :
	@rm -fr *.o *.exe Simulation/*.o Simulation/*~ Graphic/SDL2/*.o Graphic/SDL2/*~ Graphic/*.o Graphic/*~

testSquelette.exe : testSquelette.o $(OBJ_SDL)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o testSquelette.exe testSquelette.o $(OBJ_SDL) $(LIBS)

testSquelette.o : testSquelette.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c testSquelette.cpp -o testSquelette.o 

testSimulation.exe : testSimulation.o $(OBJ_SIM)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o testSimulation.exe testSimulation.o $(OBJ_SIM) 

testSimulation.o : testSimulation.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c testSimulation.cpp -o testSimulation.o


testGraphic.exe : testGraphic.o $(OBJ_SDL) $(OBJ_GRAPH) $(OBJ_SIM)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o testGraphic.exe testGraphic.o $(OBJ_SDL) $(OBJ_GRAPH) $(OBJ_SIM) $(LIBS) 

testGraphic.o : testGraphic.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c testGraphic.cpp -o testGraphic.o 

# .o pour les niveaux de jeu
Niveau1.o : Niveau1.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Niveau1.cpp -o Niveau1.o 


# .o pour les calculs/Simulations
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

Simulation/ouvriers.o : Simulation/ouvriers.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Simulation/ouvriers.cpp -o Simulation/ouvriers.o

#/ .o pour la SDL2
Graphic/SDL2/sdl2.o: Graphic/SDL2/sdl2.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/sdl2.cpp -o Graphic/SDL2/sdl2.o

Graphic/SDL2/geometry.o: Graphic/SDL2/geometry.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/geometry.cpp -o Graphic/SDL2/geometry.o

Graphic/SDL2/window.o: Graphic/SDL2/window.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/window.cpp -o Graphic/SDL2/window.o

Graphic/SDL2/font.o: Graphic/SDL2/font.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/font.cpp -o Graphic/SDL2/font.o

Graphic/SDL2/event.o : Graphic/SDL2/event.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/event.cpp -o Graphic/SDL2/event.o

Graphic/SDL2/texte.o : Graphic/SDL2/texte.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/texte.cpp -o Graphic/SDL2/texte.o

Graphic/SDL2/formated_text.o : Graphic/SDL2/formated_text.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/formated_text.cpp -o Graphic/SDL2/formated_text.o

Graphic/SDL2/image.o : Graphic/SDL2/image.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/SDL2/image.cpp -o Graphic/SDL2/image.o

# .o pour les fonctions de Graphic
Graphic/Fenetre_acceuil.o : Graphic/Fenetre_acceuil.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/Fenetre_acceuil.cpp -o Graphic/Fenetre_acceuil.o 

Graphic/Commande.o : Graphic/Commande.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/Commande.cpp -o Graphic/Commande.o 

Graphic/Choix_Niveau.o : Graphic/Choix_Niveau.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/Choix_Niveau.cpp -o Graphic/Choix_Niveau.o

Graphic/Centrale_tab.o : Graphic/Centrale_tab.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/Centrale_tab.cpp -o Graphic/Centrale_tab.o

Graphic/Cadre.o : Graphic/Cadre.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/Cadre.cpp -o Graphic/Cadre.o

Graphic/Radioprotection_win.o : Graphic/Radioprotection_win.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/Radioprotection_win.cpp -o Graphic/Radioprotection_win.o

Graphic/arrondi.o : Graphic/arrondi.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c Graphic/arrondi.cpp -o Graphic/arrondi.o