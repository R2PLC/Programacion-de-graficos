#include <GL/glut.h>
//Propiedades luz
float luz_ambiente [] = {0.5,0.7,0,0};
float luz_difusa [] = {1,1,1,0};
float luz_posicion []={0,0,0,0};
//Propiedades material tetera y esfera
float mat_ambiente [] = {.3,0,0,1};
float mat_difuso [] = {.5,0,0,1};
float mat_especular [] = {.8,.8,0,1};
float mat_emision [] = {0,0,0,1};
float mat_brillo = 64;
//Propiedades material esfera-foco
float foco_ambiente_difusa [] = {1,1,.1,0};
float foco_emision [] = {0.5,0.5,0,0};
float foco_direction [] = {0,-2,0};

void ajusta(int ancho, int alto) {
	glClearColor(0.9,0.9,0.9,0.0);

	glLightfv(GL_LIGHT0,GL_AMBIENT,luz_ambiente);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,luz_difusa);
	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,.8);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3,3,-1.5,3.5,-3,3);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void dibuja(void)  {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();  //foco
		glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,foco_ambiente_difusa);
		glMaterialfv(GL_FRONT,GL_EMISSION,foco_emision);
		glTranslatef(0,3,0);
		glutSolidSphere(.35,15,15);
	glPopMatrix();
	glPushMatrix();  //esfera
		glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambiente);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_difuso);
		glMaterialfv(GL_FRONT,GL_SPECULAR,mat_especular);
		glMaterialfv(GL_FRONT,GL_EMISSION,mat_emision);
		glMaterialf(GL_FRONT,GL_SHININESS,mat_brillo);
		glTranslatef(2.4,2,0);
		glutSolidSphere(.4,20,20);
	glPopMatrix();
	glutSolidTeapot(1.3);  //tetera
	glFlush();
}

void teclado(unsigned char tecla, int x, int y){
 switch (tecla) {
		case 27: exit(0);
		case 'd': 
			luz_posicion [0] = 0;
			luz_posicion [1] = 3;
			luz_posicion [2] = 0;
			luz_posicion [3] = 0;
			glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);
	 	break;
	 	case 'p': 
	 		luz_posicion [0] = 0;
			luz_posicion [1] = 3;
			luz_posicion [2] = 0;
			luz_posicion [3] = 1;
	 		glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);
			glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180);
			glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0);
	 	break;
	 	case 'f': 
	 		luz_posicion [3]=1; 
	 		glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, foco_direction);
			glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 50);
			glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10);
	 	break;
 }
 glutPostRedisplay();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(300,250);
	glutCreateWindow("Flor que da fulgor");
	glutDisplayFunc(dibuja);
	glutReshapeFunc(ajusta);
	glutKeyboardFunc (teclado);
	glutMainLoop();
	return 0;
}
