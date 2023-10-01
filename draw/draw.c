#include <X11/Xlib.h>
#include <stdio.h>
#include <err.h>
#include "draw.h"

static Display* dpy;
static int scr;
static Window root;
static Window window;
static GC graphicsContext;

#define POSX 500
#define POSY 500
#define WIDTH 500
#define HEIGHT 500
#define BORDER 15

void open_window()
{
	Window win;
	XEvent ev;
	if ((dpy = XOpenDisplay(NULL)) == NULL)
		err(1, "Can not open display");
	scr = DefaultScreen(dpy);
	root = RootWindow(dpy, scr);

	win = XCreateSimpleWindow(dpy, root, POSX, POSY, WIDTH, HEIGHT, BORDER, BlackPixel(dpy, scr), WhitePixel(dpy, scr));
	XMapWindow(dpy, win);
	window = win;
	graphicsContext  = XCreateGC(dpy, window, 0, 0);
}

void close_window()
{
	XUnmapWindow(dpy, window);
	XDestroyWindow(dpy, window);
	XCloseDisplay(dpy);
}



void draw_point(int x, int y, short red, short green, short blue)
{
	unsigned long color = (red << 16) | (green << 8) | blue;
	XSetForeground(dpy, graphicsContext, color);
	XDrawPoint(dpy, window, graphicsContext, x, y);
}
