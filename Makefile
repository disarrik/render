build: render/render.o draw/draw.o main.c
	gcc -lX11 -lm render/render.o draw/draw.o main.c -o main 

draw/render.o: draw/draw.h draw/draw.c
	gcc -c draw/draw.c -o draw/draw.o

render/render.o: render/render.h render/render.c
	gcc -c render/render.c -o render/render.o

clear:
	rm render/render.o main