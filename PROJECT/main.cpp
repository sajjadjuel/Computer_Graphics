#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;
float _move_car_1 = 0.00f;
float _speed_car_1 = 0.0025f;

float _move_car_2 = 0.00f;
float _speed_car_2 = 0.0025f;

float _move_car_3 = 0.00f;
float _speed_car_3 = 0.0025f;

float _move_train = 0.00f;
float _speed_train = 0.0025f;

float _move_ship = 0.00f;
float _speed_ship = 0.0025f;

float _move_sun = 1.00f;
float _move_cloud_1 = 0.00f;
float _move_cloud_2 = 0.00f;
float _move_boat = 0.00f;

bool isRain = false;

GLfloat i = 0.0f;
GLfloat r = 0.0f;
GLfloat position = 0.0f;
GLfloat speed = 0.02f;

void update_car_1(int value) {
    if(_speed_car_1>1.00f || _speed_car_1<0.00f)
    {
        _speed_car_1 = 0.0f;
    }
    _move_car_1 += _speed_car_1;
    if(_move_car_1-1.3 > 1.0)
    {
        _move_car_1 = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_car_2(int value) {
    if(_speed_car_2>1 || _speed_car_2<0)
    {
        _speed_car_2 = 0.0f;
    }
    _move_car_2 -= _speed_car_2;
    if(_move_car_2+1.3 < -1.0)
    {
        _move_car_2 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_2, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_car_3(int value) {
    if(_speed_car_3>1 || _speed_car_3<0)
    {
        _speed_car_3 = 0.0f;
    }
    _move_car_3 -= _speed_car_3;
    if(_move_car_3+1.3 < -1.0)
    {
        _move_car_3 = 1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_car_3, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_train(int value) {
    if(_speed_train>1 || _speed_train<0)
    {
        _speed_train = 0.0f;
    }
    _move_train -= _speed_train;
    if(_move_train+1.3 < -1.0)
    {
        _move_train = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_train, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_ship(int value) {
    if(_speed_ship>1 || _speed_ship<0)
    {
        _speed_ship = 0.0f;
    }
    _move_ship -= 0.0025;
    if(_move_ship +1.3 < -1.0)
    {
        _move_ship = 2.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_ship, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_sun(int value){
    _move_sun -= 0.00055f;
    if(_move_sun+1.0 < -1.0)
    {
        _move_sun = 1.3;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_sun, 0);
}

void update_cloud_1(int value) {
    _move_cloud_1 += 0.0025f;
    if(_move_cloud_1-1.3 > 1.0)
    {
        _move_cloud_1 = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_cloud_2(int value){
    _move_cloud_2 -= 0.0025f;
    if(_move_cloud_2+1.3 < -1.0)
    {
        _move_cloud_2 = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_cloud_2, 0);
}

void update_boat(int value) {
    _move_boat += 0.0025f;
    if(_move_boat-1.3 > 1.0)
    {
        _move_boat = -1.5;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update_boat, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update_plane(int value) {

    if(position > 1.6)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();

	glutTimerFunc(100, update_plane, 0);
}
void rainSound()
{

    PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);


}

void rainSoundOff()
{

    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
}
void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          update_car_1(0);
          update_car_2(0);
          update_car_3(0);
          update_train(0);
          update_ship(0);
          break;
        case GLUT_KEY_LEFT:
            isRain=true;
            rainSound();
            break;
      case GLUT_KEY_DOWN:
          exit(0);
          break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
      case 65: //A for Start the car-1 or increase speed
          _speed_car_1+=0.0025f;
          update_car_1(0);
          break;
      case 97: //A for decrease speed
          _speed_car_1-=0.0025f;
          update_car_1(0);
          break;
      case 66: //B for Start the car-2 or increase speed
          _speed_car_2+=0.0025f;
          update_car_2(0);
          break;
      case 98: //B for  car-2 -> Decrease speed
          _speed_car_2-=0.0025f;
          update_car_2(0);
          break;
      case 67: //C for Start the car-3 or increase speed
          _speed_car_3+=0.0025f;
          update_car_3(0);
          break;

      case 99: //c for car-3 -> decrease speed
          _speed_car_3-=0.0025f;
          update_car_3(0);
          break;

      case 84: //T for Start the Train or increase speed
          _speed_train+=0.0025f;
          update_train(0);
          break;
      case 116: //t for train -> decrease speed
          _speed_train-=0.0025f;
          update_train(0);
          break;

      case 83: //S for Start the Ship or increase speed
          _speed_ship+=0.0025f;
          update_ship(0);
          break;
      case 115: //s for ship -> decrease speed
          _speed_ship-=0.0025f;
          update_ship(0);
          break;
      case 82: //R for start Rain
          isRain=true;
          rainSound();
          break;
      case 114: //r for Stop rain
          isRain=false;
          rainSoundOff();


    }
}
void star()
{
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

}

void sky(){
    //Sky
    if(isRain==true)
    {
        glBegin(GL_QUADS);
        glColor3f(0.5647, 0.6196, 0.6235);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.50, 0.58, 0.60);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else
    {
    if(_move_sun<=1.00f && _move_sun>=0.90f){
        glClear (GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.922);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.90f && _move_sun>=0.55f){
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.55f && _move_sun>=0.35f){
        glBegin(GL_QUADS);
        glColor3f(0.000, 0.749, 1.000);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.961, 0.933);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }

    else if(_move_sun<0.35f && _move_sun>=0.25f){
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(1.000, 0.855, 0.725);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }

    else if(_move_sun<0.25f && _move_sun>=0.10f){
        glBegin(GL_QUADS);
        glColor3f(0.529, 0.808, 0.980);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else if(_move_sun<0.10f && _move_sun>=-0.10f){
        glBegin(GL_QUADS);
        glColor3f(1.000, 0.388, 0.278);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.957, 0.643, 0.376);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();
    }
    else{
        glBegin(GL_QUADS);
        glColor3f(0.412, 0.412, 0.412);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);

        glColor3f(0.8, 1.000, 1.000);
        glVertex2f(1.0, -0.05);
        glVertex2f(-1.0, -0.05);
        glEnd();

        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glTranslatef(0.80,1.05,0);
        glScalef(0.6,1,1);
        glColor3f(0.902, 0.902, 0.980);
        glBegin(GL_POLYGON);// moon
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.085;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
       //update_sun(0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.95,0.95,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.75,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.65,0.65,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.60,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.65,0.93,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.10,0.67,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.15,0.67,0);

        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.35,0.85,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.25,0.73,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.72,0.63,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.05,0.43,0);
        star();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(0.15,0.13,0);
        star();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(-0.15,0.88,0);
        star();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.65,0.73,0);
        star();
        glPopMatrix();
        //update_sun(0);
    }
    }
}

void field_1(){
    //field 1
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(1.0, -0.05);

    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0, -0.05);

    glColor3f(0.486, 0.988, 0.000);
    glVertex2f(-1.0, 0.135);

    glColor3f(0.498, 1.000, 0.000);
    glVertex2f(1.0, 0.135);

    glEnd();
}

void rail_track(){
    //Rail track
    glBegin(GL_QUADS);
    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(-1.0, 0.015);
    glVertex2f(-1.0, 0.030);
    glVertex2f(1.0, 0.030);
    glVertex2f(1.0, 0.015);

    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(-1.0, 0.080);
    glVertex2f(-1.0, 0.095);
    glVertex2f(1.0, 0.095);
    glVertex2f(1.0, 0.080);

    glColor3f(0.184, 0.310, 0.310);
    for(float i = -0.99; i<=1; i =i+0.03){
        glVertex2f(i,0.030);
        glVertex2f(i,0.080);
        glVertex2f(i+0.01, 0.080);
        glVertex2f(i+0.01, 0.030);
    }
    glEnd();
}

void train(){
    glColor3d(0.282, 0.239, 0.545);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.05, 0.065);
        glVertex2f(0.30, 0.065);
        glVertex2f(0.30, 0.26);
        glVertex2f(0.05, 0.26);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.07, 0.110);
        glVertex2f(0.28, 0.110);
        glVertex2f(0.28, 0.215);
        glVertex2f(0.07, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.17, 0.110);
        glVertex2f(0.18, 0.110);
        glVertex2f(0.18, 0.215);
        glVertex2f(0.17, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.07, 0.235);
        glVertex2f(0.28, 0.235);
        glVertex2f(0.28, 0.26);
        glVertex2f(0.07, 0.26);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.10,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.0, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.25,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.0, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glColor3d(0.275, 0.510, 0.706);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.30, 0.075);
        glVertex2f(0.35, 0.075);
        glVertex2f(0.35, 0.095);
        glVertex2f(0.30, 0.095);
	glEnd();
    glPopMatrix();

	/////////////////////////
	glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.35, 0.065);
        glVertex2f(0.60, 0.065);
        glVertex2f(0.60, 0.26);
        glVertex2f(0.35, 0.26);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 0.110);
        glVertex2f(0.58, 0.110);
        glVertex2f(0.58, 0.215);
        glVertex2f(0.37, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glVertex2f(0.47, 0.110);
        glVertex2f(0.48, 0.110);
        glVertex2f(0.48, 0.215);
        glVertex2f(0.47, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 0.235);
        glVertex2f(0.58, 0.235);
        glVertex2f(0.58, 0.26);
        glVertex2f(0.37, 0.26);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.40,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.0, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.55,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.0, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glColor3d(0.275, 0.510, 0.706);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.60, 0.075);
        glVertex2f(0.65, 0.075);
        glVertex2f(0.65, 0.095);
        glVertex2f(0.60, 0.095);
	glEnd();
    glPopMatrix();

    /////////////////////////
	glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.65, 0.065);
        glVertex2f(0.90, 0.065);
        glVertex2f(0.90, 0.26);
        glVertex2f(0.65, 0.26);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.000);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.67, 0.110);
        glVertex2f(0.88, 0.110);
        glVertex2f(0.88, 0.215);
        glVertex2f(0.67, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.282, 0.239, 0.545);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.77, 0.110);
        glVertex2f(0.78, 0.110);
        glVertex2f(0.78, 0.215);
        glVertex2f(0.77, 0.215);
	glEnd();
    glPopMatrix();

    glColor3d(0.416, 0.353, 0.804);
    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.67, 0.235);
        glVertex2f(0.88, 0.235);
        glVertex2f(0.88, 0.26);
        glVertex2f(0.67, 0.26);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.70,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.0, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_train, 0.0f, 0.0f);
        glTranslatef(0.85,0.065,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 0.0, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.035;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();
        glPopMatrix();

    if(_move_sun<-0.10 || _move_sun>0.90 || isRain==true){
        glColor3f(2.000, 1.973, 1.863);
            glPushMatrix();
            glTranslatef(_move_train, 0.0f, 0.0f);
            glBegin(GL_POLYGON);
                glVertex2f(0.05, 0.245);
                glVertex2f(0.05, 0.255);
                glVertex2f(-0.00, 0.26);
                glVertex2f(-0.00, 0.24);
            glEnd();
            glPopMatrix();
        }
        glutSwapBuffers();
}

