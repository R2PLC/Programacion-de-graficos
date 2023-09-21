#include <gl/glut.h>
#include <math.h>

GLfloat  girax = 0, giray= 0, zoom=0;
GLboolean malla = GL_FALSE, ejes = GL_TRUE;

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
    float i, z, xx=-10, yy=0, zz=-10;
    float y;
      glColor3f(0.0,1.0,0.58);
      for(i= -10; i<=10; i+=0.3) {
      	for(z= -10; z<=10; z+=0.3) {
		  		y = 12*(sin(sqrt(i*i+z*z))/sqrt(i*i+z*z));
          		glVertex3f (xx,yy,zz);
          		glVertex3f (i,y,z);
          		glVertex3f (zz,yy,xx);
          		glVertex3f (z,y,i);
          		xx=i;
          		zz=z;
          		yy=y;
		  }
      	
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


void dibuja(void) {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
	    mover();
	    creaMalla(10);
		if (ejes) creaEjes();
 	glPopMatrix();

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
}
int main(int argc, char** argv) {
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInit(&argc, argv);
    glutCreateWindow("Sombrerito");
    glutKeyboardFunc(teclado);
    glutDisplayFunc(dibuja);
    glutReshapeFunc(ajusta);
    
    glutSpecialFunc(rotar);
    glutMainLoop();
    return 0;
}
