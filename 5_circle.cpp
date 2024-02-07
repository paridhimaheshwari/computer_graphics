// WAP to draw a circle using Bresenham and then mid-point circle algorithm
#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include <cmath>
#include <vector>
// using namespace std;

// Function to draw a circle using Bresenham's algorithm
void drawCircleBresenham(int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    
    std::vector<std::pair<int, int> > points;
    
    while (x <= y) {
        points.push_back(std::make_pair(x, y));
        points.push_back(std::make_pair(y, x));
        points.push_back(std::make_pair(-x, y));
        points.push_back(std::make_pair(-y, x));
        points.push_back(std::make_pair(-x, -y));
        points.push_back(std::make_pair(-y, -x));
        points.push_back(std::make_pair(x, -y));
        points.push_back(std::make_pair(y, -x));
        
        if (d < 0)
            d += 4 * x++ + 6;
        else
            d += 4 * (x++ - y--) + 10;
    }

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    for (auto point : points) {
        glVertex2i(point.first, point.second);
    }
    glEnd();
}

// Function to draw a circle using midpoint circle algorithm
void drawCircleMidpoint(int radius) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    
    std::vector<std::pair<int, int> > points;
    
    while (x <= y) {
        points.push_back(std::make_pair(x, y));
        points.push_back(std::make_pair(y, x));
        points.push_back(std::make_pair(-x, y));
        points.push_back(std::make_pair(-y, x));
        points.push_back(std::make_pair(-x, -y));
        points.push_back(std::make_pair(-y, -x));
        points.push_back(std::make_pair(x, -y));
        points.push_back(std::make_pair(y, -x));
        
        if (d < 0)
            d += 2 * x++ + 3;
        else
            d += 2 * (x++ - y--) + 5;
    }

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);
    for (auto point : points) {
        glVertex2i(point.first, point.second);
    }
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw circle using Bresenham's algorithm
    drawCircleBresenham(50);
    
    // Draw circle using midpoint circle algorithm
    // drawCircleMidpoint(50);
    
    glFlush();
}

// Initialize OpenGL
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Circle Drawing Algorithms");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