void sun_circle()
{
    glScalef(0.6,1,1);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.125;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
}

void sun(){
    //Sun
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    if(isRain==true)
    {

    }
    else{
    if(_move_sun<=1.00 && _move_sun>=0.90f){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.647, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else if(_move_sun<0.90f && _move_sun>=0.80f){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.843, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else if(_move_sun<0.80 && _move_sun>=0.65){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 1.000, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else if(_move_sun<0.65 && _move_sun>=0.45){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.843, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else if(_move_sun<0.45 && _move_sun>=0.25){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.647, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else if(_move_sun<0.25 && _move_sun>=0.10){
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.549, 0.000);
        sun_circle();
        glPopMatrix();
    }

    else{
        glPushMatrix();
        glTranslatef(0.0f, _move_sun, 0.0f);
        glColor3f(1.000, 0.271, 0.000);
        sun_circle();
        glPopMatrix();
    }
    }
}

void cloud_struct()
{

    if(isRain==true)
        glColor3f(0.500, 0.500, 0.500);
    else{
         glColor3f(1.000, 1.000, 1.000);
    }
        glScalef(0.6,1,1);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.075;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

}

void cloud_left(){
    //Cloud on the left
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.78,0.82,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.74,0.87,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.70,0.91,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.65,0.88,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.61,0.80,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.68,0.77,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_1, 0.0f, 0.0f);
    glTranslatef(-0.75,0.78,0);
    cloud_struct();
    glPopMatrix();
}

void cloud_right(){
    //Cloud on the right
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.78,0.70,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.74,0.75,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.70,0.79,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.65,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.61,0.76,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.68,0.65,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.63,0.66,0);
    cloud_struct();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_cloud_2, 0.0f, 0.0f);
    glTranslatef(0.75,0.66,0);
    cloud_struct();
    glPopMatrix();
}

void red_building(){
    //Red Building
    glBegin(GL_QUADS);
    glColor3f(0.698, 0.133, 0.133);
    glVertex2f(-0.95, -0.05);
    glVertex2f(-0.75, -0.05);
    glVertex2f(-0.75, 0.45);
    glVertex2f(-0.95, 0.45);

    //Door of Red Building
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(-0.90, -0.05);
    glVertex2f(-0.80, -0.05);
    glVertex2f(-0.80, 0.15);
    glVertex2f(-0.90, 0.15);

    //2 Window of Red Building
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);;
    glVertex2f(-0.93, 0.26);
    glVertex2f(-0.88, 0.26);
    glVertex2f(-0.88, 0.36);
    glVertex2f(-0.93, 0.36);

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.82, 0.26);
    glVertex2f(-0.77, 0.26);
    glVertex2f(-0.77, 0.36);
    glVertex2f(-0.82, 0.36);

    //Roof top of red building
    glBegin(GL_QUADS);
    glColor3f(0.0, 01.000, 0.000);
    glVertex2f(-0.93, 0.45);
    glVertex2f(-0.87, 0.45);
    glVertex2f(-0.87, 0.52);
    glVertex2f(-0.93, 0.52);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.94, 0.52);
    glVertex2f(-0.86, 0.52);
    glVertex2f(-0.86, 0.54);
    glVertex2f(-0.94, 0.54);

    glEnd();
}

