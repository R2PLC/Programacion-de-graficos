#include <gl/glut.h>

GLUquadricObj *cilindro;
GLfloat  girax = 0, giray= 0, zoom=0;
GLboolean malla = GL_FALSE, ejes = GL_TRUE;
GLubyte colores[4][3]={{255,0,0},{255,255,0},{0,255,0},{200,200,200}};
int t1=3, t2=3, t3=2;
GLfloat PosPosicional[]={0.0, 2.0, 3.0, 1.0};
GLfloat PosDireccional[]={3.0, 3.0, 3.0, 0.0};

//   Rotacion XY y Zoom
void mover(void) {
    glTranslated( 0, 0, zoom);
    glRotated( giray, 0.0, 1.0, 0.0);
    glRotated( girax, 1.0, 0.0, 0.0);
}
//  Malla y Ejes
void creaMalla(int long_eje) {
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    int i;
      for(i= -long_eje; i<=long_eje; i++) {
          glVertex3f (i,0,-long_eje);
          glVertex3f (i,0,long_eje);
          glVertex3f (-long_eje,0,i);
          glVertex3f (long_eje,0,i);
      }
    glEnd();
}
void creaEjes(void) {
    glColor3f(0.0,0.0,0.0);
    glBegin( GL_LINES );
        glVertex3f (0.0,0.0,0.0); glVertex3f (11.0,0.0,0.0);
        glVertex3f (0.0,0.0,0.0); glVertex3f (0.0,11.0,0.0);
        glVertex3f (0.0,0.0,0.0); glVertex3f (0.0,0.0,11.0);
    glEnd();
    glBegin( GL_TRIANGLES );
        glVertex3f (11.0,0.0,0.0); /* eje x */
        glVertex3f (10.5,0.0,-.50);
        glVertex3f (10.5,0.0,.50);
        glColor3f(0.25,1,0.25);  	/* eje y */
        glVertex3f (0.0,11.0,0.0);
        glVertex3f (-.50,10.5,0.0);
        glVertex3f (.50,10.5,0.0);
        glColor3f(0.25,0.25,1.0);  	/* eje z */
        glVertex3f (0.0,0.0,11.0);
        glVertex3f (-.50,0.0,10.5);
        glVertex3f (.50,0.0,10.5);
    glEnd();
}

void tiempo(int x){
	x++;
	if(t1==0){
		t1=3;
		t2=3;
		t3=2;
		glutPostRedisplay();
	 	glutTimerFunc(10000,tiempo,x);
	}else if(t2==1){
		t1=0;
		t2=3;
		t3=3;
		glutPostRedisplay();
	 	glutTimerFunc(5000,tiempo,x);
	}else if(t3==2){
		t1=3;
		t2=1;
		t3=3;
		glutPostRedisplay();
		glutTimerFunc(2000,tiempo,x);
	}
	 
}

void dibuja(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING); 
    glLightfv(GL_LIGHT0,GL_POSITION,PosPosicional);
	glLightfv(GL_LIGHT1,GL_POSITION,PosDireccional);
    glEnable(GL_COLOR_MATERIAL);
    glPushMatrix();
        mover();
        if (malla) creaMalla(10);
        glColor3f(0.5,0.25,0.75);
        glPushMatrix();
		 glTranslatef(1,1,1);
		glColor3f(1.0, 0.8, 0.0); //cubo
		 glPushMatrix();
		 	glTranslatef(0,0,.85);
			 glScalef(1,2,1);
			 glutSolidCube(1);
		 glPopMatrix();
		 glColor3ubv(colores[t1]); // circulos
		 glPushMatrix();
		 	glTranslatef(0,.6,1.2);
			 glScalef(.25,.25,.25);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glColor3ubv(colores[t2]); 
		 glPushMatrix();
		 	glTranslatef(0,0,1.2);
			 glScalef(.25,.25,.25);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
		 glColor3ubv(colores[t3]);
		 glPushMatrix();
		 	glTranslatef(0,-0.6,1.2);
			 glScalef(.25,.25,.25);
			 glutSolidSphere(1.0,40,40);
		 glPopMatrix();
	 glPopMatrix();
        if (ejes) creaEjes();
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
    case 'm': malla = !malla; break;
    case 'e': ejes = !ejes;  break;
    case 'p': glMatrixMode(GL_PROJECTION);
              glLoadIdentity();
              gluPerspective(45,1,10,100);
              zoom= -40;
			  break;
    case 'o': glMatrixMode(GL_PROJECTION);
              glLoadIdentity();
              glOrtho(-15,15,-15,15,-30,30);
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
	glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
}
int main(int argc, char** argv) {
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInit(&argc, argv);
    glutCreateWindow("Semaforo");
    glutDisplayFunc(dibuja);
    glutReshapeFunc(ajusta);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(rotar);
    glutTimerFunc(1000,tiempo,0);
    glutMainLoop();
    return 0;
}
