#include <gl/glut.h>
#include <stdio.h>
#include <math.h>
GLfloat ptosctl[4][3];
struct Punto{
   int cx;
   int cy;
};
struct Punto p[4];
int puntos=0;
int fin=0;
int par=0, longi=0;
GLboolean mostrar=GL_TRUE; //mostrar o no los puntos
GLboolean rojo=GL_TRUE;
float xx[31];
float yy[31];
float dist[31];
float distac[31];
float gnorm[31];
float tnuevo[31];
float t[31];

void inicializa(void)
{
	 glClearColor(1.0, 1.0, 1.0, 0.0);
	 glMap1f(GL_MAP1_VERTEX_3, 0, 1, 3, 4, &ptosctl[0][0]);
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
	    	if(puntos<4){
	    		p[puntos].cx = x;
		        p[puntos].cy = alto_ventana - y;
		        ptosctl[puntos][0]=x;
		        ptosctl[puntos][1]=alto_ventana - y;
		        ptosctl[puntos][2]=0;
		        puntos++;
			}
	        
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
		case 'p':
			if(par==0){
				par=1;
			}else{
				par=0;
			}
			dibuja();
		    glutPostRedisplay();
			break;
		case 'l':
			if(longi==0){
				longi=1;
			}else{
				longi=0;
			}
			dibuja();
		    glutPostRedisplay();
			break;
    }
}
void dibuja(void){
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	
	//puntos de control
        for (i=0 ; i< 4; i++)	{
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
	  if(par==1){
	  	glColor3f(0.0, 0.0, 1.0);
		glEvalMesh1(GL_POINT, 0, 30);
	  }
	  if(longi==1){
			dist[0]=0;
			distac[0]=0;
			gnorm[0]=0;
			gnorm[30]=1;
			tnuevo[0]=0;
			for(i=0;i<=30;i++){
				t[i]=i/30.0;
			}
	  		longitud();
	  }
	  
	 
	 glFlush();
}
int longitud(){
	int i;
	for(i=0;i<=30;i++){
		xx[i]=pow(1.0-t[i],3)*ptosctl[0][0]+3.0*pow(1.0-t[i],2)*t[i]*ptosctl[1][0]+3.0*(1.0-t[i])*t[i]*t[i]*ptosctl[2][0]+pow(t[i],3)*ptosctl[3][0];
		yy[i]=pow(1.0-t[i],3)*ptosctl[0][1]+3.0*pow(1.0-t[i],2)*t[i]*ptosctl[1][1]+3.0*(1.0-t[i])*t[i]*t[i]*ptosctl[2][1]+pow(t[i],3)*ptosctl[3][1];
	}
	for(i=1;i<=30;i++){
		dist[i]=sqrt((pow(xx[i-1]-xx[i], 2)+pow(yy[i-1]-yy[i],2)));
		distac[i]=dist[i]+distac[i-1];
		
	}
	for(i=29;i>0;i--){
		gnorm[i]= gnorm[i+1]*distac[i]/distac[i+1];
	}
	for(i=1;i<=30;i++){
		tnuevo[i]=t[i]+(((t[i+1])-gnorm[i])/(gnorm[i+1]-gnorm[i]))*(t[i+1]-t[i]);
	}
	
	glColor3f(0.0, 1.0, 1.0);
	  	glBegin(GL_POINTS);
 		for(i = 0; i <= 30; i++){
 			glEvalCoord1f((GLfloat)tnuevo[i]);
		 }
 		glEnd();
	
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
