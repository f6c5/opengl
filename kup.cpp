#include <GL/glut.h>

GLfloat angle = 0.0f;

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(angle, 1.0f, 1.0f, 1.0f);

    // Köşe noktalarını tanımla
    GLfloat vertices[] = {-0.5, -0.5, -0.5, // 0
                           0.5, -0.5, -0.5, // 1
                           0.5,  0.5, -0.5, // 2
                          -0.5,  0.5, -0.5, // 3
                          -0.5, -0.5,  0.5, // 4
                           0.5, -0.5,  0.5, // 5
                           0.5,  0.5,  0.5, // 6
                          -0.5,  0.5,  0.5};// 7

    // Yüzeyleri belirle
    GLuint indices[] = {0, 1, 2, 3, // Ön yüz
                        1, 5, 6, 2, // Sağ yüz
                        4, 5, 6, 7, // Arka yüz
                        0, 4, 7, 3, // Sol yüz
                        0, 4, 5, 1, // Alt yüz
                        3, 7, 6, 2};// Üst yüz

    // Küpü çiz
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glEnableClientState(GL_VERTEX_ARRAY);

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_VERTEX_ARRAY);

    angle += 0.1f; // Küpü döndür

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dönen Küp");

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}
