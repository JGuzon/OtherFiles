#include <cstdlib>

#include <GL/glut.h>

#include <cmath>
#include <iostream>

#define Pi 3.14

using namespace std;
 

GLUquadricObj *obj;

//Static variables for the current positions
static float angle = 0;



//*****************************************************************
// Begin: Global variables about the camera location and orientation
//*****************************************************************

//Camera on y = 0 plan, circling around (0,0,0)
//The following variable records the current angle between the vector (1,0,0) and (eyex, eyey, eyez)
double C_angle;

const double PI = 3.14156;

//Camera on y = 0 plan, circling around (0,0,0)
//The following variable records the radius of the camera's orbit
double C_Radius;

//Camera on y = 0 plan, circling around (0,0,0)
//The following variable records the rotation speed of the camera
double C_increment;

//Camera on y = 0 plan, circling around (0,0,0)
//Recording the currnet position of the camera.
double eyex, eyey, eyez; 

//New boolean variables by Jason for knowing which axis we are rotating around
bool xRotate, yRotate, zRotate; 

//Camera on y = 0 plan, circling around (0,0,0)
//Specifies the position of the point looked at
double centerx, centery, centerz; 
	

//Specifies the direction of the up vector. 
double upx, upy, upz;


//*****************************************************************
// End of Global variables about the camera location and orientation
//*****************************************************************





