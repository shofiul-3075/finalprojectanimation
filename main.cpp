#include<windows.h>
#include <GL/glut.h>


#include <cmath>
#define FILL true
#define NOT_FILL false




float xPos = 0.0f;
float yPos = 0.0f;

float x1Pos = 0.0f;

float x2Pos = 0.0f;

float x3Pos = 0.0f;

float angle1 = 0.0f;


float a,b,c;







void makeCircle(float r, double x_center, double y_center,bool isFill)
{
    float deg = 0;
    double theta, x, y;

    glPointSize(3);
    if(isFill)
    {
        glBegin(GL_TRIANGLE_FAN);
    }
    else
    {
        glBegin(GL_POINTS);
    }
    glPointSize(3);

    while(deg < 360)
    {

        theta = (deg*M_PI)/180;
        x = x_center + r*cos(theta);
        y = y_center + r*sin(theta);


        glVertex2d(x, y);
        deg+=1;
    }
    glEnd();
}

void drawSnRays(float r, double x_center, double y_center)
{
    float deg = 0;
    double theta, x0 = 0, y0 = 0, x1 =0, y1 =0;

    glLineWidth(0.30);
    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_LINES);
    while(deg <= 360)
    {

        theta = (deg*M_PI)/180;
        x0 = x_center + (r+0.05)*cos(theta);
        y0 = y_center + (r+0.05)*sin(theta);
        x1 = x_center + (r+0.07)*cos(theta);
        y1 = y_center + (r+0.07)*sin(theta);

        glVertex2d(x0, y0);
        glVertex2d(x1, y1);
        deg+=10;
    }
    glEnd();
}








void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Draw a square using two triangles


//Sun
    glColor3f(1.0, 1.0, 0.0);
    makeCircle(0.05,0.30,0.90,FILL);
    drawSnRays(0.02,0.30,0.90);


//Cloud-1

    glPushMatrix();
    glTranslatef(x1Pos, 0.0f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    makeCircle(0.03,0.55,0.90,FILL);

    glColor3f(1.0, 1.0, 1.0);
    makeCircle(0.03,0.58,0.92,FILL);

    glColor3f(1.0, 1.0, 1.0);
    makeCircle(0.03,0.56,0.93,FILL);

    glPopMatrix();



//Cloud-2

    glPushMatrix();
    glTranslatef(x1Pos, 0.0f, 0.0f);

    glColor3f(1.0, 1.0, 1.0);
    makeCircle(0.03,0.50,0.80,FILL);

    glColor3f(1.0, 1.0, 1.0);
    makeCircle(0.03,0.53,0.82,FILL);

    glColor3f(1.0, 1.0, 1.0);
    makeCircle(0.03,0.51,0.83,FILL);

    glPopMatrix();


//poka
    glPushMatrix();

    glRotatef(angle1, 1.0f, 1.0f, 0.0f);

    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.40, 0.95, 0.00);
    glVertex3f(0.41, 0.95, 0.00);
    glEnd();

    glPopMatrix();





//Background of Under Road

    glBegin(GL_QUADS);
    glColor3f(0.50, 0.70, 0.50);
    glVertex3f(0.0, 0.55, 0.00);
    glVertex3f(1.0, 0.55, 0.00);
    glVertex3f(1.0, 0.0, 0.00);
    glVertex3f(0.0, 0.0, 0.00);
    glEnd();


//Plen

    glPushMatrix();
    glTranslatef(xPos, 0.0f, 0.0f);


    glBegin(GL_QUADS);
    glColor3f(0.50, 0.70, 0.50);
    glVertex3f(0.05, 0.92, 0.00);
    glVertex3f(0.10, 0.92, 0.00);
    glVertex3f(0.10, 0.90, 0.00);
    glVertex3f(0.05, 0.90, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.20, 0.0, 0.0);
    glVertex3f(0.10, 0.92, 0.00);
    glVertex3f(0.11, 0.91, 0.00);
    glVertex3f(0.10, 0.90, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.20, 0.0, 0.0);
    glVertex3f(0.05, 0.94, 0.00);
    glVertex3f(0.06, 0.92, 0.00);
    glVertex3f(0.05, 0.92, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.20, 0.0, 0.0);
    glVertex3f(0.06, 0.95, 0.00);
    glVertex3f(0.07, 0.95, 0.00);
    glVertex3f(0.08, 0.92, 0.00);
    glVertex3f(0.07, 0.92, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.20, 0.0, 0.0);
    glVertex3f(0.07, 0.90, 0.00);
    glVertex3f(0.08, 0.90, 0.00);
    glVertex3f(0.07, 0.87, 0.00);
    glVertex3f(0.06, 0.87, 0.00);
    glEnd();

    glPopMatrix();