void blue_building(){
    //Blue Building
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex2f(-0.65, -0.05);
    glVertex2f(-0.45, -0.05);
    glVertex2f(-0.45, 0.45);
    glVertex2f(-0.65, 0.45);

    //Door of blue building
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(-0.63, -0.05);
    glVertex2f(-0.57, -0.05);
    glVertex2f(-0.57, 0.15);
    glVertex2f(-0.63, 0.15);

    //Little window of blue building
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.53, 0.03);
    glVertex2f(-0.48, 0.03);
    glVertex2f(-0.48, 0.13);
    glVertex2f(-0.53, 0.13);

    //Big window of blue building
    glBegin(GL_QUADS);
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-0.63, 0.25);
    glVertex2f(-0.47, 0.25);
    glVertex2f(-0.47, 0.36);
    glVertex2f(-0.63, 0.36);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.63, 0.31);
    glVertex2f(-0.63, 0.30);
    glVertex2f(-0.47, 0.30);
    glVertex2f(-0.47, 0.31);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.555, 0.36);
    glVertex2f(-0.555, 0.25);
    glVertex2f(-0.545, 0.25);
    glVertex2f(-0.545, 0.36);

    //Roof top of blue building
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.46, 0.45);
    glVertex2f(-0.52, 0.45);
    glVertex2f(-0.52, 0.52);
    glVertex2f(-0.46, 0.52);

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.45, 0.52);
    glVertex2f(-0.53, 0.52);
    glVertex2f(-0.53, 0.54);
    glVertex2f(-0.45, 0.54);

    glEnd();
}

void phone_box(){
    //Phone Box
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2f(-0.41, -0.05);
    glVertex2f(-0.34, -0.05);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.41, 0.15);

    //Window of Phone Box
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex2f(-0.40, 0.02);
    glVertex2f(-0.35, 0.02);
    glVertex2f(-0.35, 0.13);
    glVertex2f(-0.40, 0.13);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(-0.38, 0.02);
    glVertex2f(-0.38, 0.13);

    glVertex2f(-0.37, 0.02);
    glVertex2f(-0.37, 0.13);

    glVertex2f(-0.40, 0.07);
    glVertex2f(-0.35, 0.07);

    glVertex2f(-0.40, 0.08);
    glVertex2f(-0.35, 0.08);
    glEnd();

    //Top of Phone Box
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(-0.41, 0.15);
    glVertex2f(-0.34, 0.15);
    glVertex2f(-0.36, 0.17);
    glVertex2f(-0.39, 0.17);
    glEnd();

}

void tower(){
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    if(_move_sun<0.10 || _move_sun>0.90)
    {
        glColor3f(2.0, 2.0, 2.0);
    }
    glVertex2f(-0.28, -0.03);
    glVertex2f(-0.20, -0.03);
    glVertex2f(-0.20, 0.05);
    glVertex2f(-0.28, 0.05);
    glEnd();

}

void twin_tower(){
    //Tower 1 of twin tower
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.30, -0.05);
    glVertex2f(-0.08, -0.05);
    glVertex2f(-0.08, 0.60);
    glVertex2f(-0.30, 0.60);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(-0.31, 0.60);
    glVertex2f(-0.07, 0.60);
    glVertex2f(-0.07, 0.62);
    glVertex2f(-0.31, 0.62);
    glEnd();
    //Roof top of tower 1


    //1st floor window of tower 1
    tower();

    glPushMatrix();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.10,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glTranslatef(0.0,0.10,0);
    tower();
    glPopMatrix();


    //Tower 2 of twin tower
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.08, -0.05);
    glVertex2f(0.30, -0.05);
    glVertex2f(0.30, 0.60);
    glVertex2f(0.08, 0.60);
    glEnd();

    //Roof top of tower 2
    glBegin(GL_QUADS);
    glColor3f(0.502, 0.000, 0.000);
    glVertex2f(0.31, 0.60);
    glVertex2f(0.07, 0.60);
    glVertex2f(0.07, 0.62);
    glVertex2f(0.31, 0.62);
    glEnd();


    glPushMatrix();
    glTranslatef(0.38,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.48,0.0,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glTranslatef(0.0,0.1,0);
    tower();
    glPopMatrix();

    //Joining of twin tower
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(-0.08, 0.15);
    glVertex2f(0.08, 0.15);
    glVertex2f(0.08, 0.27);
    glVertex2f(-0.08, 0.27);

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.08, 0.17);
    glVertex2f(0.08, 0.17);
    glVertex2f(0.08, 0.25);
    glVertex2f(-0.08, 0.25);

    glEnd();
}

void building_side_road(){
    //Building side road
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.753, 0.753);
    glVertex2f(-1.0, -0.05);
    glVertex2f(-1.0, -0.12);
    glVertex2f(1.0, -0.12);
    glVertex2f(1.0, -0.05);

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.10);
    glVertex2f(-1.0, -0.12);
    glVertex2f(1.0, -0.12);
    glVertex2f(1.0, -0.10);
    glEnd();
}

void roadStrips()
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.95, -0.30);
    glVertex2f(-0.95, -0.32);
    glVertex2f(-0.65, -0.32);
    glVertex2f(-0.65, -0.30);
    glEnd();
}

