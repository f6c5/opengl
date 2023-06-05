#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0f, 1.0f, 0.5f);
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.0f, 0.0f); // Kırmızı
  glVertex3f(0.0f, 0.0f, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f); // Yeşil
  glVertex3f(1.0f, 0.0f, 0.0f);
  glColor3f(0.0f, 0.0f, 1.0f); // Mavi
  glVertex3f(0.0f, 1.0f, 0.0f);
  glTranslatef(1.0f, 1.0f, 0.0f); // X ve Y ekseninde 1 birim kaydırma
  glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // Z ekseninde 45 derece dönme
  glScalef(2.0f, 2.0f, 2.0f); // Ölçeklendirme

  glEnd();

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutCreateWindow("opengl");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
