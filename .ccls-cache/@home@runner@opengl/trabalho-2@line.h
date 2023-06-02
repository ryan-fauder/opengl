#ifndef __LINE_H__
#define __LINE_H__

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  GLdouble x, y;
} Vertex;

typedef struct {
  Vertex start, end;
} Line;

Line createLine(Vertex start, Vertex end);
Vertex createVertex(GLdouble x, GLdouble y);
void setPixel(int xCoord, int yCoord);
void drawLine(Line line);
#endif 