void road(){
    //Main road lane 1
    glBegin(GL_QUADS);
    glColor3f(0.412, 0.412, 0.412);
    glVertex2f(-1.0, -0.12);
    glVertex2f(-1.0, -0.50);
    glVertex2f(1.0, -0.50);
    glVertex2f(1.0, -0.12);
    glEnd();
    //Main Road Strips 1
    roadStrips();

    //Main Road Strips 2
    glPushMatrix();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glTranslatef(0.40,0,0);
    roadStrips();
    glPopMatrix();
}

void car_1(){
    glColor3d(0.000, 0.545, 0.545);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.85, -0.20);
        glVertex2f(-0.55, -0.20);
        glVertex2f(-0.55, -0.13);
        glVertex2f(-0.60, -0.13);
        glVertex2f(-0.65, -0.03);
        glVertex2f(-0.75, -0.03);
        glVertex2f(-0.80, -0.03);
        glVertex2f(-0.85, -0.13);
        glVertex2f(-0.85, -0.20);
    glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.61, -0.13);
        glVertex2f(-0.66, -0.04);
        glVertex2f(-0.79, -0.04);
        glVertex2f(-0.84, -0.13);
    glEnd();
    glPopMatrix();

    glColor3f(0.000, 0.545, 0.545);
    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.73, -0.13);
        glVertex2f(-0.72, -0.13);
        glVertex2f(-0.72, -0.04);
        glVertex2f(-0.73, -0.04);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.80,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.80,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.62,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_1, 0.0f, 0.0f);
        glTranslatef(-0.62,-0.21,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    if(_move_sun<-0.10 || _move_sun>0.90 || isRain==true){
        glColor3f(2.000, 1.973, 1.863);
        glPushMatrix();
        glTranslatef(_move_car_1, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.55, -0.165);
            glVertex2f(-0.55, -0.175);
            glVertex2f(-0.505, -0.195);
            glVertex2f(-0.505, -0.145);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void car_2(){
    glColor3d(0.545, 0.000, 0.000);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.54, -0.42);
        glVertex2f(-0.21, -0.42);
        glVertex2f(-0.20, -0.40);
        glVertex2f(-0.20, -0.13);
        glVertex2f(-0.21, -0.11);
        glVertex2f(-0.54, -0.11);
        glVertex2f(-0.55, -0.13);
        glVertex2f(-0.55, -0.40);
        glVertex2f(-0.54, -0.42);
	glEnd();
    glPopMatrix();

    glColor3d(0.902, 0.902, 0.980);
    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.52, -0.28);
        glVertex2f(-0.44, -0.28);
        glVertex2f(-0.44, -0.15);
        glVertex2f(-0.52, -0.15);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.41, -0.28);
        glVertex2f(-0.33, -0.28);
        glVertex2f(-0.33, -0.15);
        glVertex2f(-0.41, -0.15);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.30, -0.28);
        glVertex2f(-0.22, -0.28);
        glVertex2f(-0.22, -0.15);
        glVertex2f(-0.30, -0.15);
	glEnd();
    glPopMatrix();

    glColor3f(1.000, 0.647, 0.000);
    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53, -0.40);
        glVertex2f(-0.22, -0.40);
        glVertex2f(-0.225, -0.38);
        glVertex2f(-0.525, -0.38);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.48,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.045;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.48,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.27,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.045;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_2, 0.0f, 0.0f);
        glTranslatef(-0.27,-0.42,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    if(_move_sun<-0.10 || _move_sun>0.90 || isRain==true){
        glColor3f(2.000, 1.973, 1.863);
        glPushMatrix();
        glTranslatef(_move_car_2, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.55, -0.405);
            glVertex2f(-0.55, -0.395);
            glVertex2f(-0.605, -0.385);
            glVertex2f(-0.605, -0.415);
        glEnd();
        glPopMatrix();
    }

    glutSwapBuffers();
}

void car_3(){
    glColor3d(0.118, 0.565, 1.000);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON); //body solid
        glVertex2f(0.55, -0.25);
        glVertex2f(0.50, -0.25);
        glVertex2f(0.50, -0.40);
        glVertex2f(0.85, -0.40);
        glVertex2f(0.85, -0.10);
        glVertex2f(0.65, -0.10);
        glVertex2f(0.55, -0.25);
	glEnd();
    glPopMatrix();

    glColor3d(0.878, 1.000, 1.00);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON); //glass & windows
        glVertex2f(0.57, -0.25);
        glVertex2f(0.84, -0.25);
        glVertex2f(0.84, -0.12);
        glVertex2f(0.65, -0.12);
	glEnd();
    glPopMatrix();

    glColor3d(0.118, 0.565, 1.000);
    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // glass windows separator
        glVertex2f(0.71, -0.25);
        glVertex2f(0.72, -0.25);
        glVertex2f(0.72, -0.12);
        glVertex2f(0.71, -0.12);
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.57,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);// tire
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.57,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.78,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(_move_car_3, 0.0f, 0.0f);
        glTranslatef(0.78,-0.40,0);
        glScalef(0.6,1,1);
        glColor3f(1.000, 1.000, 1.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    if(_move_sun<-0.10 || _move_sun>0.90 || isRain==true){
        glColor3f(2.000, 1.973, 1.863);
        glPushMatrix();
        glTranslatef(_move_car_3, 0.0f, 0.0f);
        glBegin(GL_POLYGON);//light
            glVertex2f(0.50, -0.385);
            glVertex2f(0.50, -0.375);
            glVertex2f(0.45, -0.365);
            glVertex2f(0.45, -0.395);
        glEnd();
        glPopMatrix();
    }
    glutSwapBuffers();
}

void planeWindow()
{
   glBegin(GL_POLYGON);
    glColor3f(0.00, 0.00, 0.0);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.1f, -0.1f);
   glEnd();
}
void plane()
{
   glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.9f, 0.0f);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(0.5f, 0.2f);
    glColor3f(0.9, 0.9, 1.0);
    glVertex2f(0.5f, 0.0f);
   glEnd();
   glBegin(GL_POLYGON);
    glColor3f(1.00, 1.00, 1.0);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.5f, 0.2f);
   glEnd();
   glBegin(GL_POLYGON);
    glColor3f(1.000, 0.0, 0.000);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.4f, 0.0f);
   glEnd();
   glBegin(GL_POLYGON);
    glColor3f(0.000, 1.5, 0.000);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.3f, 0.5f);
    glVertex2f(-0.2f, 0.5f);
    glVertex2f(0.2f, 0.2f);
   glEnd();
   glBegin(GL_POLYGON);
    glColor3f(0.000, 1.0, 0.000);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(0.2f, 0.0f);
   glEnd();



    glPushMatrix();
    glScalef(0.2, 0.4, 0.0);
    glTranslatef( 0.3, 0.32, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glTranslatef( 0.3, 0.0, 0.0);
    planeWindow();
    glPopMatrix();
}

