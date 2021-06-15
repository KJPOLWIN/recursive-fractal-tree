SFMLINC = D:\SFML-2.5.1\include
SFMLLIB = D:\SFML-2.5.1\lib
SFML = -lsfml-graphics -lsfml-window -lsfml-system
HEADER = ./includes/
SOURCE = ./source/

TITLE = Fractal_tree

OPTIONS = -std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion -Wpedantic

OBJ = main.o

output: $(OBJ)
	g++ $(OBJ) -o $(TITLE).exe -L$(SFMLLIB) -mwindows -static-libstdc++ $(SFML)
	
debug: $(OBJ)
	g++ $(OBJ) -g -o $(TITLE)-debug.exe -L$(SFMLLIB) -static-libstdc++ $(SFML)

main.o: $(SOURCE)main.cpp
	g++ -c $(SOURCE)main.cpp $(OPTIONS) -isystem $(SFMLINC) -I./includes