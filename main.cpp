#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;

GLfloat spin = 0.0;
GLfloat spinplane = 0.0;
GLfloat runxc = 0.0;
GLfloat runyc = 0.0;
GLfloat runcloud = 0.0;
GLfloat resizee = 1.0;

void runAnimation(void)
{
    runcloud = runcloud + 0.03;
    runxc = runxc + 0.2;
    runyc = runyc + 0.1;
    resizee = resizee - 0.001;
    spin = spin - 100;
    if (spin > 360.0)
      spin = spin - 360.0;
    glutPostRedisplay();
}

void spinLeft(){
   spinplane = spinplane + 1;
   if (spinplane > 360.0)
      spinplane = spinplane - 360.0;
   glutPostRedisplay();
}
void spinRight(){
   spinplane = spinplane - 1;
   if (spinplane > 360.0)
      spinplane = spinplane - 360.0;
   glutPostRedisplay();
}

void init(){
    glShadeModel(GL_SMOOTH);
    glClearColor(0, 0, 0,0);
    glOrtho(-50, 50, -50, 50, -10, 10);
}
void showString(char *string)
{
     while(*string)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *string++);
}
GLvoid drawCircle(GLdouble xc, GLdouble yc, GLdouble radius)
{
    glPointSize(3);
	glBegin(GL_POLYGON);

    for(float i=0;i<=7;i+=.01)
        glVertex2f(xc+radius*cos(i),yc+radius*sin(i));
	glEnd();
}
void sun(GLdouble x,GLdouble y)
{
    glColor3f(0.921, 0.592, 0.117);
    drawCircle(x+0,y+2,5);
}
void tree(GLdouble x, GLdouble y)
{
    //Tree leaves
    glColor3f(0.082, 0.478, 0.172);
    drawCircle(x,y,2);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x-1,y-2,3);
    drawCircle(x-3,y-0.3,3);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x-4,y+1.5,3);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x-3.1,y+3.5,3);
    drawCircle(x-1.8,y+6.5,3.4);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x+1.1,y+9.1,3);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x+4,y+8,3);
    drawCircle(x+3,y+3,4);
    glColor3f(0.584, 0.752, 0.129);
    drawCircle(x+6.2,y+3.5,3);
    drawCircle(x+7.1,y+1.1,3);
    drawCircle(x+6.5,y-1,3);
    drawCircle(x+5,y-1.5,3);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x+3.2,y-3.8,2.4);
    drawCircle(x+2.2,y-3.8,2.4);
    glColor3f(0.439, 0.631, 0.211);
    drawCircle(x+4,y+4.5,3.8);
    glColor3f(0.725, 0.858, 0.078);
    drawCircle(x+2.8,y+5.5,3.8);
    drawCircle(x+1.5,y+5.0,2);
    glColor3f(0.647, 0.776, 0.223);
    drawCircle(x+1.0,y+5.3,2.8);
    drawCircle(x+0.9,y+4.9,1.8);

    glColor3f(0.662, 0.298, 0.078);//tree branch
    glBegin(GL_QUADS);
    glVertex2f(x+1.5,y+2);
    glVertex2f(x+2.5,y+2);
    glVertex2f(x+3.0,y-12);
    glVertex2f(x+1.0,y-12);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//2nd branch
    glBegin(GL_QUADS);
    glVertex2f(x+2.5,y-2);
    glVertex2f(x+2.5,y-3);
    glVertex2f(x+5.8,y+1);
    glVertex2f(x+5.8,y+1);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//1st branch
    glBegin(GL_QUADS);
    glVertex2f(x+2.5,y+0);
    glVertex2f(x+2.5,y-0.8);
    glVertex2f(x+3.5,y+1);
    glVertex2f(x+4,y+1);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//left 1st branch
    glBegin(GL_QUADS);
    glVertex2f(x+1.4,y+0);
    glVertex2f(x+1.5,y-1);
    glVertex2f(x+0.5,y+0.5);
    glVertex2f(x+0.2,y-0.01);
    glEnd();

    glColor3f(0.662, 0.298, 0.078);//left 2nd branch
    glBegin(GL_QUADS);
    glVertex2f(x+2.5,y-2);
    glVertex2f(x+2.5,y-3);
    glVertex2f(x-0.2,y-0.2);
    glVertex2f(x-0.3,y-0.8);
    glEnd();

}
void cloud(GLdouble x, GLdouble y)
{
    glColor3f(0.945, 0.956, 0.956);//light ash color
    drawCircle(x-10.5,y+1,1);
    drawCircle(x-8.5,y+2,1.5);
    drawCircle(x-6,y+4,2.5);
    drawCircle(x-4,y+2.5,2.5);
    drawCircle(x-2,y+2,1.5);
    drawCircle(x+2,y+2,2);
    drawCircle(x+4,y+1.5,1.5);
    drawCircle(x+6,y+1.5,1.2);
    drawCircle(x+8,y+1.3,1.3);
    drawCircle(x+10,y+1.2,.8);

    //for straight line below
    glColor3f(0.945, 0.956, 0.956);//light ash color
    glBegin(GL_QUADS);
    glVertex2f(x-9,y+2);
    glVertex2f(x+8,y+2);
    glColor3f(0.713, 0.8, 0.803);//dark ash color
    glVertex2f(x+15,y);
    glVertex2f(x-15,y);
    glEnd();
}