void park_side_road(){
    //River side road
    glBegin(GL_QUADS);
    glColor3f(0.753, 0.753, 0.753);
    glVertex2f(-1.0, -0.50);
    glVertex2f(-1.0, -0.57);
    glVertex2f(1.0, -0.57);
    glVertex2f(1.0, -0.50);

    glBegin(GL_QUADS);
    glColor3f(0.502, 0.502, 0.502);
    glVertex2f(-1.0, -0.55);
    glVertex2f(-1.0, -0.57);
    glVertex2f(1.0, -0.57);
    glVertex2f(1.0, -0.55);
    glEnd();
}

void house_1(){
    //House 1
    glBegin(GL_QUADS);
    glColor3f(0.400, 0.804, 0.667);
    glVertex2f(0.45, -0.03);
    glVertex2f(0.72, -0.03);
    glVertex2f(0.72, 0.17);
    glVertex2f(0.45, 0.17);

    //Door of House 1
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.894, 0.882);
    glVertex2f(0.56, -0.03);
    glVertex2f(0.60, -0.03);
    glVertex2f(0.60, 0.12);
    glVertex2f(0.56, 0.12);

    //Window of House 1
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.48, 0.03);
    glVertex2f(0.52, 0.03);
    glVertex2f(0.52, 0.10);
    glVertex2f(0.48, 0.10);

    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.64, 0.03);
    glVertex2f(0.68, 0.03);
    glVertex2f(0.68, 0.10);
    glVertex2f(0.64, 0.10);

    //Basement of house 1
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.44, -0.05);
    glVertex2f(0.73, -0.05);
    glVertex2f(0.73, -0.03);
    glVertex2f(0.44, -0.03);

    //Roof of house 1
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex2f(0.44, 0.17);
    glVertex2f(0.73, 0.17);
    glVertex2f(0.73, 0.19);
    glVertex2f(0.44, 0.19);
    glEnd();

    //Roof of house 1
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.937, 0.835);
    glVertex2f(0.44, 0.19);
    glVertex2f(0.73, 0.19);
    glVertex2f(0.59, 0.27);
    glEnd();
}

void house_2(){
    //House 2
    glBegin(GL_QUADS);
    glColor3f(0.804, 0.361, 0.361);
    glVertex2f(0.78, -0.03);
    glVertex2f(0.95, -0.03);
    glVertex2f(0.95, 0.17);
    glVertex2f(0.78, 0.17);

    //Door of House 2
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.87, -0.03);
    glVertex2f(0.92, -0.03);
    glVertex2f(0.92, 0.12);
    glVertex2f(0.87, 0.12);

    //Window of House 2
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex2f(0.80, 0.03);
    glVertex2f(0.84, 0.03);
    glVertex2f(0.84, 0.10);
    glVertex2f(0.80, 0.10);

    //Basement of house 2
    glBegin(GL_QUADS);
    glColor3f(0.647, 0.165, 0.165);
    glVertex2f(0.77, -0.05);
    glVertex2f(0.96, -0.05);
    glVertex2f(0.96, -0.03);
    glVertex2f(0.77, -0.03);

    //Roof of house 2
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex2f(0.77, 0.17);
    glVertex2f(0.96, 0.17);
    glVertex2f(0.96, 0.19);
    glVertex2f(0.77, 0.19);
    glEnd();

    //Roof of house 2
    glBegin(GL_POLYGON);
    glColor3f(1.000, 0.937, 0.835);
    glVertex2f(0.77, 0.19);
    glVertex2f(0.96, 0.19);
    glVertex2f(0.86, 0.25);
    glEnd();
}

void road_light()
{
    //Road lights
    glBegin(GL_POLYGON);
     glColor3f(0.0f,0.0f,0.0f);
     glVertex2f(-0.8f, -1.0f);
     glVertex2f(-0.8f, 0.5f);
     glVertex2f(-0.87f, 0.5f);
     glVertex2f(-0.87f, -1.0f);
    glEnd();

    //Road lights
    glBegin(GL_POLYGON);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(-0.8f, 0.5f);
     glVertex2f(-0.6f, 0.65f);
     glVertex2f(-0.6f, 0.7f);
     glVertex2f(-0.87f, 0.5f);
    glEnd();

    //Road Lights
    glBegin(GL_POLYGON);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2f(-0.6f, 0.7f);
     glVertex2f(-0.3f, 0.7f);
     glVertex2f(-0.3f, 0.65);
     glVertex2f(-0.6f, 0.65f);
    glEnd();

    //Lights
    glBegin(GL_POLYGON);
    glColor3f(0.90f, 0.90f, 0.0f);
    if(_move_sun<0.10 || _move_sun>0.90)
    {
        glColor3f(2.00f, 2.00f, 0.0f);
    }

     glVertex2f(-0.5f, 0.65f);
     glVertex2f(-0.3f, 0.65f);
     glVertex2f(-0.3f, 0.55f);
     glVertex2f(-0.5f, 0.55f);
    glEnd();

    //base
    glBegin(GL_POLYGON);
     glColor3f(0.90f, 0.90f, 0.80f);
     glVertex2f(-0.9f, -1.0f);
     glVertex2f(-0.9f, -0.9f);
     glVertex2f(-0.7f, -0.9f);
     glVertex2f(-0.7f, -1.0f);
    glEnd();
}

void road_lamp_one_side()
{
    //Lamp 1
    glPushMatrix();
    glLoadIdentity();
    glScalef(0.2f, 0.2f, 0.0f);
    glTranslatef(-3.0f, 0.52f, 0.0f);
    road_light();

    //Lam Stand 2

    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand 3
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand 4
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand 5
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand 5
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();
    glPopMatrix();
}

void road_lamp_another_side(){

    //Lam Stand - 1
    glPushMatrix();
    glLoadIdentity();
    glScalef(0.2f, 0.2f, 0.0f);
    glTranslatef(-3.0f, -1.5f, 0.0f);
    road_light();

    //Lam Stand - 2
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand - 3
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand - 4
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand - 5
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();

    //Lam Stand - 6
    glTranslatef(1.55f, 0.f, 0.0f);
    road_light();
    glPopMatrix();
}

