#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include "line.h"

Line createLine(Vertex start, Vertex end){
  Line l;
  l.start = start;
  l.end = end;
  return l;
}

Vertex createVertex(GLdouble x, GLdouble y) {
  Vertex v;
  v.x = x;
  v.y = y;
  return v;
}

void setPixel(int xCoord, int yCoord) {
  glBegin(GL_POINTS);
  glVertex2i(xCoord, yCoord);
  glEnd();
}

void drawLine(Line line) {
  int xi = line.start.x;
  int yi = line.start.y;
  int xf = line.end.x;
  int yf = line.end.y;
  int dx = fabs(xf - xi), dy = fabs(yf - yi);
  int x_inc = 1;
  int y_inc = 1;
  int controle = 0;
  
  if (xf < xi)
    x_inc = -1;
  if (yf < yi)
    y_inc = -1;

  int x, y;
  x = xi;
  y = yi;

  setPixel(x, y);

  if (dx == 0) {
    while (y != yf) {
      y += y_inc;
      setPixel(x, y);
    }
  } else if (dy == 0) {
    while (x != xf) {
      x += x_inc;
      setPixel(x, y);
    }
  } else {
    if (dx >= dy) {
      controle = dx / 2;
      setPixel(x, y);
      while (x != xf) {
        x += x_inc;
        controle = controle - dy;
        if (controle < 0) {
          y += y_inc;
          controle += dx;
        }
        setPixel(x, y);
      }

    } else {
      controle = dy / 2;
      setPixel(x, y);
      while (y != yf) {
        y += y_inc;
        controle = controle - dx;
        if (controle < 0) {
          x += x_inc;
          controle += dy;
        }
        setPixel(x, y);
      }
    }
  }
}