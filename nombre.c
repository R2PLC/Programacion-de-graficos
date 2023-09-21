#include <gl/glut.h>

struct Punto{
   int cx;
   int cy;
   float color[3];
   int tamanio;
};
struct Punto p[1000];
int puntos=0;
int pfinal=0;

void ajusta(int ancho, int alto) {
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}
void raton(/*int boton, int estado,*/ int x, int y){
    int alto_ventana=480;
        p[puntos].cx = x;
        p[puntos].cy = alto_ventana - y;
        puntos++;
	glutPostRedisplay();
}

void dibuja(void){
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
        for (i=0 ; i< puntos-1; i++)	{
            glLineWidth(3);
            glColor3f(0,0,1);
            glBegin(GL_LINES);
                glVertex2i(p[i].cx, p[i].cy);
                glVertex2i(p[i+1].cx, p[i+1].cy);
            glEnd();
        }
    glFlush();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Dibujando puntos estructuras");
	glutDisplayFunc(dibuja);
	glutMotionFunc(raton);
	glutReshapeFunc(ajusta);
	glutMainLoop();
	return 0;
}