void field_2(){
    glBegin(GL_QUADS);
    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(-1.0, -0.523);
    glVertex2f(-0.060, -0.523);
    glVertex2f(-0.060, -0.528);
    glVertex2f(-1.0, -0.528);

    glBegin(GL_QUADS);
    glColor3f(0.439, 0.502, 0.565);
    glVertex2f(0.060, -0.523);
    glVertex2f(1.0, -0.523);
    glVertex2f(1.0, -0.528);
    glVertex2f(0.060, -0.528);

    glColor3f(0.184, 0.310, 0.310);
    for(float i = -1.0; i<=-0.060; i =i+0.02){
        glVertex2f(i, -0.57);
        glVertex2f(i, -0.520);
        glVertex2f(i+0.005, -0.520);
        glVertex2f(i+0.005, -0.57);
    }

    for(float i = 0.060; i<=1; i =i+0.02){
        glVertex2f(i, -0.57);
        glVertex2f(i, -0.520);
        glVertex2f(i+0.005, -0.520);
        glVertex2f(i+0.005, -0.57);
    }
    glEnd();
    //field 2
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(1.0, -0.57);

    glColor3f(0.000, 1.000, 0.000);
    glVertex2f(-1.0, -0.57);

    glColor3f(0.486, 0.988, 0.000);
    glVertex2f(-1.0, -0.73);

    glColor3f(0.498, 1.000, 0.000);
    glVertex2f(1.0, -0.73);
    glEnd();
}

void road_side_park(){
    //River Side Bench 1
    glBegin(GL_QUADS);
    glColor3f(0.961, 1.000, 0.980);
    glVertex2f(-0.855, -0.70);
    glVertex2f(-0.87, -0.70);
    glVertex2f(-0.87, -0.62);
    glVertex2f(-0.855, -0.62);

    glVertex2f(-0.755, -0.70);
    glVertex2f(-0.77, -0.70);
    glVertex2f(-0.77, -0.62);
    glVertex2f(-0.755, -0.62);

    glColor3f(0.941, 1.000, 0.941);
    glVertex2f(-0.885, -0.62);
    glVertex2f(-0.740, -0.62);
    glVertex2f(-0.740, -0.60);
    glVertex2f(-0.885, -0.60);

    //River Side Bench 2
    glColor3f(0.961, 1.000, 0.980);
    glVertex2f(0.855, -0.70);
    glVertex2f(0.87, -0.70);
    glVertex2f(0.87, -0.62);
    glVertex2f(0.855, -0.62);

    glVertex2f(0.755, -0.70);
    glVertex2f(0.77, -0.70);
    glVertex2f(0.77, -0.62);
    glVertex2f(0.755, -0.62);

    glColor3f(0.941, 1.000, 0.941);
    glVertex2f(0.885, -0.62);
    glVertex2f(0.740, -0.62);
    glVertex2f(0.740, -0.60);
    glVertex2f(0.885, -0.60);

    //Road On park
    glColor3f(0.941, 0.902, 0.549);
    glVertex2f(-0.05, -0.68);
    glVertex2f(0.05, -0.68);
    glVertex2f(0.05, -0.57);
    glVertex2f(-0.05, -0.57);

    glColor3f(0.741, 0.718, 0.420);
    glVertex2f(-0.060, -0.68);
    glVertex2f(-0.050, -0.68);
    glVertex2f(-0.050, -0.57);
    glVertex2f(-0.060, -0.57);

    glVertex2f(0.060, -0.68);
    glVertex2f(0.050, -0.68);
    glVertex2f(0.050, -0.57);
    glVertex2f(0.060, -0.57);

    //River Side Temple
    glColor3f(0.627, 0.322, 0.176);
    glVertex2f(-0.15, -0.70);
    glVertex2f(0.15, -0.70);
    glVertex2f(0.15, -0.68);
    glVertex2f(-0.15, -0.68);

    glColor3f(0.804, 0.522, 0.247);
    glVertex2f(-0.12, -0.68);
    glVertex2f(0.12, -0.68);
    glVertex2f(0.12, -0.66);
    glVertex2f(-0.12, -0.66);

    glColor3f(0.957, 0.643, 0.376);
    glVertex2f(-0.10, -0.66);
    glVertex2f(-0.08, -0.66);
    glVertex2f(-0.08, -0.48);
    glVertex2f(-0.10, -0.48);

    glVertex2f(0.10, -0.66);
    glVertex2f(0.08, -0.66);
    glVertex2f(0.08, -0.48);
    glVertex2f(0.10, -0.48);

    glColor3f(0.804, 0.522, 0.247);
    glVertex2f(-0.12, -0.48);
    glVertex2f(0.12, -0.48);
    glVertex2f(0.12, -0.46);
    glVertex2f(-0.12, -0.46);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.961, 0.871, 0.702);
    glVertex2f(-0.12, -0.46);
    glVertex2f(0.12, -0.46);
    glVertex2f(0.00, -0.34);
    glVertex2f(-0.12, -0.46);
    glEnd();

    //River Side
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.871, 0.678);
    glVertex2f(-1.0, -0.73);
    glColor3f(1.000, 0.894, 0.769);
    glVertex2f(1.0, -0.73);
    glColor3f(1.000, 0.922, 0.804);
    glVertex2f(1.0, -0.77);
    glColor3f(0.871, 0.722, 0.529);
    glVertex2f(-1.0, -0.77);
    glEnd();
}

void river(){
    glBegin(GL_QUADS);
    glColor3f(0.000, 1.000, 1.000);
    glVertex2f(1.0, -0.77);

    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(-1.0, -0.77);

    glColor3f(0.498, 1.000, 0.831);
    glVertex2f(-1.0, -1.0);

    glColor3f(0.282, 0.820, 0.800);
    glVertex2f(1.0, -1.0);

    glEnd();
}

void tree1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(-0.84, -0.65);
    glVertex2f(-0.81, -0.65);
    glVertex2f(-0.82, -0.45);
    glVertex2f(-0.83, -0.45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.0);
    glVertex2f(-0.88, -0.50);
    glColor3f(0.0, 0.5, 0.0);
    glVertex2f(-0.77, -0.50);
    glColor3f(0.196, 0.804, 0.196);
    glVertex2f(-0.825, -0.30);
    glEnd();
}

void circle_tree()
{
    glBegin(GL_POLYGON);
    glColor3f(0.824, 0.412, 0.118);
    glVertex2f(-0.59, -0.65);
    glVertex2f(-0.56, -0.65);
    glVertex2f(-0.57, -0.45);
    glVertex2f(-0.58, -0.45);
    glEnd();

    glPushMatrix();
        glTranslatef(-0.595,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.555,-0.45,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.575,-0.385,0);
        glScalef(0.6,1,1);
        glColor3f(0.000, 1.000, 0.000);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.065;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
}

