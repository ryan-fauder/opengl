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
  gluOrtho2D(-500, 500, -500, 500);
  
  Vertex start1 = createVertex(0, 0);
  Vertex end1 = createVertex(150, 80);
  Line l1 = createLine(start1, end1);
  glColor3f(1.0, 0.0, 0.0); // Vermelho
  drawLine(l1);
  glFlush();
  
  Vertex start2 = createVertex(0, 0);
  Vertex end2 = createVertex(-150, 80);
  Line l2 = createLine(start2, end2);
  glColor3f(0.0, 0.0, 1.0); // Verde
  drawLine(l2);
  glFlush();

  start2 = createVertex(0, 0);
  end2 = createVertex(-80, 150);
  l2 = createLine(start2, end2);
  glColor3f(1.0, 1.0, 0.0); // Verde
  drawLine(l2);
  glFlush();

  start2 = createVertex(0, 0);
  end2 = createVertex(-100, -100);
  l2 = createLine(start2, end2);
  glColor3f(0.0, 1.0, 0.0); // Verde
  drawLine(l2);
  glFlush();

  start2 = createVertex(0, 0);
  end2 = createVertex(100, -150);
  l2 = createLine(start2, end2);
  glColor3f(0.0, 1.0, 1.0); // Verde
  drawLine(l2);
  glFlush();

  start2 = createVertex(0, 500);
  end2 = createVertex(0, -500);
  l2 = createLine(start2, end2);
  glColor3f(1.0, 1.0, 1.0); // Verde
  drawLine(l2);
  glFlush();

  start2 = createVertex(500, 0);
  end2 = createVertex(-500, 0);
  l2 = createLine(start2, end2);
  glColor3f(1.0, 1.0, 1.0); // Verde
  drawLine(l2);
  glFlush();
}

