
all: GPUEngine

run:
	./GPUEngine.exe

Engine.o: Engine.cpp
	g++ Engine.cpp -c -o Engine.o -I./src/headers -I./external

Window.o: src/Window.cpp
	g++ src/Window.cpp -c -o Window.o -I./src/headers -I./external

GLshader.o: src/GLshader.cpp
	g++ src/GLshader.cpp -c -o GLshader.o -I./src/headers -I./external

GLviewport.o: src/GLviewport.cpp
	g++ src/GLviewport.cpp -c -o GLviewport.o -I./src/headers -I./external

GPUEngine: Engine.o Window.o GLshader.o GLviewport.o
	g++ Engine.o Window.o GLshader.o GLviewport.o external/glad.c -o GPUEngine.exe -lglfw3 -lm -I./external

clean:
	rm -f *.o GPUEngine.exe