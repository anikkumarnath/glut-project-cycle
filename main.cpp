#include <gl/glut.h>
#include <stdio.h>

void myInit()
{

    glClearColor(0.92, 0.53, 0.85, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0,0.0);
    glPointSize(5.0);
    glLineWidth(5.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, 400, -400, 400);
}

void line(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();

}
void draw_pixel_circle(int x, int y,int x1,int y1)
{
    glBegin(GL_POINTS);
    ///1st xy coordinate
    glVertex2i(x+x1, y+y1);
    glVertex2i(y+x1, x+y1);
    ///2nd -xy coordinate
    glVertex2i(-x+x1, y+y1);
    glVertex2i(-y+x1, x+y1);
    ///3rd -x-y coordinate
    glVertex2i(-x+x1, -y+y1);
    glVertex2i(-y+x1, -x+y1);
    ///4th x-y coordinate
    glVertex2i(x+x1,-y+y1);
    glVertex2i(y+x1, -x+y1);
    glEnd();
}

void circle(int r,int x1,int y1)
{

    int x,y,d;
    d=1-r;
    x=0;
    y=r;
    draw_pixel_circle(x,y,x1,y1);
    while(x<=y)
    {
        if(d<0)
        {
            d=d+2*x+3;
            x=x+1;

        }
        else
        {
            d=d+2*(x-y)+5;
            x=x+1;
            y=y-1;
        }
        draw_pixel_circle(x,y,x1,y1);
    }

}
void myDisplay()
{
    glRasterPos2f(-100, 300); /// text position
    char a[100] = "Cycle Drawing";
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[i]);
    }

    circle(75,249-400,400-479); /// 1st wheel
    circle(70,561-400,400-462); /// 2nd wheel
    circle(30,431-400,400-433); /// chain wheel
    line(249-400,400-479,301-400,400-316); /// front frame
    line(435-400,400-433,290-400,400-345); ///bottom frame
    line(435-400,400-433,543-400,400-327); ///middle frame
    line(306-400,400-317,531-400,400-340); ///upper frame
    line(531-400,400-340,564-400,400-459); ///rear frame
    line(262-400,400-300,302-400,400-262); ///handlebars
    line(388-400,400-447,486-400,400-411); ///pedal
    line(433-400,400-433,563-400,400-455); ///rear bottom frame
    line(302-400,400-315,286-400,400-277); ///handlebar
    line(500-400,400-327,567-400,400-329); ///seat
    line(500-400,400-313,567-400,400-315); ///seat
    line(500-400,400-327,500-400,400-313);  ///seat
    line(567-400,400-329,567-400,400-315); ///seat

    glFlush();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cycle Figure Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
