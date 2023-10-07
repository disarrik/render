build: math/math.o render/render.o draw/draw.o light/light.o main.c
	gcc -lX11 -lm -ggdb light/light.o math/math.o render/render.o draw/draw.o main.c -o main 

math/math.o: math/math.h math/math.c
	gcc -c -ggdb math/math.c -o math/math.o

draw/render.o: draw/draw.h draw/draw.c
	gcc -c -ggdb draw/draw.c -o draw/draw.o

render/render.o: render/render.h render/render.c
	gcc -c -ggdb render/render.c -o render/render.o

light/light.o: light/light.h light/light.c
	gcc -c -ggdb light/light.c -o light/light.o

clear:
	rm render/render.o draw/draw.o math/math.o light/light.o main 