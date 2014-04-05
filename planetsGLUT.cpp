#include <GL/glut.h>
#include <cmath>

#define Pi 3.14

//Your global data structures here to record 
//	the geometric infromation of the plants and their orbits

//Global Data Structures for Planet A
static float radius = 20.0; //The radius of Planet A's orbit
static float coordinates[2] = {radius, 0.0}; //The starting x and y coordinates of Planet A
static float centerCoordinates[2] = {0.0, 0.0}; //The coordinates of the center of Planet A's orbit
static float angle = 0.0; //The starting angle of Planet A

//Global Data Structures for Planet B
static float radiusB = 40.0;
static float coordinatesB[2] = {radiusB, 0.0};
static float angleB = 0.0;

//Global Data Structures for Planet C
static float radiusC = 70.0;
static float coordinatesC[2] = {radiusC, 0.0};
static float angleC = 0.0;

//Global Data Structures for Planet D
static float radiusD = 85.0;
static float coordinatesD[2] = {radiusD, 0.0};
static float angleD = 0.0;

//Your code for the fancyCircle function here
void myFancyCircle(float a, float b, float c, float x, float y, float  z, float r, int numPoints)
{
	if (a > 1.0 || a < 0.0 || b > 1.0 || b < 0.0 || c > 1.0 || c < 0.0) //Error with the colors
	{
		return;
	}

	glColor3f(a, b, c); //Set colors

	glBegin(GL_POLYGON);
	 	for (int i=0; i < numPoints; i++) //Draw the circle
		{
			glVertex3f(x + (r*cos(i*2*Pi/numPoints)), y + (r*sin(i*2*Pi/numPoints)), z);
		}
	glEnd();
}

//Function just for drawing the orbits
void myFancyLine(float a, float b, float c, float x, float y, float  z, float r, int numPoints)
{
	if (a > 1.0 || a < 0.0 || b > 1.0 || b < 0.0 || c > 1.0 || c < 0.0)
	{
		return;
	}

	glColor3f(a, b, c);

	glBegin(GL_LINE_LOOP);
	 	for (int i=0; i < numPoints; i++)
		{
			glVertex3f(x + (r*cos(i*2*Pi/numPoints)), y + (r*sin(i*2*Pi/numPoints)), z);
		}
	glEnd();
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

   //Your code to call your fancyCircle function to display the planets
   //		based on the geometric information in the global data structures

   //Circle for the sun
   myFancyCircle(1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 10.0, 360);

   //Planet A
   myFancyCircle(1.0, 1.0, 1.0, coordinates[0], coordinates[1], 0, 2.0, 360);
   myFancyLine(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 20.0, 360); //Planet A's orbit

   //Planet B
   myFancyCircle(0.0, 0.0, 1.0, coordinatesB[0], coordinatesB[1], 0, 3.0, 360);
   myFancyLine(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 40.0, 360);

   //Planet C
   myFancyCircle(1.0, 0.0, 0.0, coordinatesC[0], coordinatesC[1], 0, 7.0, 360);
   myFancyLine(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 70.0, 360);

   //Planet D
   myFancyCircle(0.0, 1.0, 1.0, coordinatesD[0], coordinatesD[1], 0, 2.5, 360);
   myFancyLine(0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 85.0, 360);


   glutSwapBuffers();
}

void spinDisplay(void)
{
   //Your code to update the geometric information in the golbal data structures
   //		to simulate the movements of individual plantes one step fruther along
   //		their orbits

	//Change the angle
	angle = angle + (2.0*Pi/1720.0);
	if (angle >= 2.0*Pi) //Reset the angle if it reaches the beginning
	{
		angle = 0.0;
	}

	//Change the coordinates
	coordinates[0] = (radius*cos(angle));
	coordinates[1] = (radius*sin(angle));


	//Planet B
	angleB = angleB + (2.0*Pi/5000.0);
	if (angleB >= 2.0*Pi)
	{
		angleB = 0.0;
	}

	coordinatesB[0] = (radiusB*cos(angleB));
	coordinatesB[1] = (radiusB*sin(angleB));


	//Planet C
	angleC = angleC + (2.0*Pi/10000.0);
	if (angleC >= 2.0*Pi)
	{
		angleC = 0.0;
	}

	coordinatesC[0] = (radiusC*cos(angleC));
	coordinatesC[1] = (radiusC*sin(angleC));

	//Planet D
	angleD = angleD + (2.0*Pi/4000.0);
	if (angleD >= 2.0*Pi)
	{
		angleD = 0.0;
	}

	coordinatesD[0] = (radiusD*cos(angleD));
	coordinatesD[1] = (radiusD*sin(angleD));

   glutPostRedisplay();
}

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(0);
         break;
      default:
         break;
   }
}
   
/* 
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (0, 0);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}