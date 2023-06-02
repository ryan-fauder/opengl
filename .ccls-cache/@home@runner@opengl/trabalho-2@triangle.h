#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  GLdouble x, y;
} Vertex;

typedef struct {
  Vertex vertices[3];
} Triangle;
Vertex createVertex(GLdouble x, GLdouble y);
Triangle createTriangle(Vertex first, Vertex second, Vertex third);
void translateTriangle(Triangle *triangle, GLdouble tx, GLdouble ty);
void drawTriangle(Triangle triangle);
void rotateTriangle(Triangle *triangle, GLdouble theta);
void scaleTriangle(Triangle *triangle, GLdouble scaleX, GLdouble scaleY);