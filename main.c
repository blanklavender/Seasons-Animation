#include<stdio.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

int i,day=1,light=1;float pi=3.41;int snow=0,rain=0;
void display();
void reshape(int,int);
void timer();

void circle(float x1,float y1,float r)
{
	for(i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+x1,y+y1);
	}
}

void sky()
{
	glLoadIdentity();
	glColor3f(0.0,0.9,0.9); //sky  RGB 0-255, Float 0-1
    glBegin(GL_POLYGON);
    glVertex2f(0,600);
    glVertex2f(1100,600);
    glVertex2f(1100,0);
    glVertex2f(0,0);
    glEnd();
}

void sun()
{
	glLoadIdentity();
	glBegin(GL_POLYGON); // Sun
    glColor3f(0.976,0.992,0.392);
	circle(550,70,40);
	glEnd();
}

void land()
{
	glLoadIdentity();
	glBegin(GL_POLYGON); //Land
	glColor3f(0.196,0.4,0.117);
	glVertex2f(0.0,600.0);
	glVertex2f(700.0,600.0);
	glColor3f(0.223,0.776,0.043);
	glVertex2f(550.0,450.0);
	glVertex2f(0.0,450.0);
	glEnd();
}

void sea()
{
	glLoadIdentity();
	glBegin(GL_POLYGON); //Sea
	glColor3f(0.188,0.423,0.819);
	glVertex2f(600.0,600.0);
	glVertex2f(1100.0,600.0);
	glVertex2f(1100.0,500.0);
	glVertex2f(600.0,500.0);
	glEnd();
}

void icesea()
{
	glLoadIdentity();
	glBegin(GL_POLYGON); //ice Sea
	glColor3f(0.188,0.423,0.819);
	glVertex2f(600.0,600.0);
	glVertex2f(1100.0,600.0);
	glColor3f(0.796,0.854,0.972);
	glVertex2f(1100.0,500.0);
	glVertex2f(600.0,500.0);
	glEnd();
}

float a=1,b=1;

void wave1()
{
	glLoadIdentity();
	glTranslatef(a,0.0,0.0);
	glBegin(GL_POLYGON); //Wave 1
	glColor3f(0.188,0.423,0.819);
	glVertex2f(600.0,500.0);
	glVertex2f(650.0,500.0);
	glVertex2f(625.0,470.0);
	glEnd();
}

void wave2()
{
	glLoadIdentity();
	glTranslatef(b,0.0,0.0);
	glBegin(GL_POLYGON); //Wave 1
	glColor3f(0.188,0.423,0.819);
	glVertex2f(850.0,500.0);
	glVertex2f(900.0,500.0);
	glVertex2f(875.0,470.0);
	glEnd();
}

void house()
{
	glLoadIdentity();
	glBegin(GL_POLYGON); //walls
	glColor3f(0.803,0.694,0.270);
	glVertex2f(70.0,450.0);
	glVertex2f(350.0,450.0);
	glVertex2f(350.0,310.0);
	glVertex2f(70.0,310.0);
	glEnd();
	
	glBegin(GL_POLYGON); //roof
	glColor3f(0.35,0.0,0.0);
	glVertex2f(70.0,310.0);
	glVertex2f(350.0,310.0);
	glVertex2f(300.0,255.0);
	glVertex2f(120.0,255.0);
	glEnd();
	
}

void room1()
{
	glLoadIdentity();
	glBegin(GL_POLYGON); //window 1
	glColor3f(0.972,0.835,0.470);
	glVertex2f(90.0,380.0);
	glVertex2f(140.0,380.0);
	glColor3f(0.988,0.925,0.760);
	glVertex2f(140.0,330.0);
	glVertex2f(90.0,330.0);
	glEnd();
	
	glBegin(GL_POLYGON); //window 2
	glColor3f(0.972,0.835,0.470);
	glVertex2f(280.0,380.0);
	glVertex2f(330.0,380.0);
	glColor3f(0.988,0.925,0.760);
	glVertex2f(330.0,330.0);
	glVertex2f(280.0,330.0);
	glEnd();
	
	glBegin(GL_POLYGON); //door
	glColor3f(0.972,0.835,0.470);
	glVertex2f(180.0,450.0);
	glVertex2f(240.0,450.0);
	glColor3f(0.988,0.925,0.760);
	glVertex2f(240.0,390.0);
	glVertex2f(180.0,390.0);
	glEnd();
}

