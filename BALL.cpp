#include <bits/stdc++.h>
using namespace std;
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>


int WIDTH = 800, HEIGHT = 800,
    BALL_WIDTH = 5,s=1;
float ball_pos[5][2],  ball_vel[5][2];

float  pad_height=5,pad_width = 40,
       paddle1_pos[2] = {-20,-89},vel =0;
float brick_WIDTH=35,brick_HEIGHT = 9,
      brick[22];

void init()
{
    for(int i=0;i<5;i++)
    {
        ball_vel[i][0]=0.04;
        ball_vel[i][1]=-0.04;
    }
      ball_pos[0][0]=30;
      ball_pos[0][1]=23;

      ball_pos[1][0]=(rand()%(80+80+1)-80);
      ball_pos[1][1]=(rand()%(80-0+1)+0);

      ball_pos[2][0]=(rand()%(80+80+1)-80);
      ball_pos[2][1]=(rand()%(80-0+1)+0);


      ball_pos[3][0]=(rand()%(80+80+1)-80);
      ball_pos[3][1]=(rand()%(80-0+1)+0);


      ball_pos[4][0]=(rand()%(80+80+1)-80);
      ball_pos[4][1]=(rand()%(80-0+1)+0);

}
void draw_border()
{
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
    glVertex3f(-95.0,95.0,0.0);
    glVertex3f(-95,-95,0.0);
    glVertex3f(-95,-95,0.0);
    glVertex3f(95,-95,0.0);
    glVertex3f(95,-95,0.0);
    glVertex3f(95,95,0.0);
    glVertex3f(95,95,0.0);
    glVertex3f(-95.0,95.0,0.0);
    glEnd();
}


void draw_paddle1()
{
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(paddle1_pos[0]+vel,paddle1_pos[1],0.0);
    glVertex3f(paddle1_pos[0]+vel,paddle1_pos[1]-pad_height,0.0);
    glVertex3f(paddle1_pos[0]+pad_width+vel,paddle1_pos[1]-pad_height,0.0);
    glVertex3f(paddle1_pos[0]+vel+pad_width,paddle1_pos[1],0.0);
    glEnd();
}


void draw_ball()
{
for(int i=0;i<s;i++){

    ball_pos[i][0] += ball_vel[i][0];
    ball_pos[i][1] += ball_vel[i][1];

    if(ball_pos[i][0]-BALL_WIDTH<=-95 || ball_pos[i][0]+BALL_WIDTH>=95)
    {
        ball_vel[i][0]=-1*ball_vel[i][0];

    }

    if(ball_pos[i][1]+BALL_WIDTH>=95 )
    {
        ball_vel[i][1]=-1*ball_vel[i][1];

    }

    if(  ball_pos[i][1]-BALL_WIDTH <= -95 )
    {

        if( (ball_pos[i][0]+ BALL_WIDTH  ) >= (paddle1_pos[0]+vel ) )
        {

            if((ball_pos[i][0] - BALL_WIDTH ) <= (paddle1_pos[0] + pad_width+vel)){
                ball_vel[i][1] = -ball_vel[i][1];
               if(s==5)continue;
                    s++;
            }
            else
            {
                exit(0);
            }

        }
        else
            exit(0);

       ball_vel[i][0]+=float(ball_vel[i][0]/100);
        ball_vel[i][1]+=float(ball_vel[i][1]/100);

    }
    if(i==1)glColor3f(0.0,0.4,0.0);
    else if(i==2)glColor3f(0.5,0.7,0.0);
    else if(i==3)glColor3f(0.0,0.0,0.3);
    else if(i==4)glColor3f(0.3,0.3,0.2);
    else glColor3f(0.3,0.5,0.6);

    glBegin(GL_QUADS);
    glVertex2f(ball_pos[i][0], ball_pos[i][1]);
    glVertex2f(ball_pos[i][0]+BALL_WIDTH, ball_pos[i][1]);
    glVertex2f(ball_pos[i][0]+BALL_WIDTH, ball_pos[i][1]+BALL_WIDTH);
    glVertex2f(ball_pos[i][0], ball_pos[i][1]+BALL_WIDTH);
    glEnd();
}
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    draw_border();
    draw_paddle1();
    draw_ball();

    glutPostRedisplay();
    glutSwapBuffers();
}

void key_fun(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:

        vel-=5;
        if(paddle1_pos[0]+vel<-95)
            vel = -1*(95+ paddle1_pos[0]);
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        vel+=5;
        if(paddle1_pos[0] + vel+pad_width>95)
            vel=95-paddle1_pos[0]-pad_width;
        glutPostRedisplay();
        break;

    }

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (WIDTH,HEIGHT);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("BALL");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); /* clear the matrix */
    glOrtho(-100.0,100.0, -100.0, 100.0, -50.0, 50.0);
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(key_fun);
    glutMainLoop();
}