GLvoid spinFan(GLfloat x, GLfloat y){
    glPushMatrix();
	glRotatef(spin, x, y, 1.0);
	glColor3f(0.654, 0.772, 0.862);
	glBegin(GL_POLYGON);
	glVertex2f(x+0,y+0);
	glVertex2f(x-1,y+5);
	glVertex2f(x+1,y+5);
	glVertex2f(x+0,y+0);
	glVertex2f(x+1,y-5);
	glVertex2f(x-1,y-5);
	glEnd();
	glPopMatrix();
	glFlush();
}



void floor(){
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(-50,-20);
        glVertex2f(50,-20);
    glEnd();
    glFlush();
    //green field
    glBegin(GL_QUADS);
        glColor3f(.01,.66,.24);
        glVertex2f(-50,-20);
        glColor3f(.21,.31,.15);
        glVertex2f(50,-20);
        glColor3f(.18,.66,.24);
        glVertex2f(90,-80);
        glColor3f(.18,.66,.24);
        glVertex2f(-90,-80);
    glEnd();
    glFlush();
    //left road border
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-40,-20);
        glVertex2f(-38,-20);
        glVertex2f(5,-50);
        glVertex2f(1,-50);
    glEnd();
    glFlush();
    //right road border
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-30,-20);
        glVertex2f(-28,-20);
        glVertex2f(50,-50);
        glVertex2f(45,-50);
    glEnd();
    glFlush();
    //road
    glColor3f(0.141, 0.172, 0.215);
    glBegin(GL_QUADS);
        glVertex2f(-38,-20);
        glVertex2f(-30,-20);
        glVertex2f(45,-50);
        glVertex2f(5,-50);
    glEnd();
    glFlush();
}
void sky(){
    glColor3f(0.647, 0.858, 0.874);
    glBegin(GL_QUADS);
        glVertex2f(-50,-20);
        glVertex2f(-50,50);
        glVertex2f(50,50);
        glVertex2f(50,-20);
    glEnd();
    glFlush();
}
void hill(){
    glColor3f(0.152, 0.258, 0.023);
    glBegin(GL_POLYGON);
        //glColor3f(0.152, 0.258, 0.023);
        glVertex2f(-30,-20);
        glColor3f(0.466, 0.713, 0.145);
        glVertex2f(-6,-8);
        glVertex2f(-5,-8.5);
        glVertex2f(-4,-8);
        glVertex2f(-3,-8.5);
        glVertex2f(20,-15);
        glColor3f(0.152, 0.258, 0.023);
        glVertex2f(30,-20);
    glEnd();
    glFlush();

    glColor3f(0.152, 0.258, 0.023);
    glBegin(GL_POLYGON);
        glVertex2f(-60,-20);
        glVertex2f(-37,-4.5);
        glVertex2f(-36,-4);
        glVertex2f(-35,-4.5);
        glVertex2f(-20,-15);
        glVertex2f(-10,-20);
    glEnd();
    glFlush();

    glColor3f(0.152, 0.258, 0.023);
    glBegin(GL_POLYGON);
        glVertex2f(-5,-20);
        glVertex2f(16,-5);
        glVertex2f(17,-4.9);
        glVertex2f(18,-4.8);
        glVertex2f(19,-4.7);
        glVertex2f(20,-4.8);
        glVertex2f(21,-4.9);
        glVertex2f(22,-5);

        glVertex2f(50,-20);
    glEnd();
    glFlush();

}

