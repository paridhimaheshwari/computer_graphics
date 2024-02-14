#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

int windowHeight = 500;
int windowWidth = 500;
int ellipseXCenter = 250;
int ellipseYCenter = 250;
int ellipseA = 200; // Horizontal radius
int ellipseB = 100; // Vertical radius

void plotEllipsePoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x + ellipseXCenter, y + ellipseYCenter);
    glVertex2i(-x + ellipseXCenter, y + ellipseYCenter);
    glVertex2i(x + ellipseXCenter, -y + ellipseYCenter);
    glVertex2i(-x + ellipseXCenter, -y + ellipseYCenter);
    glEnd();
}

void drawEllipse() {
    int x = 0;
    int y = ellipseB;
    int a2 = ellipseA * ellipseA;
    int b2 = ellipseB * ellipseB;
    int twoA2 = 2 * a2;
    int twoB2 = 2 * b2;
    int xEnd = round(ellipseA * ellipseA / sqrt(a2 + b2));
    int p = round(b2 - (a2 * ellipseB) + (0.25 * a2));
    
    while (x <= xEnd) {
        plotEllipsePoints(x, y);
        if (p < 0) {
            p += twoB2 * (x + 1) + b2;
        } else {
            y--;
            p += twoB2 * (x + 1) - twoA2 * (y - 1) + b2;
        }
        x++;
    }
    
    p = round(b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2);
    while (y >= 0) {
        plotEllipsePoints(x, y);
        if (p > 0) {
            p += -twoA2 * (y - 1) + a2;
        } else {
            x++;
            p += twoB2 * x - twoA2 * (y - 1) + a2;
        }
        y--;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // White color
    drawEllipse();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Midpoint Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