void room2()
{
	glLoadIdentity();
	glBegin(GL_POLYGON); //window 1
	glColor3f(0.725,0.537,0.043);
	glVertex2f(90.0,380.0);
	glVertex2f(140.0,380.0);
	glColor3f(0.443,0.329,0.023);
	glVertex2f(140.0,330.0);
	glVertex2f(90.0,330.0);
	glEnd();
	
	glBegin(GL_POLYGON); //window 2
	glColor3f(0.725,0.537,0.043);
	glVertex2f(280.0,380.0);
	glVertex2f(330.0,380.0);
	glColor3f(0.443,0.329,0.023);
	glVertex2f(330.0,330.0);
	glVertex2f(280.0,330.0);
	glEnd();
	
	glBegin(GL_POLYGON); //door
	glColor3f(0.725,0.537,0.043);
	glVertex2f(180.0,450.0);
	glVertex2f(240.0,450.0);
	glColor3f(0.443,0.329,0.023);
	glVertex2f(240.0,390.0);
	glVertex2f(180.0,390.0);
	glEnd();
}

void darksky()
{
	glLoadIdentity();
	glColor3f(0.721,0.721,0.721); //dark sky
    glBegin(GL_POLYGON);
    glVertex2f(0,600);
    glVertex2f(1100,600);
    glVertex2f(1100,0);
    glVertex2f(0,0);
    glEnd();
    
}

void lightsky()
{
	glLoadIdentity();
	glColor3f(0.517,0.925,0.843); //light sky
    glBegin(GL_POLYGON);
    glVertex2f(0,600);
    glVertex2f(1100,600);
    glVertex2f(1100,0);
    glVertex2f(0,0);
    glEnd();
    
}

float p=1,q=1;

void cloud1()
{
	glLoadIdentity();
    glTranslatef(p,0.0,0.0);
    //cloud1
    glBegin(GL_POLYGON); // Cloud
    glColor3f(1.0,1.0,1.0);
	circle(160,80,20);
	glEnd();
	glBegin(GL_POLYGON); // Cloud
    glColor3f(1.0,1.0,1.0);
	circle(200,80,30);
	glEnd();
	glBegin(GL_POLYGON); // Cloud
    glColor3f(1.0,1.0,1.0);
	circle(240,80,20);
	glEnd();
}

void cloud2()
{
	glLoadIdentity();
    glTranslatef(q,0.0,0.0);
	//cloud2
	glBegin(GL_POLYGON); // Cloud
    glColor3f(1.0,1.0,1.0);
	circle(860,150,20);
	glEnd();
	glBegin(GL_POLYGON); // Cloud
    glColor3f(1.0,1.0,1.0);
	circle(900,150,30);
	glEnd();
	glBegin(GL_POLYGON); // Cloud
    glColor3f(1.0,1.0,1.0);
	circle(940,150,20);
	glEnd();
}

float r=1;

void fullrain()
{
	//line1
	glLoadIdentity();
	glTranslatef(r,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line2
	glLoadIdentity();
	glTranslatef(r+150,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line3
	glLoadIdentity();
	glTranslatef(r+300,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line4
	glLoadIdentity();
	glTranslatef(r+450,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line5
	glLoadIdentity();
	glTranslatef(r+600,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line6
	glLoadIdentity();
	glTranslatef(r+750,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line7
	glLoadIdentity();
	glTranslatef(r+900,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line8
	glLoadIdentity();
	glTranslatef(r-150,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line9
	glLoadIdentity();
	glTranslatef(r-300,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line10
	glLoadIdentity();
	glTranslatef(r+1050,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
	
	//line11
	glLoadIdentity();
	glTranslatef(r-450,r,0.0);
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);
	glVertex2f(40,40);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-40,-40);
	glVertex2f(-80,-80);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-120,-120);
	glVertex2f(-160,-160);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-200,-200);
	glVertex2f(-240,-240);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-280,-280);
	glVertex2f(-320,-320);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-360,-360);
	glVertex2f(-400,-400);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-440,-440);
	glVertex2f(-480,-480);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-520,-520);
	glVertex2f(-560,-560);
	glEnd();
}

float s=1;

void snowy()
{
	//line1
	glLoadIdentity();
	glTranslatef(s,s,0.0);
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-20,-20,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-120,-120,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-220,-220,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-320,-320,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-420,-420,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-520,-520,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-620,-620,12);
	glEnd();
	
	//line2
	glLoadIdentity();
	glTranslatef(s+250,s,0.0);
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-20,-20,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-120,-120,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-220,-220,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-320,-320,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-420,-420,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-520,-520,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-620,-620,12);
	glEnd();
	
	//line3
	glLoadIdentity();
	glTranslatef(s+500,s,0.0);
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-20,-20,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-120,-120,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-220,-220,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-320,-320,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-420,-420,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-520,-520,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-620,-620,12);
	glEnd();
	
	//line4
	glLoadIdentity();
	glTranslatef(s-250,s,0.0);
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-20,-20,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-120,-120,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-220,-220,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-320,-320,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-420,-420,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-520,-520,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-620,-620,12);
	glEnd();
	
	//line5
	glLoadIdentity();
	glTranslatef(s+750,s,0.0);
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-20,-20,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-120,-120,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-220,-220,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-320,-320,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-420,-420,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-520,-520,12);
	glEnd();
	
	glBegin(GL_POLYGON); //Snow ball
    glColor3f(1.0,1.0,1.0);
	circle(-620,-620,12);
	glEnd();
}