//Road

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.30, 0.30);
    glVertex3f(0.0, 0.61, 0.00);
    glVertex3f(1.0, 0.61, 0.00);
    glVertex3f(1.0, 0.55, 0.00);
    glVertex3f(0.0, 0.55, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 0.58, 0.00);
    glVertex3f(0.05, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.10, 0.58, 0.00);
    glVertex3f(0.15, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.20, 0.58, 0.00);
    glVertex3f(0.25, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.30, 0.58, 0.00);
    glVertex3f(0.35, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.40, 0.58, 0.00);
    glVertex3f(0.45, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.50, 0.58, 0.00);
    glVertex3f(0.55, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.60, 0.58, 0.00);
    glVertex3f(0.65, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.70, 0.58, 0.00);
    glVertex3f(0.75, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.80, 0.58, 0.00);
    glVertex3f(0.85, 0.58, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.90, 0.58, 0.00);
    glVertex3f(0.95, 0.58, 0.00);
    glEnd();

//building

    glBegin(GL_QUADS);
    glColor3f(0.50, 0.0, 0.50);
    glVertex3f(0.95, 0.80, 0.00);
    glVertex3f(1.0, 0.80, 0.00);
    glVertex3f(1.0, 0.61, 0.00);
    glVertex3f(0.95, 0.61, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.97, 0.77, 0.00);
    glVertex3f(0.98, 0.77, 0.00);
    glVertex3f(0.98, 0.74, 0.00);
    glVertex3f(0.97, 0.74, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.97, 0.70, 0.00);
    glVertex3f(0.98, 0.70, 0.00);
    glVertex3f(0.98, 0.65, 0.00);
    glVertex3f(0.97, 0.65, 0.00);
    glEnd();

//middle building

    glBegin(GL_QUADS);
    glColor3f(0.70, 0.0, 1.0);
    glVertex3f(0.90, 0.75, 0.00);
    glVertex3f(0.95, 0.75, 0.00);
    glVertex3f(0.95, 0.61, 0.00);
    glVertex3f(0.90, 0.61, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.92, 0.73, 0.00);
    glVertex3f(0.93, 0.73, 0.00);
    glVertex3f(0.93, 0.69, 0.00);
    glVertex3f(0.92, 0.69, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.92, 0.67, 0.00);
    glVertex3f(0.93, 0.67, 0.00);
    glVertex3f(0.93, 0.63, 0.00);
    glVertex3f(0.92, 0.63, 0.00);
    glEnd();

//3rd building

    glBegin(GL_QUADS);
    glColor3f(0.20, 0.10, 0.70);
    glVertex3f(0.85, 0.85, 0.00);
    glVertex3f(0.90, 0.85, 0.00);
    glVertex3f(0.90, 0.61, 0.00);
    glVertex3f(0.85, 0.61, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.87, 0.67, 0.00);
    glVertex3f(0.88, 0.67, 0.00);
    glVertex3f(0.88, 0.63, 0.00);
    glVertex3f(0.87, 0.63, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.87, 0.73, 0.00);
    glVertex3f(0.88, 0.73, 0.00);
    glVertex3f(0.88, 0.69, 0.00);
    glVertex3f(0.87, 0.69, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.87, 0.79, 0.00);
    glVertex3f(0.88, 0.79, 0.00);
    glVertex3f(0.88, 0.75, 0.00);
    glVertex3f(0.87, 0.75, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.87, 0.85, 0.00);
    glVertex3f(0.88, 0.85, 0.00);
    glVertex3f(0.88, 0.81, 0.00);
    glVertex3f(0.87, 0.81, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.10, 0.10, 0.50);
    glVertex3f(0.83, 0.80, 0.00);
    glVertex3f(0.85, 0.85, 0.00);
    glVertex3f(0.85, 0.61, 0.00);
    glVertex3f(0.83, 0.65, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.20, 0.10, 0.70);
    glVertex3f(0.87, 0.85, 0.00);
    glVertex3f(0.88, 0.85, 0.00);
    glEnd();



//4th building


    glBegin(GL_QUADS);
    glColor3f(01.70, 0.20, 1.0);
    glVertex3f(0.70, 0.75, 0.00);
    glVertex3f(0.75, 0.75, 0.00);
    glVertex3f(0.75, 0.61, 0.00);
    glVertex3f(0.70, 0.61, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.72, 0.73, 0.00);
    glVertex3f(0.73, 0.73, 0.00);
    glVertex3f(0.73, 0.69, 0.00);
    glVertex3f(0.72, 0.69, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.72, 0.67, 0.00);
    glVertex3f(0.73, 0.67, 0.00);
    glVertex3f(0.73, 0.63, 0.00);
    glVertex3f(0.72, 0.63, 0.00);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.70, 0.75, 0.00);
    glVertex3f(0.72, 0.77, 0.00);
    glVertex3f(0.75, 0.75, 0.00);
    glEnd();


