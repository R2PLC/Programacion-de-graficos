#include <gl/glut.h>
#include <stdio.h>
GLfloat ptosctl[60][3];
struct Punto{
   int cx;
   int cy;
   float color[3];
   int tamanio;
};
struct Punto p[60];
int puntos=0;
int fin=0;
GLboolean mostrar=GL_TRUE; //mostrar o no los puntos
GLboolean rojo=GL_TRUE;
//GLboolean negro=GL_TRUE;    // elección de color

void inicializa(void)
{
	 glClearColor(1.0, 1.0, 1.0, 0.0);
	 glMap1f(GL_MAP1_VERTEX_3, 0, 1, 3, puntos, &ptosctl[0][0]);
	 glEnable(GL_MAP1_VERTEX_3);
}

void ajusta(int w, int h) {   
	glViewport(0, 0, w, h);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(0, 640, 0, 480);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
}
void raton(int boton, int estado, int x, int y){
	if (fin==0){
		int alto_ventana=480;
	    if(boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)    {
	        p[puntos].cx = x;
	        p[puntos].cy = alto_ventana - y;
	        p[puntos].color[0]=(rojo)?1:0;   //rojo
	        ptosctl[puntos][0]=x;
	        ptosctl[puntos][1]=alto_ventana - y;
	        ptosctl[puntos][2]=0;
	        puntos++;
	    }
	    inicializa();
		glutPostRedisplay();
	}
    
}

void teclado(unsigned char tecla, int x, int y){
    switch(tecla) {
      	case 27:	exit(0);		// Esc =>Salir del programa
      	case 127: 
      		if(fin==0){
      			puntos--;
		  		ptosctl[puntos][0]=0;
        		ptosctl[puntos][1]=0;
       			ptosctl[puntos][2]=0;
		    	inicializa();
		    	glutPostRedisplay();
			  }
		  break;
		case 'n':
			fin=1;
		break;
    }
}
void dibuja(void){
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	
	//puntos de control
        for (i=0 ; i< puntos; i++)	{
            glPointSize(6.0);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POINTS);
                glVertex2i(p[i].cx, p[i].cy);
            glEnd();
			}  
    
	 //curva de bezier
	 glLineWidth(4);
	 glColor3f(0.0, 0.0, 0.0);
	 glMapGrid1f(30,0,1);
	 glEvalMesh1(GL_LINE, 0, 30);
	 
	 glFlush();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Bezier");
	glutDisplayFunc(dibuja);
	glutMouseFunc(raton);
	inicializa();
	glutKeyboardFunc(teclado);
	glutReshapeFunc(ajusta);
	glutMainLoop();
	return 0;
}