void display()
{

 glMatrixMode (GL_MODELVIEW);
 glLoadIdentity ();
 gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
 glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



   GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[4] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };
   GLfloat low_shininess[] = { 5.0 };
   GLfloat high_shininess[] = { 100.0 };
   GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

 
 //***************************************************
 // to generate floor 
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.0;
   mat_diffuse[1] = 0.5;
   mat_diffuse[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   

 glRotatef(-90,1,0,0);

 gluDisk(obj, 0, 5, 10, 10);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate tallest pillar
 //***************************************************
 glPushMatrix();

   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.5;
   mat_diffuse[1] = 0.0;
   mat_diffuse[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(1,4,0);

 glRotatef(35,0,0,1);
 
 glScalef(0.5,10,0.5);
 
 glutSolidCube(1);
 
 glPopMatrix();

 glFlush();

 //***************************************************
 // to generate medium pillar
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.5;
   mat_diffuse[1] = 0.0;
   mat_diffuse[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(-0.5,3,-1.35);

 glRotatef(23,1,0,0);
 
 glScalef(0.5,7,0.5);
 
 glutSolidCube(1);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate small pillar
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.5;
   mat_diffuse[1] = 0.0;
   mat_diffuse[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(-0.5,2,0.5);

 glRotatef(-35,1,0,0);
 
 glScalef(0.5,5,0.5);
 
 glutSolidCube(1);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate bell #1 (biggest)
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.0;
   mat_diffuse[1] = 0.7;
   mat_diffuse[2] = 0.7;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(-0.5,2,-0.8);

 glRotatef(-90,1,0,0);

 glScalef(0.7,0.7,0.7);
 
 glutSolidCone(1.0, 2.0, 10, 10);
 
 glPopMatrix();

 glFlush();

 //***************************************************
 // to generate highest bell #2 (highest)
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.0;
   mat_diffuse[1] = 0.7;
   mat_diffuse[2] = 0.7;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(0,4,0);

 glRotatef(-90,1,0,0);

 glScalef(0.5,0.5,0.5);
 
 glutSolidCone(1.0, 2.0, 10, 10);
 
 glPopMatrix();

 glFlush();

 //***************************************************
 // to generate bell #3
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.0;
   mat_diffuse[1] = 0.7;
   mat_diffuse[2] = 0.7;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(0.65,3.25,0);

 glRotatef(-90,1,0,0);

 glScalef(0.4,0.4,0.4);
 
 glutSolidCone(1.0, 2.0, 10, 10);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate bell #4
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.0;
   mat_diffuse[1] = 0.7;
   mat_diffuse[2] = 0.7;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(1.3,2.5,0);

 glRotatef(-90,1,0,0);

 glScalef(0.3,0.3,0.3);
 
 glutSolidCone(1.0, 2.0, 10, 10);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate smallest bell #5 (smallest/lowest)
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.0;
   mat_diffuse[1] = 0.7;
   mat_diffuse[2] = 0.7;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(1.95,1.75,0);

 glRotatef(-90,1,0,0);

 glScalef(0.2,0.2,0.2);
 
 glutSolidCone(1.0, 2.0, 10, 10);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate foundation #1 (for tallest pillar)
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.4;
   mat_diffuse[1] = 0.0;
   mat_diffuse[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(3.5,0,0);
 
 glScalef(2,1,2);
 
 glutSolidCube(1);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate foundation #2 (for medium pillar)
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.4;
   mat_diffuse[1] = 0.0;
   mat_diffuse[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(-0.5,0,-2.5);
 
 glScalef(2,1,2);
 
 glutSolidCube(1);
 
 glPopMatrix();

 glFlush();



 //***************************************************
 // to generate foundation #3 (for smallest pillar)
 //***************************************************
 glPushMatrix();
 
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   mat_diffuse[0] = 0.4;
   mat_diffuse[1] = 0.0;
   mat_diffuse[2] = 0.0;
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

 glTranslatef(-0.5,0,1.75);
 
 glScalef(2,1,2);
 
 glutSolidCube(1);
 
 glPopMatrix();

 glFlush();


 //***************************************************
 // to generate x axis
 //***************************************************
 glPushMatrix();
 glColor3f(1,0,0); 
 glPointSize(1.0);  

 glBegin(GL_LINES);
	glVertex2d(15, 0);
	glVertex2d(-15, 0);
 glEnd();
 glPopMatrix();
 glFlush();



 //***************************************************
 // to generate y axis
 //***************************************************
 glPushMatrix();
 glColor3f(0,1,0); 
 glPointSize(1.0);  

 glBegin(GL_LINES);
	glVertex2d(0, 15);
	glVertex2d(0, -15);
 glEnd();
 glPopMatrix();
 glFlush();



 //***************************************************
 // to generate z axis
 //***************************************************
 glPushMatrix();
 glColor3f(0,0,1); 
 glPointSize(1.0);  

 glBegin(GL_LINES);
	glVertex3d(0, 0, 15);
	glVertex3d(0, 0, -15);
 glEnd();
 glPopMatrix();
 glFlush();


 glutSwapBuffers();
 
}

//************End of display function *****************
 
void reshape(int w, int h)
{
 float left = -5.2;
 float right = 5.2;
 float bottom = -5.2;
 float top = 5.2;
 float near = 0.1;
 float far = 50;

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


void spin(void)
{

	//Move Camera
   	//Camera on y = 0 plan, circling around (0,0,0)
	//The following variable records the current angle between the vector (1,0,0) and (eyex, eyey, eyez)
	C_angle += C_increment;


	if ( C_angle > 2*PI)
		C_angle -= 2*PI;
	
	if (xRotate == true)//If we rotate around the x-axis
	{
		eyex = 0;
		eyey = C_Radius * sin(C_angle);
		eyez = C_Radius * cos(C_angle);
		if (eyez < 0)//To avoid suddenly twisting the orientation
			upy = -1;
		else
			upy = 1;
	}
	else if (yRotate == true)//If we rotate around the y-axis
	{
		eyex = C_Radius * cos(C_angle);
		eyey = 10;
		eyez = C_Radius * sin(C_angle);
		upy = 1;
	}
	else if (zRotate == true)//If we rotate around the z-axis
	{
		eyex = C_Radius * cos(C_angle);
		eyey = C_Radius * sin(C_angle);
		eyez = 0;
		if (eyex < 0)//To avoid suddenly twisting the orientation
			upy = -1;
		else
			upy = 1;
	}
	else;

	glutPostRedisplay();
}

void initCameraSetting()
{

 
//The following variable records the current angle between the vector (1,0,0) and (eyex, eyey, eyez)
	C_angle = 0;

//Camera on y = 0 plan, circling around (0,0,0)
//The following variable records the radius of the camera's orbit
	C_Radius = 10;

//Camera on y = 0 plan, circling around (0,0,0)
//The following variable records the rotation speed of the camera
	C_increment = 2*PI / (360*2);

//Recording the currnet position of the camera.
	eyex = 0; eyey = 6; eyez = C_Radius;//C_Radius;

	xRotate = false; yRotate = false; zRotate = false;

//Specifies the position of the point looked at as (0,0,0).
	centerx = 0; centery = 5; centerz=0;

//Specifies the direction of the up vector. 
	upx = 0; upy=1;  upz=0;

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 gluLookAt
	 (eyex, eyey, eyez,
	 centerx, centery, centerz,
	 upx, upy, upz);

 glMatrixMode (GL_PROJECTION);
}



void mouse(int btn, int state, int x, int y)
{ 
}

void myMenuFunction(int id)
{
	
   if(id < 5) 
   {	
	   if(id == 1) //Rotate about the x-axis
	   {
		   xRotate = true;
		   yRotate = false;
		   zRotate = false;
	   }
	   else if(id == 2)//Rotate about the y-axis
	   {
		   xRotate = false;
		   yRotate = true;
		   zRotate = false;
	   }
	   else if(id == 3)//Rotate about the z-axis
	   {
		   xRotate = false;
		   yRotate = false;
		   zRotate = true;
	   }
	   else if(id == 4)//Stop rotating
	   {
		   xRotate = false;
		   yRotate = false;
		   zRotate = false;
	   }
	   else
		   exit(0);
   }
   else
	   exit(0);
}

void initLight()
{
	GLfloat light_position[] = {1.0, 2.0, 2.0, 1.0};


	glShadeModel (GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_DEPTH_TEST);
}



 
void main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutCreateWindow("BIOLA Bell Tower");
 initLight();
 glutReshapeFunc(reshape);
 glutDisplayFunc(display);


	glutMouseFunc(mouse);

	//register the menu function
    glutCreateMenu(myMenuFunction);

	//set up the menu
    glutAddMenuEntry("Rotate on X-Axis", 1);
    glutAddMenuEntry("Rotate on Y-Axis", 2);
    glutAddMenuEntry("Rotate on Z-Axis", 3);
	glutAddMenuEntry("Stop Rotation", 4);
    glutAddMenuEntry("Quit", 5);


	//Attach one button to the menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);

 glutIdleFunc(spin);

 obj = gluNewQuadric();
 gluQuadricDrawStyle(obj, GLU_FILL);

 initCameraSetting();

 
 glutMainLoop();
}
 
 
 
 