#include <gl/glut.h>

GLfloat  girax = 0, giray= 0, zoom=0;
GLfloat PosPosicional[]={-3.0, 2.0, 4.0, 1.0};
GLfloat PosDireccional[]={-1.0, 2.0, 2.0, 0.0};

//   Rotacion XY y Zoom
void mover(void) {
    glTranslated( 0, 0, zoom);
    glRotated( giray, 0.0, 1.0, 0.0);
    glRotated( girax, 1.0, 0.0, 0.0);
}

void dibuja(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING); 
    glLightfv(GL_LIGHT0,GL_POSITION,PosDireccional);
    glEnable(GL_COLOR_MATERIAL);
    glPushMatrix();
        mover();
        glColor3f(0.5,0.25,0.75);
        glPushMatrix();
		 glTranslatef(1,1,1);
		glColor3f(1.0, 1.0, 1.0); //cabeza
		 glPushMatrix();
		 	//glTranslatef(0,0,.85);
			 glScalef(1.5,1,1);
			 glutSolidSphere(1.0, 40, 40);
			glPopMatrix();
			glPushMatrix();
			 glTranslatef(0.7,0.4,0);
			 glRotatef(30,0,0,1);
			 glScalef(1.5,1.2,1);
			 glutSolidSphere(1.0, 40,40);
		 glPopMatrix();
		 glColor3f(0.0, 0.0, 0.0); //nariz
		 glPushMatrix();
		 	glTranslatef(-1.5,0,0);
			 glScalef(.25,.25,.25);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glColor3f(0.0, 0.0, 0.0); //ojo1
		 glPushMatrix();
		 	glTranslatef(0.2,0.5,0.8);
		 	glRotatef(-30,0,0,1);
			 glScalef(.1,.2,.2);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glColor3f(0.0, 0.0, 0.0); //ojo2
		 glPushMatrix();
		 	glTranslatef(0.2,0.5,-0.8);
		 	glRotatef(-30,0,0,1);
			 glScalef(.1,.2,.2);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();	//cola
		 	glTranslatef(1.5,-3,0);
		 	glRotatef(-30,0,0,1);
			 glScalef(1.2,.1,.1);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();	//oreja1
		 	glTranslatef(1.5,-0.2,1);
			 glScalef(0.8,1.3,.05);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		  glPushMatrix();	//oreja2
		 	glTranslatef(1.5,-0.2,-1);
			 glScalef(0.8,1.3,.05);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();//ceja1
			 glTranslatef(0.5,1,0.9);
			 glRotatef(-30,0,1,1);
			 glScalef(0.2,0.1,1);
			 glLineWidth(3);
			 glBegin (GL_LINE_STRIP);
			 glVertex2f(-1, 0);
			 glVertex2f(-0.5, 0.5);
			 glVertex2f(0, 0.7);
			glVertex2f(0.5, 0.5);
			 glVertex2f(1, 0);
			 glEnd();
		 glPopMatrix();
		 glPushMatrix();//ceja2
			 glTranslatef(0.5,1,-0.9);
			 glRotatef(-30,0,1,1);
			 glScalef(0.2,0.1,1);
			 glLineWidth(3);
			 glBegin (GL_LINE_STRIP);
			 glVertex2f(-1, 0);
			 glVertex2f(-0.5, 0.5);
			 glVertex2f(0, 0.7);
			glVertex2f(0.5, 0.5);
			 glVertex2f(1, 0);
			 glEnd();
		 glPopMatrix();
		 glPushMatrix();//boca
			 glTranslatef(-0.5,-0.25,0);
			 glRotatef(-20,0,0,1);
			 glRotatef(90,0,1,0);
			 glutSolidTorus(0.05,0.7,40,40);
		 glPopMatrix();
		 glColor3f(1.0, 1.0, 1.0); //cuerpo
		 glPushMatrix();
		 	glTranslatef(0.5,-2.6,0);
			 glScalef(1,1.5,1);
			 glutSolidSphere(1.0, 40, 40); 
		 glPopMatrix();
		 glPushMatrix();//cuello
		 	glTranslatef(0.4,-1,0);
			 glScalef(0.5,0.5,0.5);
			 glutSolidSphere(1.0, 40, 40); 
		 glPopMatrix();
		 glPushMatrix();	//brazo1
		 	glTranslatef(0.7,-2.5,1);
		 	glRotatef(-20,1,0,0);
			 glScalef(0.3,0.7,.1);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();	//brazo2
		 	glTranslatef(0.7,-2.5,-1);
		 	glRotatef(20,1,0,0);
			 glScalef(0.3,0.7,.1);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();	//pie1
		 	glTranslatef(0.3,-4.8,0.5);
			 glScalef(1.2,0.5,0.5);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();	//pie2
		 	glTranslatef(0.3,-4.8,-0.5);
			 glScalef(1.2,0.5,0.5);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();	//pierna1
		 	glTranslatef(0.5,-4.2,0.4);
			 glScalef(0.35,0.35,0.35);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glPushMatrix();	//pierna2
		 	glTranslatef(0.5,-4.2,-0.4);
			 glScalef(0.35,0.35,0.35);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		  glColor3f(1.0, 0.0, 0.0);
		 glPushMatrix();	//collar
		 	glTranslatef(0.4,-1.2,0);
			 glRotatef(20,0,0,1);
			 glRotatef(90,1,0,0);
			 glutSolidTorus(0.1,0.6,40,40);
		 glPopMatrix();
	 glPopMatrix();
    glPopMatrix();
	 
	 glFlush();
    glutSwapBuffers();
}
// Funciones con Teclas
void teclado(unsigned char key, int x, int y) {
  switch(key) {
    case 27:  exit (0);
    case '+': zoom ++; break;
    case '-': zoom --; break;
    case 'p': glMatrixMode(GL_PROJECTION);
              glLoadIdentity();
              gluPerspective(45,1,10,100);
              zoom= -40;
			  break;
    case 'o': glMatrixMode(GL_PROJECTION);
              glLoadIdentity();
              glOrtho(-5,20,-15,15,-30,30);
              zoom=0;
    default: break;
  }
  glutPostRedisplay();
}
void rotar(int key, int x, int y) {
  switch(key) {
    case GLUT_KEY_LEFT: giray-= 15; break;
    case GLUT_KEY_RIGHT:giray+= 15; break;
    case GLUT_KEY_UP:   girax -= 15; break;
    case GLUT_KEY_DOWN: girax += 15; break;
  }
  glutPostRedisplay();
}
void ajusta(int ancho, int alto) {
	glClearColor(0.9,0.9,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,10,100);
    zoom= -15;
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
}
int main(int argc, char** argv) {
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInit(&argc, argv);
    glutCreateWindow("Arturo Perez de Lara");
    glutDisplayFunc(dibuja);
    glutReshapeFunc(ajusta);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(rotar);
    glutMainLoop();
    return 0;
}
