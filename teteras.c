#include <gl/glut.h>
#include <math.h>
GLfloat  zoom=0;


void dibuja(void) {
	 glClearColor(1.0,1.0,1.0,0.0);
	 glClear(GL_COLOR_BUFFER_BIT);
	 glLineWidth(2);
	 
	 //Tetera 1
	 glViewport(0,300,300,300);
	 glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-1, 1, -1, 1, 1,30);
 	glColor3f(0.7, 0.0, 1.0);
 	glPushMatrix();
 		gluLookAt(0,2,0,0,0,-3,0,1,0);
	 glPushMatrix();
	 	glTranslatef(0.0, 0.0, -3);
		 glScalef(.5,.5,.5);
	 	glutWireTeapot(1);
	 glPopMatrix();
	glPopMatrix();
	 
	 //Tetera 2
	 glViewport(0,0,300,300);
	 glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-1, 1, -1, 1, 1,30);
 	glColor3f(0.0, 0.75, 1.0);
 	glPushMatrix();
 	gluLookAt(0,10,0,0,-4,-4,0,2,0);
	 glPushMatrix();
	 	glTranslatef(0.0, 0.0, -3);
		 glScalef(.5,.5,.5);
	 	glutWireTeapot(1);
	 glPopMatrix();
	glPopMatrix();
	 
	 //Tetera 3
	 glViewport(400,300,300,300);
	 glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-1, 1, -1, 1, 1,30);
 	glColor3f(0.7, 0.5, 0.0);
 	glPushMatrix();
 		gluLookAt(1,1,3,0,0,-3,1,1,0);
	 glPushMatrix();
	 	glTranslatef(0.0, 0.0, -3);
		 glScalef(.5,.5,.5);
	 	glutWireTeapot(1);
	 glPopMatrix();
	glPopMatrix();
	 
	 //Tetera 4
	 glViewport(400,0,300,300);
	 glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	gluPerspective(45, 1, 1, 30);
 	glColor3f(0.4, 0.8, 0.0);
 	glPushMatrix();
	 glPushMatrix();
	 	glTranslatef(0.0, 0.0, -3);
	 	glRotatef(30, 1,0,0);
		glScalef(.5,.5,.5);
	 	glutWireTeapot(1);
	 glPopMatrix();
	glPopMatrix();
	 
	 glFlush();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(800,600);
 glutInitWindowPosition(100, 150);
 glutCreateWindow("Teteras");
 glutDisplayFunc(dibuja);
 glutMainLoop();
 return 0;
}
