#include <GL/glut.h>
//Propiedades luz
float luz_ambiente [] = {0.5,0.7,0,0};
float luz_difusa [] = {1,1,1,0};
float luz_posicion [] = {0,3,0,0};
//Propiedades material perla
float perla_ambiente[] = {0.25, 0.20725, 0.20725, 1};
float perla_difuso [] = {1, 0.829, 0.829,1};
float perla_especular [] = {0.296648, 0.296648, 0.296648,1};
float perla_brillo = 0.088*128;
//Propiedades material esmeralda
float esmeralda_ambiente[] = {0.0215, 0.1745, 0.0215, 1};
float esmeralda_difuso [] = {0.07568, 0.61424, 0.07568,1};
float esmeralda_especular [] = {0.633, 0.727811, 0.633,1};
float esmeralda_brillo = .6*128;
//Propiedades material esfera-foco
float foco_ambiente_difusa [] = {1,1,.1,0};
float foco_emision [] = {0.5,0.5,0,0};


void renderTeapot(GLfloat x, GLfloat y,
 GLfloat ambr, GLfloat ambg, GLfloat ambb,
 GLfloat difr, GLfloat difg, GLfloat difb,
 GLfloat specr, GLfloat specg, GLfloat specb,
 GLfloat shine)
{
	 float mat[4];
	 glPushMatrix();
	 glTranslatef(x, y, 0.0);
	 mat[3] = 1.0;
	 mat[0] = ambr; mat[1] = ambg; mat[2] = ambb;
	 glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	 mat[0] = difr; mat[1] = difg; mat[2] = difb;
	 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	 mat[0] = specr; mat[1] = specg; mat[2] = specb;
	 glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
	 glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);
	 glutSolidTeapot(1.3);
	 glPopMatrix();
}

void ajusta(int ancho, int alto) {
	glClearColor(0.9,0.9,0.9,0.0);
	glLightfv(GL_LIGHT0,GL_AMBIENT,luz_ambiente);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,luz_difusa);
	glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);
	glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,.8);

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
		//glutSolidSphere(.35,15,15);
	glPopMatrix();
	glPushMatrix();  //perla
		glMaterialfv(GL_FRONT,GL_AMBIENT,perla_ambiente);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,perla_difuso);
		glMaterialfv(GL_FRONT,GL_SPECULAR,perla_especular);
		glMaterialf(GL_FRONT,GL_SHININESS,perla_brillo);
		glTranslatef(2.4,2,0);
		glutSolidSphere(.4,20,20);
	glPopMatrix();
	glPushMatrix();  //esmeralda
		glMaterialfv(GL_FRONT,GL_AMBIENT,esmeralda_ambiente);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,esmeralda_difuso);
		glMaterialfv(GL_FRONT,GL_SPECULAR,esmeralda_especular);
		glMaterialf(GL_FRONT,GL_SHININESS,esmeralda_brillo);
		glTranslatef(-2.4,2,0);
		glutSolidSphere(.4,20,20);
	glPopMatrix();
		 renderTeapot(0, 0, 0.329412, 0.223529, 0.027451,
 0.780392, 0.568627, 0.113725, 0.992157, 0.941176, 0.807843,
 0.21794872);  //tetera
	glFlush();
}
int main(int argc, char ** argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(300,250);
	glutCreateWindow("Luz Puntual");
	glutDisplayFunc(dibuja);
	glutReshapeFunc(ajusta);
	glutMainLoop();
	return 0;
}
