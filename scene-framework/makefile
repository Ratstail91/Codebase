CXXFLAGS+=-std=c++11
DFLAGS=-DDEBUG
LIB=-lmingw32 -lSDLmain -lSDL
OBJ=base_scene.o scene_manager.o main.o
SRC=example.cpp

all: debug

release: $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) $(OBJ) $(LIB)

debug: $(OBJ)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(SRC) $(OBJ) $(LIB)

clean:
	-$(RM) *.o *.a *.exe
