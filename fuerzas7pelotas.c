#include <GL/glut.h>
#define GRAVEDAD -9.8
#define MASA 200 // masa de la pelota
double h= 0.025; // h incrementos de tiempo
double posicion[7][3]= {{-3,0,0},{-2,0,0},{-1,0,0},{0,0,0},{1,0,0},{2,0,0},{3,0,0}};
double velocidad[7][3]= {{0,0,0}, {0,0,0}, {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
double fzaX=.02;
double fzaZ=-.05;
GLboolean bx=GL_FALSE;
GLboolean by=GL_FALSE;
GLboolean bz=GL_FALSE;
void integraEuler(){
	
	 int i;
	 for(i=0;i<=6;i++){
	 	 // v(t+h)=v(t)+F(t)/m*h
	 	if (bx) velocidad[i][0] += fzaX*h*(i+1);
		 if (by) velocidad[i][1] += GRAVEDAD/MASA*h;
		 if (bz) velocidad[i][2] += fzaZ*h*(i+1);
		 // x(t+h)=x(t) + v(t+h)*h
		 posicion[i][0] += velocidad[i][0]*h;
		 posicion[i][1] += velocidad[i][1]*h;
		 posicion[i][2] += velocidad[i][2]*h;
	 }
	 
}
void ajusta(int alto, int ancho){
	 glClearColor(0.5,0.5,0.5,0);
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluPerspective(60,(float)alto/ancho, 1, 100);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
}
void dibuja(void){
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3ub(0,0,0);
	 glLineWidth(2);
	 glPushMatrix();
		 glTranslatef(0,0,-16);
		 glutWireCube(11);
		 glColor3ub(0,0,255);
			 glPushMatrix();
				 glTranslated(posicion[0][0],posicion[0][1],posicion[0][2]);
				 glutSolidSphere(.4,20,20);
			 glPopMatrix();
			 glColor3ub(0,255,0);
			 glPushMatrix();
				 glTranslated(posicion[1][0],posicion[1][1],posicion[1][2]);
				 glutSolidSphere(.4,20,20);
			 glPopMatrix();
			 glColor3ub(255,255,0);
			 glPushMatrix();
				 glTranslated(posicion[2][0],posicion[2][1],posicion[2][2]);
				 glutSolidSphere(.4,20,20);
			 glPopMatrix();
			 glColor3ub(255,0,0);
			 glPushMatrix();
				 glTranslated(posicion[3][0],posicion[3][1],posicion[3][2]);
				 glutSolidSphere(.4,20,20);
			 glPopMatrix();
			 glColor3ub(20,40,200);
			 glPushMatrix();
				 glTranslated(posicion[4][0],posicion[4][1],posicion[4][2]);
				 glutSolidSphere(.4,20,20);
			 glPopMatrix();
			 glColor3ub(0,255,255);
			 glPushMatrix();
				 glTranslated(posicion[5][0],posicion[5][1],posicion[5][2]);
				 glutSolidSphere(.4,20,20);
			 glPopMatrix();
			 glColor3ub(255,0,255);
			 glPushMatrix();
				 glTranslated(posicion[6][0],posicion[6][1],posicion[6][2]);
				 glutSolidSphere(.4,20,20);
			 glPopMatrix();
	 glPopMatrix();
	 glutSwapBuffers();
}
void mueve(void){
	 integraEuler();
	 //colisiones
	 int i;
	 for(i=0; i<=6;i++){
	 	if(posicion[i][0]>=5 || posicion[i][0]<=-5){ //X
		 fzaX=-1*fzaX;
		 velocidad[i][0]=0;
		 posicion[i][0]=(posicion[i][0]>=5)?4.8:-4.8;
		 }
		 if(posicion[i][1]>=5){ //Y Arriba
		 velocidad[i][1]= 0;
		 posicion[i][1]= 4.2;
		 }
		 if(posicion[i][1]<=-5){ //Y Abajo
		 velocidad[i][1]= 0.9;
		 posicion[i][1]= -4.8;
		 }
		 if(posicion[i][2]>=5 || posicion[i][2]<=-5){ //Z
		 fzaZ=-1*fzaZ;
		 velocidad[i][2]=0;
		 posicion[i][2]=(posicion[i][2]>=5)?4.8:-4.8;
		 }
	 }
	 glutPostRedisplay();
}
void teclado(unsigned char key, int x, int y) {
	 switch (key) {
	 case 27: exit(0);
	 case 'x': bx = !bx ;break;
	 case 'y': by = !by; break;
	 case 'z': bz = !bz ;
	 }
}
int main(int argc, char** argv){
	 glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	 glutInit(&argc, argv);
	 glutInitWindowSize(600, 600);
	 glutCreateWindow("Bolita");
	 glutDisplayFunc(dibuja);
	 glutReshapeFunc(ajusta);
	 glutKeyboardFunc(teclado);
	 glutIdleFunc(mueve);
	 glutMainLoop();
	 return 0;
}