//5th building

    glBegin(GL_QUADS);
    glColor3f(a, b, c);
    glVertex3f(0.65, 0.75, 0.00);
    glVertex3f(0.70, 0.75, 0.00);
    glVertex3f(0.70, 0.61, 0.00);
    glVertex3f(0.65, 0.61, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.67, 0.73, 0.00);
    glVertex3f(0.68, 0.73, 0.00);
    glVertex3f(0.68, 0.69, 0.00);
    glVertex3f(0.67, 0.69, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.67, 0.67, 0.00);
    glVertex3f(0.68, 0.67, 0.00);
    glVertex3f(0.68, 0.63, 0.00);
    glVertex3f(0.67, 0.63, 0.00);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.40, 0.40, 0.40);
    glVertex3f(0.64, 0.72, 0.00);
    glVertex3f(0.65, 0.75, 0.00);
    glVertex3f(0.65, 0.61, 0.00);
    glVertex3f(0.64, 0.63, 0.00);
    glEnd();












//hill

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.0, 0.71, 0.00);
    glVertex3f(0.07, 0.85, 0.00);
    glVertex3f(0.20, 0.61, 0.00);
    glVertex3f(0.0, 0.61, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.12, 0.75, 0.00);
    glVertex3f(0.20, 0.85, 0.00);
    glVertex3f(0.31, 0.61, 0.00);
    glVertex3f(0.20, 0.61, 0.00);
    glEnd();


//Ghash

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.27, 0.61, 0.00);
    glVertex3f(0.28, 0.65, 0.00);
    glVertex3f(0.275, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.275, 0.61, 0.00);
    glVertex3f(0.285, 0.66, 0.00);
    glVertex3f(0.28, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.28, 0.61, 0.00);
    glVertex3f(0.29, 0.65, 0.00);
    glVertex3f(0.285, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.30, 0.61, 0.00);
    glVertex3f(0.31, 0.65, 0.00);
    glVertex3f(0.305, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.305, 0.61, 0.00);
    glVertex3f(0.315, 0.66, 0.00);
    glVertex3f(0.31, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.31, 0.61, 0.00);
    glVertex3f(0.32, 0.65, 0.00);
    glVertex3f(0.315, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.315, 0.61, 0.00);
    glVertex3f(0.325, 0.67, 0.00);
    glVertex3f(0.32, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.32, 0.61, 0.00);
    glVertex3f(0.33, 0.65, 0.00);
    glVertex3f(0.325, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.02, 0.61, 0.00);
    glVertex3f(0.03, 0.65, 0.00);
    glVertex3f(0.025, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.025, 0.61, 0.00);
    glVertex3f(0.035, 0.65, 0.00);
    glVertex3f(0.03, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.03, 0.61, 0.00);
    glVertex3f(0.04, 0.66, 0.00);
    glVertex3f(0.035, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.035, 0.61, 0.00);
    glVertex3f(0.045, 0.65, 0.00);
    glVertex3f(0.04, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.05, 0.61, 0.00);
    glVertex3f(0.06, 0.65, 0.00);
    glVertex3f(0.055, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.055, 0.61, 0.00);
    glVertex3f(0.065, 0.66, 0.00);
    glVertex3f(0.06, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.06, 0.61, 0.00);
    glVertex3f(0.07, 0.65, 0.00);
    glVertex3f(0.065, 0.61, 0.00);
    glEnd();







    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.17, 0.61, 0.00);
    glVertex3f(0.18, 0.65, 0.00);
    glVertex3f(0.175, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.175, 0.61, 0.00);
    glVertex3f(0.185, 0.66, 0.00);
    glVertex3f(0.18, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.18, 0.61, 0.00);
    glVertex3f(0.19, 0.65, 0.00);
    glVertex3f(0.185, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.20, 0.61, 0.00);
    glVertex3f(0.21, 0.65, 0.00);
    glVertex3f(0.205, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.205, 0.61, 0.00);
    glVertex3f(0.215, 0.66, 0.00);
    glVertex3f(0.21, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.21, 0.61, 0.00);
    glVertex3f(0.22, 0.65, 0.00);
    glVertex3f(0.215, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.215, 0.61, 0.00);
    glVertex3f(0.225, 0.67, 0.00);
    glVertex3f(0.22, 0.61, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.22, 0.61, 0.00);
    glVertex3f(0.23, 0.65, 0.00);
    glVertex3f(0.225, 0.61, 0.00);
    glEnd();










