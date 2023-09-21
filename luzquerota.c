#include <GL/glut.h>
//Propiedades luz
float gira=0, muevea=3, muevei=0;
float luz_ambiente [] = {0.5,0.7,0,0};
float luz_difusa [] = {1,1,1,0};
float luz_posicion[4];

//Propiedades material tetera y esfera
float mat_ambiente [] = {.3,0,0,1};
float mat_difuso [] = {.5,0,0,1};
float mat_especular [] = {.8,.8,0,1};
float mat_emision [] = {0,0,0,1};
float mat_brillo = 64;
//Propiedades material esfera-foco
float foco_ambiente_difusa [] = {1,1,.1,0};
float foco_emision [] = {0.5,0.5,0,0};



void ajusta(int ancho, int alto) {
	glClearColor(0.9,0.9,0.9,0.0);
	
	luz_posicion[0]=muevei;
	luz_posicion[1]=muevea;
	luz_posicion[2]=0;
	luz_posicion[3]=1;
	
	glLightfv(GL_LIGHT0,GL_AMBIENT,luz_ambiente);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,luz_difusa);
	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,.8);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3,3,-1.5,3.5,-3,3);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void special (unsigned char key, int x, int y)
{
	 switch (key) {
	 case 27: exit(0);
	 case GLUT_KEY_DOWN: 
	 	muevea = (muevea - 0.1);
	 	luz_posicion[1] =muevea;
	 	break;
	 case GLUT_KEY_UP: 
	 	muevea = (muevea + 0.1);
	 	luz_posicion[1] =muevea;
	 	break;
	case GLUT_KEY_LEFT: 
	 	muevei = (muevei - 0.1);
	 	luz_posicion[0] = muevei;
	 	break;
	case GLUT_KEY_RIGHT: 
	 	muevei = (muevei + 0.1);
	 	luz_posicion[0] = muevei;
	 	break;
	}
	 glutPostRedisplay();
}

void teclado (unsigned char key, int x, int y)
{
	 switch (key) {
	 case 27: exit(0);
	 case 'A': 
	 	gira = (gira + 0.1);
	 	luz_posicion[2] = gira;
	 	break;
	 case 'a': 
	 	gira = (gira - 0.1);
	 	luz_posicion[2] = gira;
	 	break;
	 }
	 glutPostRedisplay();
}

void dibuja(void)  {
	glClear(GL_COLOR_BUFFER_BIT);
	glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);
	glPushMatrix();  //foco
		glTranslatef((GLfloat)muevei,(GLfloat)muevea,(GLfloat)gira);
		glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,foco_ambiente_difusa);
		glMaterialfv(GL_FRONT,GL_EMISSION,foco_emision);
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
int main(int argc, char ** argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(300,250);
	glutCreateWindow("Luz que rota");
	glutDisplayFunc(dibuja);
	glutReshapeFunc(ajusta);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(special);
	glutMainLoop();
	return 0;
}