void plane(float x, float y){
    spinFan(x-9,y+4.3);
        //paaankha right
    glColor3f(0.654, 0.772, 0.862);
    glBegin(GL_POLYGON);
        glVertex2f(x+8,y-1);
        glVertex2f(x+35,y+1);
        glVertex2f(x+38,y-1);
        glVertex2f(x+4,y-12);
    glEnd();
    glFlush();

    //paaankha right border
    glLineWidth(1);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x+8,y-1);
        glVertex2f(x+35,y+1);
        glVertex2f(x+38,y-1);
        glVertex2f(x+4,y-12);
    glEnd();
    glFlush();

    //pankha right back
    glColor3f(0.654, 0.772, 0.862);
    glBegin(GL_POLYGON);
        glVertex2f(x+18,y-12);
        glVertex2f(x+31,y-12);
        glVertex2f(x+33,y-14);
        glVertex2f(x+18,y-14);
    glEnd();
    glFlush();

        //paaankha back right border
    glLineWidth(1);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x+18,y-12);
        glVertex2f(x+31,y-12);
        glVertex2f(x+33,y-14);
        glVertex2f(x+18,y-14);
    glEnd();
    glFlush();
    //body
    glColor3f(0.654, 0.772, 0.862);
    glBegin(GL_POLYGON);
        glVertex2f(x-5,y+5);
        glVertex2f(x-4,y+6);
        glVertex2f(x-3,y+6.5);
        glVertex2f(x-2,y+6.6);
        glVertex2f(x-1,y+6.7);
        glVertex2f(x+0,y+6.6);
        glVertex2f(x+1,y+6.5);
        glVertex2f(x+2,y+6);
        glVertex2f(x+6,y+2);
        glVertex2f(x+12.0,y-6.3);
        ///LEJ KATA
        glVertex2f(x+20.3,y-15);
        glVertex2f(x+20.4,y-16);
        glVertex2f(x+20.3,y-17);
        glVertex2f(x+19.5,y-18);
        glVertex2f(x+19.0,y-18);
        glVertex2f(x+18.5,y-18);
        glVertex2f(x+18.1,y-18.1);
        glVertex2f(x+16.1,y-17.8);
        glVertex2f(x+14.1,y-17.1);
        glVertex2f(x+10.1,y-15.5);
        glVertex2f(x+2,y-12);
        glVertex2f(x+0,y-11);
        glVertex2f(x-2,y-10);
        glVertex2f(x-4,y-8.5);
        glVertex2f(x-6,y-6.5);
        glVertex2f(x-8,y-3.5);
        glVertex2f(x-9,y-1);
        glVertex2f(x-9.3,y+3.5);
        glVertex2f(x-9,y+4);
        glVertex2f(x-8.7,y+4.5);
        glVertex2f(x-8.5,y+4.5);
        glVertex2f(x-8.3,y+4.7);
        glVertex2f(x-8.1,y+4.9);
        glVertex2f(x-7.5,y+5);
        glVertex2f(x-7,y+5);
        glVertex2f(x-6.5,y+5);
        glVertex2f(x-5,y+5);
    glEnd();
    glFlush();
    //body border
    glLineWidth(1);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x-5,y+5);
        glVertex2f(x-4,y+6);
        glVertex2f(x-3,y+6.5);
        glVertex2f(x-2,y+6.6);
        glVertex2f(x-1,y+6.7);
        glVertex2f(x+0,y+6.6);
        glVertex2f(x+1,y+6.5);
        glVertex2f(x+2,y+6);
        glVertex2f(x+6,y+2);
        glVertex2f(x+12.0,y-6.3);
        ///LEJ KATA
        glVertex2f(x+20.3,y-15);
        glVertex2f(x+20.4,y-16);
        glVertex2f(x+20.3,y-17);
        glVertex2f(x+19.5,y-18);
        glVertex2f(x+19.0,y-18);
        glVertex2f(x+18.5,y-18);
        glVertex2f(x+18.1,y-18.1);
        glVertex2f(x+16.1,y-17.8);
        glVertex2f(x+14.1,y-17.1);
        glVertex2f(x+10.1,y-15.5);
        glVertex2f(x+2,y-12);
        glVertex2f(x+0,y-11);
        glVertex2f(x-2,y-10);
        glVertex2f(x-4,y-8.5);
        glVertex2f(x-6,y-6.5);
        glVertex2f(x-8,y-3.5);
        glVertex2f(x-9,y-1);
        glVertex2f(x-9.3,y+3.5);
        glVertex2f(x-9,y+4);
        glVertex2f(x-8.7,y+4.5);
        glVertex2f(x-8.5,y+4.5);
        glVertex2f(x-8.3,y+4.7);
        glVertex2f(x-8.1,y+4.9);
        glVertex2f(x-7.5,y+5);
        glVertex2f(x-7,y+5);
        glVertex2f(x-6.5,y+5);
        glVertex2f(x-5,y+5);
    glEnd();
    glFlush();
    //// lejaaa
    glColor3f(0.654, 0.772, 0.862);
    glBegin(GL_POLYGON);
        glVertex2f(x+13,y-8);
        glVertex2f(x+13.5,y-6.5);
        glVertex2f(x+17,y+7);
        glVertex2f(x+21.0,y+4);
        glVertex2f(x+21.5,y+3);
        glVertex2f(x+21.6,y+2);
        glVertex2f(x+19.6,y-7);
        glVertex2f(x+20.0,y-10);
        glVertex2f(x+19.4,y-15);
    glEnd();
    glFlush();

    glColor3f(0.098, 0.462, 0.113);
    glBegin(GL_POLYGON);
        glVertex2f(x+17,y+7);
        glVertex2f(x+21.0,y+4);
        glVertex2f(x+21.5,y+3);
        glVertex2f(x+21.6,y+2);
        glVertex2f(x+19.6,y-7);
    glEnd();
    glFlush();



    //leha border
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x+13,y-8);
        glVertex2f(x+13.5,y-6.5);
        glVertex2f(x+17,y+7);
        glVertex2f(x+21.0,y+4);
        glVertex2f(x+21.5,y+3);
        glVertex2f(x+21.6,y+2);
        glVertex2f(x+19.6,y-7);
        glVertex2f(x+20.0,y-10);
        glVertex2f(x+19.4,y-15);
    glEnd();
    glFlush();
    //paaankha left
    glColor3f(0.654, 0.772, 0.862);
    glBegin(GL_POLYGON);
        glVertex2f(x-7,y-2);
        glVertex2f(x-40,y+1);
        glVertex2f(x-42,y-1);
        glVertex2f(x+4,y-10);
    glEnd();
    glFlush();
    //pankhaaaa border
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x-7,y-2);
        glVertex2f(x-40,y+1);
        glVertex2f(x-42,y-1);
        glVertex2f(x+4,y-10);
    glEnd();
    glFlush();

    //back left pankha
    glColor3f(0.654, 0.772, 0.862);
    glBegin(GL_POLYGON);
        glVertex2f(x+12,y-12);
        glVertex2f(x-4,y-12);
        glVertex2f(x-2,y-14);
        glVertex2f(x+14,y-14);
    glEnd();
    glFlush();

        //back left pankhaaaa border
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x+12,y-12);
        glVertex2f(x-4,y-12);
        glVertex2f(x-2,y-14);
        glVertex2f(x+14,y-14);
    glEnd();
    glFlush();

    //windows

    glColor3f(0.525, 0.870, 0.956);
    glBegin(GL_POLYGON);
        glVertex2f(x-5,y+5);
        glVertex2f(x-4,y+6);
        glVertex2f(x-3.5,y+4);
        glVertex2f(x-2.5,y+1.9);
        glVertex2f(x-4,y+0);
        glVertex2f(x-4.5,y+0.3);
        glVertex2f(x-5,y+1);
        glVertex2f(x-5.5,y+2);
        glVertex2f(x-6,y+3.5);
        glVertex2f(x-5,y+5);
    glEnd();
    glFlush();
        ///////window border///
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x-5,y+5);
        glVertex2f(x-4,y+6);
        glVertex2f(x-3.5,y+4);
        glVertex2f(x-2.5,y+1.9);
        glVertex2f(x-4,y+0);
        glVertex2f(x-4.5,y+0.3);
        glVertex2f(x-5,y+1);
        glVertex2f(x-5.5,y+2);
        glVertex2f(x-6,y+3.5);
        glVertex2f(x-5,y+5);
    glEnd();
    glFlush();

    //2nd window
    glColor3f(0.525, 0.870, 0.956);
    glBegin(GL_POLYGON);
        glVertex2f(x-2,y+1);
        glVertex2f(x-1,y-0.5);
        glVertex2f(x+0.1,y-2.1);
        glVertex2f(x-0.6,y-3.1);
        glVertex2f(x-1,y-4);
        glVertex2f(x-2,y-3);
        glVertex2f(x-3,y-1.5);
        glVertex2f(x-3.5,y-1);
        glVertex2f(x-2,y+1);
    glEnd();
    glFlush();

        ///////2nd window border///
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(x-2,y+1);
        glVertex2f(x-1,y-0.5);
        glVertex2f(x+0.1,y-2.1);
        glVertex2f(x-0.6,y-3.1);
        glVertex2f(x-1,y-4);
        glVertex2f(x-2,y-3);
        glVertex2f(x-3,y-1.5);
        glVertex2f(x-3.5,y-1);
        glVertex2f(x-2,y+1);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    drawCircle(x+18.3,y+1,2);
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    sun(7,-8);
    glPushMatrix();
        glTranslatef(0+runcloud,0,0);
        cloud(-40,10);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0+runcloud,0,0);
        glScalef(.7,.7,0);
        cloud(-20,20);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0-runcloud,0,0);
        glScalef(1.5,1.5,0);
        cloud(20,25);
    glPopMatrix();

    hill();
    //draw trees
    glPushMatrix();
        glScalef(.3,.3,0);
        tree(-20,-55);
    glPopMatrix();

    floor();

    glPushMatrix();
    //cout<<resizee<<endl;
    if(resizee<.40){
        //resizee=.60;
        glColor3f(0,0,0);
        //glRasterPos2f(-40,0);
        glScalef(.02,.02,0);
        showString("Presented By: Pixel");
        glPopMatrix();

    }else{
        glRotatef(spinplane,0,0,1);
        glScalef(resizee,resizee,0);
        glTranslatef(0-runxc,0+runyc,0);
        plane(40,-40);
        glPopMatrix();
    }



    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{

	switch (key) {
		case 'a':
			spinLeft();
			break;
		case 'd':
			spinRight();
			break;
	  default:
			break;
	}
}

int main(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Airplane");
    init();
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(runAnimation);
    glutMainLoop();
    return 0;
}