//River


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.90);
    glVertex3f(0.52, 0.15, 0.00);
    glVertex3f(1.0, 0.15, 0.00);
    glVertex3f(1.0, 0.0, 0.00);
    glVertex3f(0.50, 0.0, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.90);
    glVertex3f(0.0, 0.10, 0.00);
    glVertex3f(1.0, 0.10, 0.00);
    glVertex3f(1.0, 0.0, 0.00);
    glVertex3f(0.0, 0.0, 0.00);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.90);
    glVertex3f(0.55, 0.25, 0.00);
    glVertex3f(1.0, 0.25, 0.00);
    glVertex3f(1.0, 0.15, 0.00);
    glVertex3f(0.52, 0.15, 0.00);
    glVertex3f(0.50, 0.20, 0.00);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.90);
    glVertex3f(0.55, 0.25, 0.00);
    glVertex3f(0.50, 0.40, 0.00);
    glVertex3f(0.60, 0.50, 0.00);
    glVertex3f(1.0, 0.55, 0.00);
    glVertex3f(1.0, 0.25, 0.00);
    glEnd();

//nodi par

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.0, 0.10, 0.00);
    glVertex3f(0.51, 0.10, 0.00);
    glVertex3f(0.515, 0.09, 0.00);
    glVertex3f(0.0, 0.09, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.50, 0.15, 0.00);
    glVertex3f(0.52, 0.15, 0.00);
    glVertex3f(0.515, 0.10, 0.00);
    glVertex3f(0.49, 0.10, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.48, 0.20, 0.00);
    glVertex3f(0.50, 0.20, 0.00);
    glVertex3f(0.52, 0.15, 0.00);
    glVertex3f(0.50, 0.15, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.52, 0.25, 0.00);
    glVertex3f(0.55, 0.25, 0.00);
    glVertex3f(0.50, 0.20, 0.00);
    glVertex3f(0.48, 0.20, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.48, 0.40, 0.00);
    glVertex3f(0.50, 0.40, 0.00);
    glVertex3f(0.55, 0.25, 0.00);
    glVertex3f(0.52, 0.25, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.58, 0.50, 0.00);
    glVertex3f(0.60, 0.50, 0.00);
    glVertex3f(0.50, 0.40, 0.00);
    glVertex3f(0.48, 0.40, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.40, 0.50);
    glVertex3f(0.58, 0.50, 0.00);
    glVertex3f(0.85, 0.55, 0.00);
    glVertex3f(1.0, 0.55, 0.00);
    glVertex3f(0.60, 0.50, 0.00);
    glEnd();

//Tree-1

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.10, 0.40, 0.00);
    glVertex3f(0.12, 0.40, 0.00);
    glVertex3f(0.12, 0.30, 0.00);
    glVertex3f(0.10, 0.30, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.10, 0.35, 0.00);
    glVertex3f(0.12, 0.35, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.10, 0.36, 0.00);
    glVertex3f(0.12, 0.36, 0.00);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.07, 0.40, 0.00);
    glVertex3f(0.11, 0.46, 0.00);
    glVertex3f(0.15, 0.40, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.07, 0.43, 0.00);
    glVertex3f(0.11, 0.51, 0.00);
    glVertex3f(0.15, 0.43, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.08, 0.48, 0.00);
    glVertex3f(0.11, 0.53, 0.00);
    glVertex3f(0.14, 0.48, 0.00);
    glEnd();





//2nd tree

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.03, 0.35, 0.00);
    glVertex3f(0.05, 0.35, 0.00);
    glVertex3f(0.05, 0.25, 0.00);
    glVertex3f(0.03, 0.25, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.03, 0.30, 0.00);
    glVertex3f(0.05, 0.30, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.03, 0.31, 0.00);
    glVertex3f(0.05, 0.31, 0.00);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.70, 0.0);
    glVertex3f(0.0, 0.35, 0.00);
    glVertex3f(0.04, 0.41, 0.00);
    glVertex3f(0.08, 0.35, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.70, 0.0);
    glVertex3f(0.0, 0.38, 0.00);
    glVertex3f(0.04, 0.46, 0.00);
    glVertex3f(0.08, 0.38, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.70, 0.0);
    glVertex3f(0.01, 0.43, 0.00);
    glVertex3f(0.04, 0.48, 0.00);
    glVertex3f(0.07, 0.43, 0.00);
    glEnd();

//3rd tree

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.05, 0.30, 0.00);
    glVertex3f(0.07, 0.30, 0.00);
    glVertex3f(0.07, 0.20, 0.00);
    glVertex3f(0.05, 0.20, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.05, 0.25, 0.00);
    glVertex3f(0.07, 0.25, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.05, 0.26, 0.00);
    glVertex3f(0.07, 0.26, 0.00);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.77, 0.87, 0.0);
    glVertex3f(0.02, 0.30, 0.00);
    glVertex3f(0.06, 0.36, 0.00);
    glVertex3f(0.10, 0.30, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.77, 0.87, 0.0);
    glVertex3f(0.02, 0.33, 0.00);
    glVertex3f(0.06, 0.41, 0.00);
    glVertex3f(0.10, 0.33, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.77, 0.87, 0.0);
    glVertex3f(0.03, 0.38, 0.00);
    glVertex3f(0.06, 0.43, 0.00);
    glVertex3f(0.09, 0.38, 0.00);
    glEnd();


