all: compile link
compile:
	g++ -Iinclude/ -c src/*.cpp
link:
	g++ -o main *.o -Llib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	del *.o