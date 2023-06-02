#include "line.h"
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

  lineBres(0, 0, 6, 6);

  glFlush();
}