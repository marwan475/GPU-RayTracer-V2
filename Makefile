
all: GPUEngine

run:
	./GPUEngine.exe

Engine.o: Engine.cpp
	g++ Engine.cpp -c -o Engine.o -I./src/headers -I./external

Window.o: src/Window.cpp
	g++ src/Window.cpp -c -o Window.o -I./src/headers -I./external

GPUEngine: Engine.o Window.o
	g++ Engine.o Window.o external/glad.c -o GPUEngine.exe -lglfw3 -lm -I./external

clean:
	rm -f *.o GPUEngine.exe