void timer()
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);
	
	p+=5;      //cloud1
	if(p>1100)
	p=-550;
	
	q+=5;      //cloud2
	if(q>300)
	q=-950;
	
	r+=5;      //rain
	if(r>605)
	r=-20;
	
	s+=5;      //snow
	if(s>605)
	s=-20;
	
	a+=3;      //wave1
	if(a>520)
	a=0;
	
	b+=3;      //wave2
	if(b>260)
	b=-260;
	
}

void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
    case 'd':
	  case 'D':
		day=1;rain=0;snow=0;
		break;
	case 'r':
	  case 'R':
		day=0;rain=1;snow=0;
		break;
	case 's':
	  case 'S':
		day=0;rain=0;snow=1;
		break;
	case 'l':
	  case 'L':
		light=1;
		break;
	case 'o':
	  case 'O':
		light=0;
		break;
    }
}

void init()
{
	glClearColor(1.0,1.0,1.0,1.0); 
}

int main(int argc, char**argv)  
{
	printf("------------------CG MINI PROJECT 2021-----------------\n");
	printf("\t           Group Members:\n");
	printf("\tMahima Rudrapati   \t 1020239\n");
	printf("\tMachlin Jeya Sekar \t 1020242\n");
	printf("\tSebasty Wilson     \t 1020263\n");
	printf("\nInstructions:\n");
	printf("\n 1.Press 'D' for a SUNNY DAY\n");
	printf("\n 2.Press 'R' for a RAINY DAY\n"); 
	printf("\n 3.Press 'S' for a SNOWY DAY\n");
	printf("\n 4.Press 'L' to turn ON light\n");
	printf("\n 5.Press 'O' to turn OFF light\n");
    printf("\n---------------------THANK YOU-----------------------\n");
	
	
	glutInit(&argc,argv);  
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  
	
	glutInitWindowPosition(10,10);
	glutInitWindowSize(1100,600);
	
	glutCreateWindow("Seasons Animation");
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunc); 
	glutReshapeFunc(reshape);  
	glutTimerFunc(0,timer,0); 
	
	init();  //to change bg color
	
	glutMainLoop(); 
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);  
	glLoadIdentity();    
	 
	if (day==1)
	{
	sky();
    sun();
    wave1();
	wave2();
	sea();
	land();
	house();
	if (light==1)
		room1();
	if (light==0)
		room2();
	cloud1();
	cloud2();
	wave1();
	wave2();
	}
	if (rain==1)
	{
	darksky();
	wave1();
	wave2();
	sea();
	land();
	house();
	if (light==1)
		room1();
	if (light==0)
		room2();
	cloud1();
	cloud2();
	fullrain();
	}
	if (snow==1)
	{
	lightsky();
	icesea();
	land();
	house();
	if (light==1)
		room1();
	if (light==0)
		room2();
	snowy();
	}
	
	glutSwapBuffers();   
}

void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);  //(GLsizei) is used to convert to int ig
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   //resets projection view matrix
	gluOrtho2D(0.0,1100,600,0.0);
	glMatrixMode(GL_MODELVIEW);
}
