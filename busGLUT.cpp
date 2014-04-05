#include <GL/glut.h>
 
//Static variables for the current positions
static float angle = 0;

void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 
 glMatrixMode(GL_MODELVIEW);
 
 glLoadIdentity();
 
 gluLookAt( 0,5,1,
                  0, 0, -4,
                  0,1,0);

 
 //***************************************************
 // to generate bus body
 //***************************************************
 glPushMatrix();
 
 glColor3f(1,1,0);

 glTranslatef(0, 0, -4);

 glRotatef(angle, 0, 1, 0);
 
 glTranslatef(0, 0.5, -2);
 
 glScalef(2,1,1);
 
 glutWireCube(1);
 
 glPopMatrix();
 
 
 //***************************************************
 // to generate back right wheel
 //***************************************************
 glPushMatrix();
 
 glColor3f(0, 0, 0);

 glTranslatef(0, 0, -4);

 glRotatef(angle, 0, 1, 0);
 
 glTranslatef(-0.55, 0, -1.5);
 
 glutWireTorus(0.1, 0.2, 10, 10);
 
 glPopMatrix();
 
 glFlush();

  //***************************************************
 // to generate back left wheel
 //***************************************************
 glPushMatrix();
 
 glColor3f(0, 0, 0);

 glTranslatef(0, 0, -4);

 glRotatef(angle, 0, 1, 0);
 
 glTranslatef(-0.55, 0, -2.5);
 
 glutWireTorus(0.1, 0.2, 10, 10);
 
 glPopMatrix();
 
 glFlush();

  //***************************************************
 // to generate front right wheel
 //***************************************************
 glPushMatrix();
 
 glColor3f(0, 0, 0);

 glTranslatef(0, 0, -4);

 glRotatef(angle, 0, 1, 0);
 
 glTranslatef(0.55, 0, -1.5);
 
 glutWireTorus(0.1, 0.2, 10, 10);
 
 glPopMatrix();
 
 glFlush();

  //***************************************************
 // to generate front left wheel
 //***************************************************
 glPushMatrix();
 
 glColor3f(0, 0, 0);

 glTranslatef(0, 0, -4);

 glRotatef(angle, 0, 1, 0);
 
 glTranslatef(0.55, 0, -2.5);
 
 glutWireTorus(0.1, 0.2, 10, 10);
 
 glPopMatrix();
 
 glFlush();

 glutSwapBuffers();
 
}

//************End of display function *****************
 
void reshape(int w, int h)
{
 float left = -5;
 float right = 5;
 float bottom = -5;
 float top = 5;
 float near = 0.1;
 float far = 15;
 
 glViewport(0, 0, w, h);           
 
 glMatrixMode(GL_PROJECTION);
 
 glLoadIdentity();                       
 
 if (w >= h)
     glOrtho( left * ( float(w)/ float(h)), right * ( float(w)/ float(h)),
              bottom, top,
              near, far
            );
 else
     glOrtho(  left , right ,
               bottom*( float(h)/ float(w)), top* ( float(h)/ float(w)),
               near, far
            );
 
 glMatrixMode(GL_MODELVIEW);
}
//**************  End of reshape function ****************
 

void drive(void)
{
	if (angle<360)
	{
		angle = angle + 0.1;
	}
	else
	{
		angle = 0;
	}

	glutPostRedisplay();
}


 
void main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Bus");
 glutReshapeFunc(reshape);
 glutDisplayFunc(display);
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glutIdleFunc(drive);
 
 glutMainLoop();
}
 
 
 
 