#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.85f, -0.2f);
        glVertex2f(-0.3f, 0.5f);
        glVertex2f(0.85f, -0.2f);
        glVertex2f(0.3f, -0.9f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("opengl");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