//4th tree

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.40, 0.40, 0.00);
    glVertex3f(0.42, 0.40, 0.00);
    glVertex3f(0.42, 0.30, 0.00);
    glVertex3f(0.40, 0.30, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.40, 0.35, 0.00);
    glVertex3f(0.42, 0.35, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.0);
    glVertex3f(0.40, 0.36, 0.00);
    glVertex3f(0.42, 0.36, 0.00);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.70, 0.0);
    glVertex3f(0.37, 0.40, 0.00);
    glVertex3f(0.41, 0.46, 0.00);
    glVertex3f(0.45, 0.40, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.70, 0.0);
    glVertex3f(0.37, 0.43, 0.00);
    glVertex3f(0.41, 0.51, 0.00);
    glVertex3f(0.45, 0.43, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.10, 0.70, 0.0);
    glVertex3f(0.38, 0.48, 0.00);
    glVertex3f(0.41, 0.53, 0.00);
    glVertex3f(0.44, 0.48, 0.00);
    glEnd();









//house-2

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.50, 0.70);
    glVertex3f(0.10, 0.15, 0.00);
    glVertex3f(0.30, 0.15, 0.00);
    glVertex3f(0.30, 0.30, 0.00);
    glVertex3f(0.20, 0.35, 0.00);
    glVertex3f(0.10, 0.30, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.30, 0.30);
    glVertex3f(0.30, 0.30, 0.00);
    glVertex3f(0.35, 0.30, 0.00);
    glVertex3f(0.20, 0.40, 0.00);
    glVertex3f(0.20, 0.35, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.30, 0.30);
    glVertex3f(0.20, 0.40, 0.00);
    glVertex3f(0.20, 0.35, 0.00);
    glVertex3f(0.10, 0.30, 0.00);
    glVertex3f(0.05, 0.30, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.30, 0.30, 0.30);
    glVertex3f(0.30, 0.33, 0.00);
    glVertex3f(0.30, 0.45, 0.00);
    glVertex3f(0.25, 0.45, 0.00);
    glVertex3f(0.25, 0.36, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.10, 0.20);
    glVertex3f(0.31, 0.45, 0.00);
    glVertex3f(0.31, 0.46, 0.00);
    glVertex3f(0.24, 0.46, 0.00);
    glVertex3f(0.24, 0.45, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.80, 0.80, 0.80);
    glVertex3f(0.28, 0.15, 0.00);
    glVertex3f(0.28, 0.28, 0.00);
    glVertex3f(0.20, 0.28, 0.00);
    glVertex3f(0.20, 0.15, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.28, 0.28, 0.00);
    glVertex3f(0.28, 0.15, 0.00);
    glVertex3f(0.23, 0.17, 0.00);
    glVertex3f(0.23, 0.26, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.80, 0.80, 0.80);
    glVertex3f(0.18, 0.22, 0.00);
    glVertex3f(0.18, 0.28, 0.00);
    glVertex3f(0.12, 0.28, 0.00);
    glVertex3f(0.12, 0.22, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.18, 0.22, 0.00);
    glVertex3f(0.18, 0.28, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.18, 0.28, 0.00);
    glVertex3f(0.12, 0.28, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.12, 0.28, 0.00);
    glVertex3f(0.12, 0.22, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.12, 0.22, 0.00);
    glVertex3f(0.18, 0.22, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.18, 0.25, 0.00);
    glVertex3f(0.12, 0.25, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.15, 0.22, 0.00);
    glVertex3f(0.15, 0.28, 0.00);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.20, 0.15, 0.00);
    glVertex3f(0.20, 0.28, 0.00);
    glVertex3f(0.28, 0.28, 0.00);
    glVertex3f(0.28, 0.15, 0.00);
    glEnd();




//2nd house

    glBegin(GL_QUADS);
    glColor3f(0.60, 0.50, 0.40);
    glVertex3f(0.40, 0.35, 0.00);
    glVertex3f(0.45, 0.35, 0.00);
    glVertex3f(0.45, 0.25, 0.00);
    glVertex3f(0.40, 0.25, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.10, 0.20, 0.10);
    glVertex3f(0.40, 0.35, 0.00);
    glVertex3f(0.425, 0.37, 0.00);
    glVertex3f(0.45, 0.35, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.41, 0.32, 0.00);
    glVertex3f(0.44, 0.32, 0.00);
    glVertex3f(0.44, 0.25, 0.00);
    glVertex3f(0.41, 0.25, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.80, 0.80, 0.80);
    glVertex3f(0.425, 0.32, 0.00);
    glVertex3f(0.425, 0.25, 0.00);
    glEnd();