void flower_tree()
{
    glPushMatrix();
        glTranslatef(-0.20, -0.625,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.22, -0.625,0);
        glScalef(0.6,1,1);
        glColor3f(0.824, 0.412, 0.118);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.030;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.24, -0.595,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.18, -0.595,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0425;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.210, -0.570,0);
        glScalef(0.6,1,1);
        glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.0435;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
    glPopMatrix();
}
void park_tree()
{
    //Tree1
    tree1();
    //tree2
    circle_tree();

    //Park Tree 3
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.45f, 0.0f, 0.0f);
    tree1();

    //Flower Tree 1
    glLoadIdentity();
    flower_tree();

    //Flower Tree 2

    glTranslatef(0.42f, 0.0f, 0.0f);
    flower_tree();

     //tree 4
     glLoadIdentity();
     glTranslatef(1.2f, 0.0f, 0.0f);
     tree1();

    //Tree 5
    glLoadIdentity();
    glTranslatef(1.16f, 0.0f, 0.0f);
    circle_tree();

    //Tree 6
    glLoadIdentity();
    glTranslatef(1.6f, 0.0f, 0.0f);
    tree1();
    glLoadIdentity();
    glPopMatrix();
}

void boat(){
glPushMatrix();//start_pushpop
glLoadIdentity();
    glTranslatef(_move_boat, 0.0f, 0.0f);
        glTranslatef(0.0, -1.05, 0.0);
        glScalef(0.55, 0.55, 0);
        glPushMatrix();
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_QUADS);
        glVertex2f(0.35, 0.35);
        glVertex2f(0.75, 0.35);
        glVertex2f(0.95, 0.45);
        glVertex2f(0.15, 0.45);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glLoadIdentity();
        glTranslatef(_move_boat, 0.0f, 0.0f);
        glTranslatef(0.12, -1.03, 0.0);
        glScalef(0.50, 0.50, 0);
        glColor3f(0.948,0.934,0.734);
        glBegin(GL_QUADS);
        glVertex2f(0.55, 0.45);
        glVertex2f(0.15, 0.45);
        glVertex2f(0.15, 0.65);
        glVertex2f(0.55, 0.65);

        glEnd();
        glPopMatrix();

    if(_move_sun<-0.10){
        glColor3f(1.000, 0.973, 0.863);
        glPushMatrix();
        glTranslatef(_move_ship, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.45, -0.80);
            glVertex2f(-0.45, -0.81);
            glVertex2f(-0.40, -0.85);
            glVertex2f(-0.40, -0.75);
        glEnd();
        glPopMatrix();
    }
}

void ship(){
    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(0.647, 0.165, 0.165);
        glBegin(GL_POLYGON);
        glVertex2f(-0.75, -0.98);
        glVertex2f(-0.45, -0.98);
        glVertex2f(-0.40, -0.83);
        glVertex2f(-0.80, -0.83);
        glEnd();
        glPopMatrix();

    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(1.000, 1.000, 0.941);
        glBegin(GL_POLYGON);
        glVertex2f(-0.70, -0.83);
        glVertex2f(-0.45, -0.83);
        glVertex2f(-0.45, -0.75);
        glVertex2f(-0.70, -0.75);
        glEnd();
        glPopMatrix();

    glPushMatrix();//start_pushpop
    glTranslatef(_move_ship, 0.0f, 0.0f);
        glColor3f(1.000, 0.980, 0.941);
        glBegin(GL_POLYGON);
        glVertex2f(-0.60, -0.75);
        glVertex2f(-0.50, -0.75);
        glVertex2f(-0.50, -0.65);
        glVertex2f(-0.60, -0.65);
        glEnd();
        glPopMatrix();

    if(_move_sun<-0.10 || _move_sun>0.90 || isRain==true){
        glColor3f(2.000, 1.973, 1.863);
        glPushMatrix();
        glTranslatef(_move_ship, 0.0f, 0.0f);
        glTranslatef(-0.25f, 0.03f, 0.0f);
        glBegin(GL_TRIANGLES);
            glVertex2f(-0.40, -0.80);
            glVertex2f(-0.60, -0.75);
            glVertex2f(-0.60, -0.85);
    glEnd();
        glPopMatrix();
    }
}

