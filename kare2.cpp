#include <GL/glut.h>

float scale = 1.0;

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glScalef(scale, 1.0, 1.0);

    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void update(int value)
{
    scale += 0.01;

    if (scale > 2.0)
    {
        scale = 1.0;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Kare");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(renderScene);
    glutTimerFunc(10, update, 0);

    glutMainLoop();

    return 0;
}
