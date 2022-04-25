#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float x,y,i;
float counter=0.0;
float hr=0.0;
float mn=0.0;

void init(void)
{
	//gluOrtho2D(0,800,400,0);
	//glOrtho(0,800,500,0,1,-1);
}
void fan(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPointSize(10.0);
	//glLoadIdentity();
	 glLoadIdentity();
	 glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0,0,255);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.23*sin(i);
			y=0.23*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
	 glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0,0,0);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.2*sin(i);
			y=0.2*cos(i);
			glVertex2f(x,y);
		}
	glEnd();

glPushMatrix();
	glRotatef(counter,0.0,0.0,-1.0);
	counter+=0.5;
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex2f(0,0);
		glVertex2f(0,0.123);
		glVertex2f(0.01,0.123);
		glVertex2f(0.01,0.0);
		glEnd();
		glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);
    glRotatef(mn,0.0,0.0,-1.0);
	mn+=0.0083;
		glColor3ub(255,255,255);
		glVertex2f(0,0);
		glVertex2f(0.12,0.0);
		glVertex2f(0.12,-0.031);
		glVertex2f(0,-0.031);
		glEnd();
glPopMatrix();

glPushMatrix();
glBegin(GL_POLYGON);
		glRotatef(hr,0.0,0.0,-1.0);
        hr+=0.0001;
		glColor3ub(255,255,255);
		glVertex2f(0,0);
		glVertex2f(0,0.1);
		glVertex2f(0.02,0.1);
		glVertex2f(0.02,0.0);
		glPopMatrix();

	glEnd();


	glutSwapBuffers();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(-1,-1);
	glutInitWindowSize(640,480);
	glutCreateWindow("Fan");
	init();
	glutDisplayFunc(fan);
	glutIdleFunc(fan);
	glutMainLoop();
	return 0;
}