//River er oporer ghas

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.27, 0.10, 0.00);
    glVertex3f(0.28, 0.15, 0.00);
    glVertex3f(0.275, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.275, 0.10, 0.00);
    glVertex3f(0.285, 0.16, 0.00);
    glVertex3f(0.28, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.28, 0.10, 0.00);
    glVertex3f(0.29, 0.15, 0.00);
    glVertex3f(0.285, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.30, 0.10, 0.00);
    glVertex3f(0.31, 0.15, 0.00);
    glVertex3f(0.305, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.305, 0.10, 0.00);
    glVertex3f(0.315, 0.16, 0.00);
    glVertex3f(0.31, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.31, 0.10, 0.00);
    glVertex3f(0.32, 0.15, 0.00);
    glVertex3f(0.315, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.315, 0.10, 0.00);
    glVertex3f(0.325, 0.17, 0.00);
    glVertex3f(0.32, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.32, 0.10, 0.00);
    glVertex3f(0.33, 0.15, 0.00);
    glVertex3f(0.325, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.02, 0.10, 0.00);
    glVertex3f(0.03, 0.15, 0.00);
    glVertex3f(0.025, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.025, 0.10, 0.00);
    glVertex3f(0.035, 0.15, 0.00);
    glVertex3f(0.03, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.03, 0.10, 0.00);
    glVertex3f(0.04, 0.15, 0.00);
    glVertex3f(0.035, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.035, 0.10, 0.00);
    glVertex3f(0.045, 0.14, 0.00);
    glVertex3f(0.04, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.05, 0.10, 0.00);
    glVertex3f(0.06, 0.14, 0.00);
    glVertex3f(0.055, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.055, 0.10, 0.00);
    glVertex3f(0.065, 0.15, 0.00);
    glVertex3f(0.06, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.06, 0.10, 0.00);
    glVertex3f(0.07, 0.14, 0.00);
    glVertex3f(0.065, 0.10, 0.00);
    glEnd();







    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.17, 0.10, 0.00);
    glVertex3f(0.18, 0.14, 0.00);
    glVertex3f(0.175, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.175, 0.10, 0.00);
    glVertex3f(0.185, 0.15, 0.00);
    glVertex3f(0.18, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.18, 0.10, 0.00);
    glVertex3f(0.19, 0.14, 0.00);
    glVertex3f(0.185, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.20, 0.10, 0.00);
    glVertex3f(0.21, 0.14, 0.00);
    glVertex3f(0.205, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.205, 0.10, 0.00);
    glVertex3f(0.215, 0.15, 0.00);
    glVertex3f(0.21, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.21, 0.10, 0.00);
    glVertex3f(0.22, 0.14, 0.00);
    glVertex3f(0.215, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.215, 0.10, 0.00);
    glVertex3f(0.225, 0.16, 0.00);
    glVertex3f(0.22, 0.10, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.90, 0.0);
    glVertex3f(0.22, 0.10, 0.00);
    glVertex3f(0.23, 0.14, 0.00);
    glVertex3f(0.225, 0.10, 0.00);
    glEnd();








//Wall

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.32, 0.23, 0.00);
    glVertex3f(0.32, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.33, 0.23, 0.00);
    glVertex3f(0.33, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.34, 0.23, 0.00);
    glVertex3f(0.34, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.35, 0.23, 0.00);
    glVertex3f(0.35, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.36, 0.23, 0.00);
    glVertex3f(0.36, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.37, 0.23, 0.00);
    glVertex3f(0.37, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.38, 0.23, 0.00);
    glVertex3f(0.38, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.39, 0.23, 0.00);
    glVertex3f(0.39, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.40, 0.23, 0.00);
    glVertex3f(0.40, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.41, 0.23, 0.00);
    glVertex3f(0.41, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.42, 0.23, 0.00);
    glVertex3f(0.42, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.43, 0.23, 0.00);
    glVertex3f(0.43, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.44, 0.23, 0.00);
    glVertex3f(0.44, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.45, 0.23, 0.00);
    glVertex3f(0.45, 0.15, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.46, 0.23, 0.00);
    glVertex3f(0.46, 0.15, 0.00);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.32, 0.22, 0.00);
    glVertex3f(0.46, 0.22, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.32, 0.19, 0.00);
    glVertex3f(0.46, 0.19, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.32, 0.16, 0.00);
    glVertex3f(0.46, 0.16, 0.00);
    glEnd();







