#include <GL/glut.h>
#include <iostream>

using namespace std;
void init(void) {
glClearColor(1.0, 1.0, 1.0, 0.0); // set display window color to white. 
glMatrixMode(GL_PROJECTION); // set projection parameters
gluOrtho2D(0.0, 200.0, 0.0, 150.0); // define rectangular area of world coordinates                                 
// to screen. Anything outside will not be displayed
}
void lineSegment(void){
glClear(GL_COLOR_BUFFER_BIT); // clear display window glColor3f(0.0, 0.4, 0.2); // set line segment color to green
glBegin(GL_LINES);
glVertex2i(180, 15); // specify the line segment geometry 
glVertex2i(10, 145);
glVertex2i(190, 55); // specify the line segment geometry glVertex2i(100, 125);
glBegin(GL_POLYGON);
glVertex2i(100, 10);
glVertex2i(10, 105);
glVertex2i(190, 55); // specify the line segment geometry glVertex2i(100, 185);
glEnd();
glFlush(); // process all OpenGL routines as quiclky as possible
}
void main(int argc, char** argv)
{
glutInit(&argc, argv); // Initialise GLUT 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode 
glutInitWindowPosition(100, 100); // set top left display window position 
glutInitWindowSize(400, 300); // set display window width and height 
glutCreateWindow(" An Example OpenGL first class"); // create display window 
init(); // Execute Initialisation Procedure 
glutDisplayFunc(lineSegment); // Send graphics to display window 
glutMainLoop(); // Display everything and wait
}