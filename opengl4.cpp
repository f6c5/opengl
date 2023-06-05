#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.8f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.8f);
        glVertex2f(-0.5f, 0.8f);
        glVertex2f(0.5f, 0.8f);
        glVertex2f(0.5f, -0.8f);
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


