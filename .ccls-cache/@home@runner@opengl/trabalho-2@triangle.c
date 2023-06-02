#include "triangle.h"

Vertex createVertex(GLdouble x, GLdouble y) {
  Vertex a;
  a.x = x;
  a.y = y;
  return a;
}
Triangle createTriangle(Vertex first, Vertex second, Vertex third) {
  Triangle triangle;
  triangle.vertices[0] = first;
  triangle.vertices[1] = second;
  triangle.vertices[2] = third;
  return triangle;
}

void rotateTriangle(Triangle *triangle, GLdouble theta) {
  int k;
  for (k = 0; k < 3; k++) {
    triangle->vertices[k].x = (triangle->vertices[k].x) * cos(theta) -
                              (triangle->vertices[k].y) * sin(theta);

    triangle->vertices[k].y = (triangle->vertices[k].x) * sin(theta) +
                              (triangle->vertices[k].y) * cos(theta);
  }
}

void scaleTriangle(Triangle *triangle, GLdouble scaleX, GLdouble scaleY) {
  int index;
  for (index = 0; index < 3; index++) {
    triangle->vertices[index].x *= scaleX;
    triangle->vertices[index].y *= scaleY;
  }
}

void translateTriangle(Triangle *triangle, GLdouble tx, GLdouble ty) {
  int i;

  for (i = 0; i < 3; i++) {
    triangle->vertices[i].x += tx;
    triangle->vertices[i].y += ty;
  }
}

void drawTriangle(Triangle triangle) {
  int index;
  for (index = 0; index < 3; index++) {
    int currentIndex = index % 3;
    int nextIndex = (index + 1) % 3;
    glBegin(GL_LINES);
    glVertex2i(triangle.vertices[currentIndex].x,
               triangle.vertices[currentIndex].y);
    glVertex2i(triangle.vertices[nextIndex].x, triangle.vertices[nextIndex].y);
    glEnd();
  }
}