//Boat

    glPushMatrix();
    glTranslatef(xPos, 0.0f, 0.0f);


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.65, 0.10, 0.00);
    glVertex3f(0.80, 0.10, 0.00);
    glVertex3f(0.78, 0.04, 0.00);
    glVertex3f(0.67, 0.04, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.67, 0.12, 0.00);
    glVertex3f(0.78, 0.12, 0.00);
    glVertex3f(0.78, 0.10, 0.00);
    glVertex3f(0.67, 0.10, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.60, 1.60, 0.60);
    glVertex3f(0.68, 0.14, 0.00);
    glVertex3f(0.77, 0.14, 0.00);
    glVertex3f(0.77, 0.12, 0.00);
    glVertex3f(0.68, 0.12, 0.00);
    glEnd();

//boat er piller

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.69, 0.17, 0.00);
    glVertex3f(0.71, 0.17, 0.00);
    glVertex3f(0.71, 0.14, 0.00);
    glVertex3f(0.69, 0.14, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.74, 0.17, 0.00);
    glVertex3f(0.76, 0.17, 0.00);
    glVertex3f(0.76, 0.14, 0.00);
    glVertex3f(0.74, 0.14, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.69, 0.17, 0.00);
    glVertex3f(0.71, 0.17, 0.00);
    glVertex3f(0.71, 0.16, 0.00);
    glVertex3f(0.69, 0.16, 0.00);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.74, 0.17, 0.00);
    glVertex3f(0.76, 0.17, 0.00);
    glVertex3f(0.76, 0.16, 0.00);
    glVertex3f(0.74, 0.16, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(0.71, 0.16, 0.00);
    glVertex3f(0.74, 0.16, 0.00);
    glEnd();

    glPopMatrix();




//2nd boat

    glBegin(GL_QUADS);
    glColor3f(0.20, 0.20, 0.20);
    glVertex3f(0.65, 0.45, 0.00);
    glVertex3f(0.70, 0.45, 0.00);
    glVertex3f(0.70, 0.42, 0.00);
    glVertex3f(0.65, 0.42, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.20, 0.20, 0.20);
    glVertex3f(0.70, 0.45, 0.00);
    glVertex3f(0.72, 0.46, 0.00);
    glVertex3f(0.70, 0.42, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.20, 0.20, 0.20);
    glVertex3f(0.63, 0.46, 0.00);
    glVertex3f(0.65, 0.45, 0.00);
    glVertex3f(0.65, 0.42, 0.00);
    glEnd();

//dori badha

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.60, 0.52, 0.00);
    glVertex3f(0.61, 0.52, 0.00);
    glVertex3f(0.61, 0.50, 0.00);
    glVertex3f(0.60, 0.50, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.80, 0.0, 0.0);
    glVertex3f(0.61, 0.50, 0.00);
    glVertex3f(0.63, 0.46, 0.00);
    glEnd();

//3rd boat

    glBegin(GL_QUADS);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.55, 0.35, 0.00);
    glVertex3f(0.60, 0.35, 0.00);
    glVertex3f(0.60, 0.32, 0.00);
    glVertex3f(0.55, 0.32, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.60, 0.35, 0.00);
    glVertex3f(0.62, 0.36, 0.00);
    glVertex3f(0.60, 0.32, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.40, 0.30, 0.20);
    glVertex3f(0.53, 0.36, 0.00);
    glVertex3f(0.55, 0.35, 0.00);
    glVertex3f(0.55, 0.32, 0.00);
    glEnd();

//dori badha

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.50, 0.38, 0.00);
    glVertex3f(0.51, 0.38, 0.00);
    glVertex3f(0.51, 0.35, 0.00);
    glVertex3f(0.50, 0.35, 0.00);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.80, 0.0, 0.0);
    glVertex3f(0.51, 0.35, 0.00);
    glVertex3f(0.53, 0.36, 0.00);
    glEnd();


//pakhi-1

    glPushMatrix();
    glTranslatef(xPos, 0.0f, 0.0f);


    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.75, 0.93, 0.00);
    glVertex3f(0.76, 0.915, 0.00);
    glVertex3f(0.75, 0.90, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.75, 0.92, 0.00);
    glVertex3f(0.78, 0.92, 0.00);
    glVertex3f(0.78, 0.91, 0.00);
    glVertex3f(0.75, 0.91, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.76, 0.94, 0.00);
    glVertex3f(0.77, 0.92, 0.00);
    glVertex3f(0.76, 0.92, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.50, 0.50, 0.50);
    glVertex3f(0.78, 0.92, 0.00);
    glVertex3f(0.79, 0.905, 0.00);
    glVertex3f(0.78, 0.91, 0.00);
    glEnd();

    glPopMatrix();

