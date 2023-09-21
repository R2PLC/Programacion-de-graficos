#include <stdlib.h>
#include <GL/glut.h>
float pinza = 0, pincita = 0;
int gira=0, gira2=0;
void dibuja(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	GLUquadricObj *qobj;
	qobj = gluNewQuadric ();
	gluQuadricDrawStyle(qobj,GLU_LINE);

	 glClear (GL_COLOR_BUFFER_BIT);
	 glPushMatrix();
	 	glRotatef(-(GLfloat)gira*2, 0.0,1,0.0);
	 	glRotatef(-(GLfloat)gira2*2, 1,0.0,0.0);
		glTranslatef((GLfloat)pinza, 0.0, 0.0);
		glPushMatrix();
			glColor3f(0.1,0.1,0.6);
				glTranslatef(0, 5, 0.0);
				glRotatef((GLfloat)pincita*1.5, -1, 0, 0);
				glBegin(GL_POLYGON); //CARA ARRIBA
					glVertex3f (-1.5,2.6,0);
					glVertex3f (0,5.2,0);
					glVertex3f (3,5.2,0);
					glVertex3f (4.5,2.6,0);
					glVertex3f (3,0,0);
					glVertex3f (0,0,0);
				glEnd();	
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(0.1,0.5,0.6);
			glRotatef((GLfloat)pincita*1.5, 1, 0, 0);
			glTranslatef(0, -5.2, 0.0);
				glBegin(GL_POLYGON); //CARA ABAJO
					glVertex3f (-1.5,2.6,0);
					glVertex3f (0,5.2,0);
					glVertex3f (3,5.2,0);
					glVertex3f (4.5,2.6,0);
					glVertex3f (3,0,0);
					glVertex3f (0,0,0);
				glEnd();	
		glPopMatrix();
		
		glPushMatrix();	
			glColor3f(0.1,0.2,0.9);
				glBegin(GL_QUADS);
					glVertex3f (0,0,0);
					glVertex3f (0,5,0);
					glVertex3f (3,5,0);
					glVertex3f (3,0,0);
				glEnd();
			glColor3f(0.1,0.0,0.5);
			glTranslatef(3, 0, 0.0);
			glRotatef((GLfloat)pincita, 0, 1, 0);
				glBegin(GL_QUADS);
					glVertex3f (0,0,0);
					glVertex3f (0,5,0);
					glVertex3f (3,5,0);
					glVertex3f (3,0,0);
				glEnd();
			glColor3f(0.1,0.0,0.9);
			glTranslatef(3, 0, 0.0);
			glRotatef((GLfloat)pincita, 0, 1, 0);
				glBegin(GL_QUADS);
					glVertex3f (0,0,0);
					glVertex3f (0,5,0);
					glVertex3f (3,5,0);
					glVertex3f (3,0,0);
				glEnd();
			glColor3f(0.1,0.5,0.9);
			glTranslatef(3, 0, 0.0);
			glRotatef((GLfloat)pincita, 0, 1, 0);
				glBegin(GL_QUADS);
					glVertex3f (0,0,0);
					glVertex3f (0,5,0);
					glVertex3f (3,5,0);
					glVertex3f (3,0,0);
				glEnd();
				glColor3f(0.1,0.5,0.7);
			glTranslatef(3, 0, 0.0);
			glRotatef((GLfloat)pincita, 0, 1, 0);
				glBegin(GL_QUADS);
					glVertex3f (0,0,0);
					glVertex3f (0,5,0);
					glVertex3f (3,5,0);
					glVertex3f (3,0,0);
				glEnd();
			glColor3f(0.1,0.2,0.9);
			glTranslatef(3, 0, 0.0);
			glRotatef((GLfloat)pincita, 0,1, 0);
				glBegin(GL_QUADS);
					glVertex3f (0,0,0);
					glVertex3f (0,5,0);
					glVertex3f (3,5,0);
					glVertex3f (3,0,0);
				glEnd();
		glPopMatrix();
		
		
		
	glPopMatrix();
	glutSwapBuffers();
}

void tiempo(int x){
	if(x==0){
		if (pincita >= 60) {
			pincita = 60;
		}else {
			pincita += 1;
 			glutPostRedisplay();
			glutTimerFunc(50,tiempo,0);
		}
	}else if (x==1){
		if (pincita <= 0) {
			pincita = 0;
		}else {
			pincita -= 5;
 			glutPostRedisplay();
			glutTimerFunc(50,tiempo,1);
		}	
	}
	 
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
	 	if (pincita >= 90) pincita = 90;
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
	case 'R': 
	 	gira2 = (gira2 + 1);
	 	break;
	case 'r': 
	 	gira2 = (gira2 - 1);
	 	break;
	 }
	 glutPostRedisplay();
}
int clic =0;
void raton(int boton, int estado, int x, int y){
	if(boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && clic ==0)    {
		clic=1;
		glutTimerFunc(500,tiempo,0);
	}else if(boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN && clic == 1)    {
		clic=0;
		glutTimerFunc(500,tiempo,1);
	}
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
	 glOrtho(-20,20,-20,20,-20,20);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
	
}
int main(int argc, char** argv)
{
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	 glutInitWindowSize(500, 500);
	 glutInitWindowPosition(100, 100);
	 glutCreateWindow("Prisma");
	 glutDisplayFunc(dibuja);
	 glutReshapeFunc(ajusta);
	 glutKeyboardFunc(teclado);
	 glutSpecialFunc(right_left);
	 glutMouseFunc(raton);
	 glutMainLoop();
	 return 0;
}
