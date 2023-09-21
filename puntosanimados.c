#include <GL/glut.h>
#include <math.h>

int col=0;

void puntos(){
	 int i;
	 for(i=0; i<15; i++){
	 		if(col==0){
	 			glColor3f(0,0,1);
			 }else if(col==1){
			 	glColor3f(0,1,0);
			 }
	 		glPointSize(20);
	 		glBegin(GL_POINTS);
                glVertex2i(50+(i*30), 200);
            glEnd();
	 }
}
void ajusta(int ancho, int alto){
	 glClearColor(1.0,1.0,1.0,0.0);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0, 640, 0, 480);
}
void dibuja(void){
 glClear(GL_COLOR_BUFFER_BIT);
 puntos();
 glutSwapBuffers();
}
void tiempo(int t){
	 if(col==0){
	 	col=1;
	 }else if(col==1){
	 	col=0;
	 }
	 glutPostRedisplay();
	 glutTimerFunc(500,tiempo,1);
}

int main(int argc, char** argv){
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	 glutInitWindowSize(640,480);
	 glutInitWindowPosition(100, 150);
	 glutCreateWindow("Lineas");
	 glutReshapeFunc(ajusta);
	 glutIdleFunc(tiempo);
	 glutDisplayFunc(dibuja);
	 glutMainLoop();
	 return 0;
}
