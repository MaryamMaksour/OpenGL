#include <bits/stdc++.h>
using namespace std;
#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>


int WIDTH = 600, HEIGHT = 600;
int c=0,k=10;
bool cheack();
char ok[9]= {'0','0','0','0','0','0','0','0','0'};
void draw_border()
{
    glLineWidth(5.0f);
    glColor3f(0.0,1.0,1.0);
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

    glBegin(GL_LINES);
    glVertex3f(-90,31,0.0);
    glVertex3f(90,31,0.0);

    glVertex3f(-90,-31,0.0);
    glVertex3f(90,-31,0.0);

    glVertex3f(31,90,0.0);
    glVertex3f(31,-90,0.0);

    glVertex3f(-31,90,0.0);
    glVertex3f(-31,-90,0.0);
    glEnd();

}

void draw_O()
{
    if(k>9)
        return;

    ok[k-1]='O';

    int m,p;
    if(k>0 && k<4)
        m=-1;
    else if(k>3 && k<7)
        m=0;
    else
        m=1;

    if(k%3==2)
        p=0;
    else if(k%3==1)
        p=-2;
    else
        p=2;


    glColor3f(1.0,0.0,0.0);

    GLint i;
    GLfloat cosine,sine,PI=3.14;
    glBegin(GL_LINE_LOOP);
    for(i = 0 ; i<100; i++)
    {
        cosine = cos(i*2*PI/100.0);
        sine = sin(i*2*PI/100.0);
        glVertex2f(cosine*15+(31*p),sine*15+(-62*m));
    }
    glEnd();


}

void draw_X()
{
    if(k>9)
        return;
    ok[k-1]='x';
    int m,p=k;
    if(k>0 && k<4)
        m=0;
    else if(k>3 && k<7)
        m=1;
    else
        m=2;
    p--;
    p=(p%3);


    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);

    glVertex3f(-85+(62*p),85+(-62*m),0.0);
    glVertex3f(-38+(62*p),38+(-62*m),0.0);

    glVertex3f(-38+(62*p),85+(-62*m),0.0);
    glVertex3f(-85+(62*p),38+(-62*m),0.0);

    glEnd();

}

void draw()
{

    if(c==10 )
    {
        exit(0);
    }

    if(c%2==0)
    {
        if(ok[k-1]!='x')
        {
            draw_O();

        }
        else
            c--;


    }
    else
    {
        if(ok[k-1]!='O')
        {
            draw_X();
        }
        else
            c--;
    }
  if(cheack()){
      cheack();



}
bool cheack()
{

    if(ok[0]==ok[3] && ok[3]==ok[6] && ok[0]!='0')
    {
            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(-60,80,0.0);
            glVertex3f(-60,-80,0.0);
            glEnd();
             glutPostRedisplay();
            return true;
    }
    if(ok[1]==ok[4] && ok[4]==ok[7] && ok[7]!='0')
    {
            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(0,80,0.0);
            glVertex3f(0,-80,0.0);
            glEnd();
            glutPostRedisplay();
            return true;


    }
    if(ok[2]==ok[5] && ok[5]==ok[8] && ok[8]!='0')
    {

            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(60,80,0.0);
            glVertex3f(60,-80,0.0);
            glEnd();
            glutPostRedisplay();
            return true;
    }
    if(ok[0]==ok[1] && ok[0]==ok[2] && ok[0]!='0')
    {
            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(-80,60,0.0);
            glVertex3f(80,60,0.0);
            glEnd();
            glutPostRedisplay();
            return true;
    }
    if(ok[3]==ok[4] && ok[4]==ok[5] && ok[4]!='0')
    {


            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(-80,0,0.0);
            glVertex3f(80,0,0.0);
            glEnd();
            glutPostRedisplay();
            return true;
    }
    if(ok[8]==ok[7] && ok[7]==ok[6] && ok[6]!='0')
    {


            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(-80,-60,0.0);
            glVertex3f(80,-60,0.0);
            glEnd();
            glutPostRedisplay();
            return true;
    }
    if(ok[0]==ok[4] && ok[4]==ok[8] && ok[0]!='0')
    {


            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(-70,70,0.0);
            glVertex3f(70,-70,0.0);
            glEnd();
            glutPostRedisplay();
            return true;
    }
    if(ok[2]==ok[4] && ok[4]==ok[6] && ok[6]!='0')
    {


            glLineWidth(20.0f);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINES);
            glVertex3f(70,70,0.0);
            glVertex3f(-70,-70,0.0);
            glEnd();
            glutPostRedisplay();
            return true;
    }
    //  glutPostRedisplay();
    return false;

}
void display()
{

    draw_border();
    draw();
    glutPostRedisplay();
    glutSwapBuffers();


}

void key_fun(unsigned char key,int x,int y)
{
    c++;
    switch(key)
    {
    case '1':
        k=1;
        glutPostRedisplay();
        break;

    case '2':
        k=2;
        glutPostRedisplay();
        break;

    case '3':
        k=3;
        glutPostRedisplay();
        break;

    case '4':
        k=4;
        glutPostRedisplay();
        break;

    case '5':
        k=5;
        glutPostRedisplay();
        break;

    case '6':
        k=6;
        glutPostRedisplay();
        break;

    case '7':
        k=7;
        glutPostRedisplay();
        break;

    case '8':
        k=8;
        glutPostRedisplay();
        break;

    case '9':
        k=9;
        glutPostRedisplay();
        break;
    }

    if(cheack()==true)
        exit(0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (WIDTH,HEIGHT);
    glutInitWindowPosition (10, 10);
    glutCreateWindow ("X/O");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); /* clear the matrix */
    glOrtho(-100.0,100.0, -100.0, 100.0, -50.0, 50.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(key_fun);

    glutMainLoop();
}
