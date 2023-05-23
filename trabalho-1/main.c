#include "triangle.h"

void display(void);

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(10, 50);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("Transformacoes");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
void display(void) {
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0, 0, 0, 0);
  gluOrtho2D(-10, 10, -10, 10);
  glColor3f(1.0, 0.0, 0.0);

  Vertex v1 = createVertex(1, 1);
  Vertex v2 = createVertex(2, 0);
  Vertex v3 = createVertex(0, 0);
  Triangle t = createTriangle(v1, v2, v3);
  drawTriangle(t);

  glColor3f(0.0, 1.0, 1.0);
  translateTriangle(&t, -5, -5);
  drawTriangle(t);

  glColor3f(0.0, 1.0, 0.0);
  scaleTriangle(&t, 2, 2);
  drawTriangle(t);

  glColor3f(0.0, 0.0, 1.0);
  rotateTriangle(&t, 3.14);
  drawTriangle(t);

  glFlush();
}