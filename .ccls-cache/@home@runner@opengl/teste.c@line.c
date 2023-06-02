#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

void setPixel(int xCoord, int yCoord) {
  glBegin(GL_POINTS);
  glVertex2i(xCoord, yCoord);
  glEnd();
}

void lineBres(int x0, int y0, int xEnd, int yEnd) {
  int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
  int p = 2 * dy - dx;
  int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
  int x, y;
    
  if (x0 > xEnd) {
    x = xEnd;
    y = yEnd;
    xEnd = x0;
  } else {
    x = x0;
    y = y0;
  }

  setPixel(x, y);
  while (x < xEnd) {
    x += 0.1;
    if (p < 0)
      p += twoDy;
    else {
      y += 0.1;
      p += twoDyMinusDx;
    }
    setPixel(x, y);
  }
}