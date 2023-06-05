#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Daire çizmek için fonksiyon
void drawCircle(float radius, int numSegments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Merkez noktası

    // Renkli segmentler
    for (int i = 0; i <= numSegments; i++)
    {
        float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);

        // Renkleri rastgele belirle
        float red = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float green = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float blue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

        glColor3f(red, green, blue);
        glVertex2f(x, y);
    }

    glEnd();
}

// Ekrana çizim işlemini yapacak fonksiyon
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0.0f); // Merkezi ekrana yerleştirme

    float circleRadius = 200.0f;
    int numSegments = 100;
    drawCircle(circleRadius, numSegments);

    glFlush();
}

// Ekran boyutu değiştiğinde çağrılan fonksiyon
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Renkli Daire");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();

    return 0;
}
