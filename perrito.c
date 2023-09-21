#include <gl/glut.h>
#include "perritos.h"

int xx =20;
int yy=20;
int col=0;
void ajusta(int ancho, int alto) {
	 glClearColor(1.0,1.0,1.0,0.0);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void teclado(unsigned char tecla, int x, int y){
    switch(tecla) {
		case GLUT_KEY_UP: 
			yy+=20;
			glutPostRedisplay();
            break;
      	case GLUT_KEY_DOWN: 
		  	yy-=20;
      		glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT: 
			xx-=20;
			glutPostRedisplay();
            break;
      	case GLUT_KEY_RIGHT: 
		  	xx+=20;
		  	glutPostRedisplay();
            break;
    }
    if(col==0){
		col=1;
	}else if (col==1){
    	col=0;
	}
}
void dibujaperrito(void){
	 int i,j;
	 int tam=10; // tamaño del punto
	 glClear(GL_COLOR_BUFFER_BIT);
	 glPointSize(tam);
	 glBegin(GL_POINTS);
	 for(i=0 ; i< ALTO; i++)
	 	for(j=0 ; j< ANCHO; j++){
	 		if(col==0){
	 			glColor3ubv(paleta[perro[i][j]]);
			 }else{
			 	glColor3ubv(paleta2[perro[i][j]]);
			 }
	 		glVertex2i((190+j*tam)+xx,(390-i*tam)+yy);
	 }
	 glEnd();
	 glFlush();
	 glutPostRedisplay();
	 
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(20, 50);
	glutCreateWindow("Perrito");
	glutDisplayFunc(dibujaperrito);
	glutReshapeFunc(ajusta);
	glutSpecialFunc(teclado);
	glutMainLoop();
	return 0;
}
