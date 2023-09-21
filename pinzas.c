#include <stdlib.h>
#include <GL/glut.h>
float pinza = 0, pincita = 0;
int gira=0;
void dibuja(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	GLUquadricObj *qobj;
	qobj = gluNewQuadric ();
	gluQuadricDrawStyle(qobj,GLU_LINE);

	 glClear (GL_COLOR_BUFFER_BIT);
	 glPushMatrix();
	 	glRotatef(-(GLfloat)gira*2, 0.0,1,0.0);
		glTranslatef((GLfloat)pinza, 0.0, 0.0);
		glPushMatrix();
			glColor3f(0.9,0.1,0.2);
				glTranslatef(0.0, 12, 0.0);
				glRotatef(90, 1, 0.0, 0.0);
				gluCylinder(qobj, 0.5, 0.5, 12, 500, 500);
		glPopMatrix();
		glPushMatrix();
			//glRotatef((GLfloat)pincita, 1, 0.0,0.0);
			
			glPushMatrix();
				glRotatef(-(GLfloat)pincita * 2, 0.0, 0.0, 1.0);
				glColor3f(0.6,0.6,0.6);
					glTranslatef(-0.2, -1.5, 0.0);
					glScalef(0.25, 3, 0.7);
					glutSolidCube(1.0);
			glPopMatrix();
			
			glPushMatrix();
				glRotatef(-(GLfloat)pincita * -2, 0.0, 0.0, 1.0);
				glColor3f(0.6,0.6,0.8);
					glTranslatef(0.2, -1.5, 0.0);
					glScalef(0.25, 3, 0.7);
					glutSolidCube(1.0);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void teclado (unsigned char key, int x, int y)
{
	 switch (key) {
	 case 27: exit(0);
	 case GLUT_KEY_LEFT: 
	 	pinza = (pinza + 0.05);
	 	break;
	 case GLUT_KEY_RIGHT: 
	 	pinza = (pinza - 0.05);
	 	break;
	 case 'A': 
	 	if (pincita >= 20) pincita = 20;
 		else pincita += 5;
	 	break;
	 case 'a': 
	 	if (pincita <= 0) pincita = 0;
 		else pincita -= 5;
	 	break;
	 case 'G': 
	 	gira = (gira + 1);
	 	break;
	 case 'g': 
	 	gira = (gira - 1);
	 	break;
	 }
	 glutPostRedisplay();
}

void right_left (unsigned char key, int x, int y)
{
	 switch (key) {
	 case 27: exit(0);
	 case GLUT_KEY_RIGHT: 
	 	pinza = (pinza + 0.05);
	 	break;
	 case GLUT_KEY_LEFT: 
	 	pinza = (pinza - 0.05);
	 	break;
	}
	 glutPostRedisplay();
}
void ajusta(int ancho, int alto)
{
	glEnable(GL_DEPTH_TEST);
	 glClearColor(1,1,1,0.);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 glOrtho(-10,10,-10,10,-10,10);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
	
}
int main(int argc, char** argv)
{
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	 glutInitWindowSize(500, 500);
	 glutInitWindowPosition(100, 100);
	 glutCreateWindow("Pinza");
	 glutDisplayFunc(dibuja);
	 glutReshapeFunc(ajusta);
	 glutKeyboardFunc(teclado);
	 glutSpecialFunc(right_left);
	 glutMainLoop();
	 return 0;
}
