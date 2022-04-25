#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(10, 233);
glVertex2i(122, 233);
glVertex2i(122, 10);
glVertex2i(10, 10);
glEnd();

glColor3ub (255,255,255);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(123, 233);
glVertex2i(346, 233);
glVertex2i(346, 10);
glVertex2i(123, 10);
glEnd();

glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(347, 234);
glVertex2i(457, 234);
glVertex2i(457, 10);
glVertex2i(347, 10);
glEnd();

glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(236, 30);
glVertex2i(188, 182);
glVertex2i(235, 173);
glVertex2i(282, 180);
glEnd();

glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(210, 105);
glVertex2i(260, 103);
glVertex2i(200, 54);
glEnd();

glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(210, 105);
glVertex2i(260, 103);
glVertex2i(272, 55);
glEnd();

glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(234, 165);
glVertex2i(230, 221);
glVertex2i(238, 220);
glEnd();

glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(250, 112);
glVertex2i(286, 86);
glVertex2i(290, 97);
glVertex2i(317, 90);
glVertex2i(310, 121);
glVertex2i(322, 127);
glVertex2i(270, 170);
glEnd();

glColor3ub (255,0,0);
glPointSize(10.0);
glBegin(GL_POLYGON);
glVertex2i(216, 112);
glVertex2i(181, 82);
glVertex2i(180, 95);
glVertex2i(150, 90);
glVertex2i(157, 120);
glVertex2i(140, 128);
glVertex2i(202, 170);
glEnd();


glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 480.0, 0.0);
}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Canada Flag");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
