#include<iostream>
#include<gl/glut.h>

void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(1000, 200);
	glutCreateWindow("Simple Window");
}

// Empty Display
void displayWindow() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

// POINT
void displayPoint() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0f);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POINTS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();

	glFlush();
}

// Line
void displayLine() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0f);
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glEnd();
	glFlush();
}

// Rectangle
void displayRectangle() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10.0f);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glEnd();

	glFlush();
}

//TRIANGLE
void displayTriangle() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glEnd();

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(displayTriangle);
	glutMainLoop();
	return 0;
}