//pakhi-2

    glPushMatrix();
    glTranslatef(xPos, 0.0f, 0.0f);


    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.65, 0.83, 0.00);
    glVertex3f(0.66, 0.815, 0.00);
    glVertex3f(0.65, 0.80, 0.00);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.65, 0.82, 0.00);
    glVertex3f(0.68, 0.82, 0.00);
    glVertex3f(0.68, 0.81, 0.00);
    glVertex3f(0.65, 0.81, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.66, 0.84, 0.00);
    glVertex3f(0.67, 0.82, 0.00);
    glVertex3f(0.66, 0.82, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.50, 0.50, 0.50);
    glVertex3f(0.68, 0.82, 0.00);
    glVertex3f(0.69, 0.805, 0.00);
    glVertex3f(0.68, 0.81, 0.00);
    glEnd();

    glPopMatrix();


//Bus-1

    glPushMatrix();
    glTranslatef(x2Pos, 0.0f, 0.0f);



    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.40, 0.59, 0.00);
    glVertex3f(0.40, 0.64, 0.00);
    glVertex3f(0.45, 0.64, 0.00);
    glVertex3f(0.45, 0.59, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.30, 0.30);
    glVertex3f(0.45, 0.64, 0.00);
    glVertex3f(0.47, 0.59, 0.00);
    glVertex3f(0.45, 0.59, 0.00);
    glEnd();

//Chaka

    glColor3f(0.0, 0.0, 0.0);
    makeCircle(0.01,0.41,0.59,FILL);

    glColor3f(0.0, 0.0, 0.0);
    makeCircle(0.01,0.44,0.59,FILL);

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.41, 0.59, 0.00);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.44, 0.59, 0.00);
    glEnd();


    glPopMatrix();










//Bus-2

    glPushMatrix();
    glTranslatef(x3Pos, 0.0f, 0.0f);



    glBegin(GL_QUADS);
    glColor3f(0.0, 1.50, 1.0);
    glVertex3f(0.10, 0.57, 0.00);
    glVertex3f(0.10, 0.62, 0.00);
    glVertex3f(0.15, 0.62, 0.00);
    glVertex3f(0.15, 0.57, 0.00);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.90);
    glVertex3f(0.15, 0.62, 0.00);
    glVertex3f(0.17, 0.57, 0.00);
    glVertex3f(0.15, 0.57, 0.00);
    glEnd();

//Chaka

    glColor3f(0.0, 0.0, 0.0);
    makeCircle(0.01,0.11,0.57,FILL);

    glColor3f(0.0, 0.0, 0.0);
    makeCircle(0.01,0.14,0.57,FILL);

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.11, 0.57, 0.00);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.14, 0.57, 0.00);
    glEnd();


    glPopMatrix();










    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        yPos += 0.02f;
        break;
    case 's':
        yPos -= 0.02f;
        break;
    case 'a':
        xPos -= 0.02f;
        break;
    case 'd':
        xPos += 0.02f;
        break;


        case 'm':
        a=0.20, b=0.10, c=0.70;
        break;

    case 'n':
        a=1, b=1, c=0;
        break;




    default:
        break;
    }
    glutPostRedisplay();


}

void update(int value)
{
    xPos += 0.01f;

    if (xPos > 1)
    {
        xPos = 0 - xPos;
    }

    glutPostRedisplay();
    glutTimerFunc(70, update, 0);
}

//for cloud speed
void update1(int value)
{
    x1Pos += 0.01f;

    if (x1Pos > 1)
    {
        x1Pos = 0- x1Pos;
    }

    glutPostRedisplay();
    glutTimerFunc(200, update1, 0);
}

//for bus-1 speed

void update2(int value)
{
    x2Pos += 0.01f;

    if (x2Pos > 1)
    {
        x2Pos = 0- x2Pos;
    }

    glutPostRedisplay();
    glutTimerFunc(50, update2, 0);
}



//for bus-2 speed

void update3(int value)
{
    x3Pos += 0.01f;

    if (x3Pos > 1)
    {
        x3Pos = 0- x3Pos;
    }

    glutPostRedisplay();
    glutTimerFunc(30, update3, 0);
}


//poka

void update4(int value)
{
    angle1 += 3.0f;
    if (angle1 > 360.0f)
        angle1 -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(25, update4, 0);
}






int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Moving Square");
    glClearColor(0.75f, 0.75f, 0.75f, 1.0f);  //  background  Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glutTimerFunc(70, update, 0);
    glutTimerFunc(200, update1, 0);
    glutTimerFunc(50, update2, 0);
    glutTimerFunc(30, update3, 0);
    glutTimerFunc(25, update4, 0);
    gluOrtho2D(0.0f, 1.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


