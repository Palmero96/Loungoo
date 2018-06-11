
#include "Coordinador.h"
#include <glut.h>

Coordinador Loungoo;

int KeyDown[256];

int anchopantalla = 640;
int altopantalla = 480;

void OnDraw(void);
void OnTimer(int value);
void OnSpecialKeyboardDown(int key, int x, int y);
void OnSpecialKeyboardUp(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);


int main(int arcg, char** argv) {
	glutInit(&arcg, argv);								//Inicializa GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);		//Para doble buffer --> GLUT_DOUBLE

	glutInitWindowSize(anchopantalla, altopantalla);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("LOUNGOO - Let's Play a Game");		//Crea una pantalla con dicho titulo

				//CALLBACKS
	glutDisplayFunc(OnDraw);
	glutTimerFunc(0, OnTimer, 0);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(OnSpecialKeyboardDown);
	glutSpecialUpFunc(OnSpecialKeyboardUp);

	glutMainLoop();
	return 0;
}


void OnDraw(void) {;
	glClear(GL_COLOR_BUFFER_BIT); //Borrado de la pantalla

	Loungoo.Dibuja();

	glutSwapBuffers();			//Renderizado
}


void OnTimer(int value) {
	Loungoo.Mueve();

	glutPostRedisplay();
	//Seteamos un valor de 25ms de refresh
	glutTimerFunc(15, OnTimer, 0);
	//glutPostRedisplay();
}

void OnSpecialKeyboardDown(int key, int x, int y) {
	Loungoo.TeclaEspecial(key);
}

void OnSpecialKeyboardUp(int key, int x, int y) {
	Loungoo.TeclaEspecialUp(key);
}

void keyboard(unsigned char key, int x, int y) {
	KeyDown[key] = 1;

	Loungoo.Tecla(key);
	glutPostRedisplay();
}

void keyboardUp(unsigned char key, int x, int y) {
	KeyDown[key] = 0;

	Loungoo.TeclaUp(key);
	glutPostRedisplay();
}