void window1()
{


    glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(0.21f, 0.18f);
      glVertex2f(0.33f, 0.18f);
      glVertex2f(0.33f, 0.12f);
      glVertex2f(0.21f, 0.12f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(0.21f, 0.10f);
      glVertex2f(0.33f, 0.10f);
      glVertex2f(0.33f, 0.04f);
      glVertex2f(0.21f, 0.04f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(0.21f, 0.02f);
      glVertex2f(0.33f, 0.02f);
      glVertex2f(0.33f, -0.04f);
      glVertex2f(0.21f, -0.04f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(0.21f, -0.06f);
      glVertex2f(0.33f, -0.06f);
      glVertex2f(0.33f, -0.12f);
      glVertex2f(0.21f, -0.12f);
    glEnd();
}

void building()
{
    //Building1
    glBegin(GL_POLYGON);
      glColor3f(0.50f, 0.40f, 0.60f);
      glVertex2f(0.20f, -0.20f);
      glVertex2f(0.20f, 0.20f);
      glVertex2f(0.50f, 0.20f);
      glVertex2f(0.50f, -0.20f);
    glEnd();
}

void buildings()
{
    glPopMatrix();
    glLoadIdentity();
    glScalef(0.4, 0.5, 0.0);
    //
    glTranslatef(0.6f, 0.47f, 0.0f);
    building();
    window1();
      glTranslatef(0.15f, 0.0f, 0.0f);
      window1();
    glTranslatef(0.4f, 0.0f, 0.0f);
    building();
    window1();
      glTranslatef(0.15f, 0.0f, 0.0f);
      window1();
    glTranslatef(0.4f, 0.0f, 0.0f);
    building();
    window1();
      glTranslatef(0.15f, 0.0f, 0.0f);
      window1();
    glPopMatrix();
}

void windmill()
{


    glBegin(GL_POLYGON);//stand
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.01f, 0.0f);
    glVertex2f( 0.01f, -0.8f);
    glVertex2f( -0.01f, -0.8f);
    glVertex2f( -0.01f, 0.0f);
    glEnd();

    glPushMatrix();

    glRotatef(r,0.0,0.0,1.0);

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.05f, 0.04f);
    glVertex2f( 0.55f, 0.01);
    glVertex2f( 0.55f, -0.01f);
    glVertex2f( 0.05f, -0.04f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.04f, -0.04f);
    glVertex2f( 0.01f, -0.55f);
    glVertex2f( -0.01f, -0.55f);
    glVertex2f( -0.04f, -0.04f);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( -0.05f, -0.04f);
    glVertex2f( -0.55f, -0.01f);
    glVertex2f( -0.55f, 0.01f);
    glVertex2f( -0.05f, 0.04f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.04f, 0.04f);
    glVertex2f( 0.01f, 0.55f);
    glVertex2f( -0.01f, 0.55f);
    glVertex2f( -0.04f, 0.04f);
    glEnd();

    glPopMatrix();

    r+=0.06f;

}
void windmills()
{

    glLoadIdentity();
    glScalef(0.2, 0.2, 0.0);

    glPushMatrix();
    glTranslatef(-4.8, 1.47, 0.0);
    windmill();
    glTranslatef(1.3, 0, 0.0);
    windmill();
    glTranslatef(1.3, 0, 0.0);
    windmill();
    glTranslatef(1.5, 0, 0.0);
    windmill();
    glTranslatef(1.3, 0, 0.0);
    windmill();
    glTranslatef(1.3, 0, 0.0);
    windmill();
    glTranslatef(1.3, 0, 0.0);
    windmill();
    glTranslatef(1.3, 0, 0.0);
    windmill();
    glPopMatrix();
}

void mountain()
{
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
    glEnable ( GL_COLOR_MATERIAL ) ;
    glBegin(GL_TRIANGLES);
     glColor3f(0.0, 0.5, 0.0);
     glVertex2f(-1.0f, -1.0f);
     glColor3f(1.0, 1.0, 1.0);
     glVertex2f(0.0f, 1.0f);
     glColor3f(0.0, 0.5, 0.0);
     glVertex2f(1.0f, -1.0f);
    glEnd();
}
void mountains()
{
    glPushMatrix();
    glLoadIdentity();
    glScalef(0.3f, 0.3f, 0.0f);
    glTranslatef(-2.6f, 1.45f,0.0f);
    mountain();
    glTranslatef(0.8f, 0.0f,0.0f);
    mountain();
    glTranslatef(3.5f, 0.0f,0.0f);
    mountain();
    glPopMatrix();
}

void rain()
{
    if(isRain==true)
    {
        int i=0,j=0;
        float x,y;
        x=-1.0f;
        y=2.0f;

        while(j<=100)
        {
            x = -1.0f;
            while(i<=100)
            {
                glBegin(GL_LINES);
                glColor3f(0.313, 0.560, 0.713);
                glVertex2f(x,y);
                glVertex2f(x-0.02f,y-0.07f);
                glEnd();

                x=x+0.03f;
                i++;
            }
            y = y-0.05f;
            j++;
            i=0;
        }
    }


}

void airplane()
{
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
      glScalef(0.2, 0.2, 0.0);
      glTranslatef(0.0, 4.0, 0.0);
      plane();
    glPopMatrix();
}
void PointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec)
{
  glEnable(GL_LIGHTING);


  GLfloat light_ambient[] = { amb,amb,amb, 1.0 };
  GLfloat light_diffuse[] = {diff, diff, diff, 1.0 };
  GLfloat light_specular[] = {spec, spec, spec, 1.0 };

  GLfloat light_position[] = {1.0,1.0,1, 0.0 };

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_LIGHT0); //enable the light after setting the properties

}


void skyColoring()
{
    if(isRain==true)
    {
        PointLight(0,0,1, 0.0, 1.0, 1.0);
    }
    if(_move_sun<=1.00 && _move_sun>=0.90f){
        PointLight(0,0,1, 0.0, 1.0, 1.0);
    }

    else if(_move_sun<0.90f && _move_sun>=0.80f){
        PointLight(0,0,1, 0.0, 1.2, 1.0);
    }

    else if(_move_sun<0.80 && _move_sun>=0.65){
        PointLight(0,0,1, 0.0, 1.4, 1.0);
    }

    else if(_move_sun<0.65 && _move_sun>=0.45){
        PointLight(0,0,1, 0.0, 1.6, 1.0);
    }

    else if(_move_sun<0.45 && _move_sun>=0.25){
        PointLight(0,0,1, 0.0, 1.8, 1.0);
    }

    else if(_move_sun<0.25 && _move_sun>=0.10){
        PointLight(0,0,1, 0.0, 2.0, 1.0);
    }

    else{
        PointLight(0,0,1, 0.0, 1.0, 1.0);
    }
}


void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    sky();
    sun();
    skyColoring();
    field_1();
    rail_track();
    mountains();
    buildings();
    windmills();
    train();
    cloud_left();
    cloud_right();
    red_building();
    blue_building();
    phone_box();
    twin_tower();
    house_1();
    house_2();
    building_side_road();
    road_lamp_one_side();
    road();
    car_1();
    car_3();
    car_2();
    road_lamp_another_side();
    park_side_road();
    field_2();
    park_tree();
    road_side_park();
    river();
    ship();
    boat();
    airplane();
    rain();
    glFlush();
}


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

void Idle()
{
    glutPostRedisplay();
}

int main(int argc, char** argv){
    cout << endl << "*********** City Lights ********************" << endl << endl;

    cout << "Press T : To Forward the Train and Increase Speed" << endl << endl;
    cout << "Press t : To Decrease the Speed of Train" << endl << endl;

    cout << "Press A : To Start or Increase The Speed Of Car 1" << endl << endl;
    cout << "Press a : To Decrease the Speed of Car 1" << endl << endl;

    cout << "Press B : To Start or Increase The Speed Of Car 2" << endl << endl;
    cout << "Press b : To Decrease the Speed of Car 2" << endl << endl;

    cout << "Press C : To Start or Increase The Speed Of Car 3" << endl << endl;
    cout << "Press c : To Decrease the Speed of Car 3" << endl << endl;

    cout << "Press S : To Start or Increase The Speed Of Ship" << endl << endl;
    cout << "Press c : To Decrease the Speed of Ship" << endl << endl;

    cout << "Press R : For Rain " << endl << endl;
    cout << "Press r : For Stop Rain" << endl << endl;

     cout << endl << "*******************************************" << endl << endl;


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("City Lights");
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(20, update_sun, 0);
    glutTimerFunc(20, update_cloud_1, 0);
    glutTimerFunc(20, update_cloud_2, 0);
    glutTimerFunc(20, update_boat, 0);
    glutTimerFunc(20, update_ship, 0);
    myInit ();
    glutTimerFunc(100, update_plane, 0);
    glutIdleFunc(Idle);
    glutMainLoop();
}
