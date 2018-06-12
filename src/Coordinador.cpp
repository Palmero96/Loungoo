#include "Coordinador.h"
#include "glut.h"


Coordinador::Coordinador() {
	estado = INICIO;
	anima.resetValori();
}


Coordinador::~Coordinador() {
}


void Coordinador::Dibuja() {
	if (estado == INICIO) {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		//Establece el color de fondo como negro opaco
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glOrtho(-320, 320, -240, 240, -1, 1);

		anima.DibujaAnimacion1();
	}

	else if (estado == JUEGO) {
		mundo.Dibuja();
	}

	else if (estado == PAUSA) {
		mundo.Dibuja();
		Coordinador::DibujaTextura("images/Pause.png", 6, mundo.getPosicionCamara());
	}

	else if (estado == GAMEOVER) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		//Establece el color de fondo como negro opaco
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glOrtho(-320, 320, -240, 240, -1, 1);

		anima.DibujaAnimacion2();
	}

	else if (estado == FIN) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		//Establece el color de fondo como negro opaco
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glOrtho(-320, 320, -240, 240, -1, 1);

		anima.DibujaAnimacion3();
	}

	else if (estado == CONVERSACION) {
		mundo.Dibuja();
	}
}


void Coordinador::Mueve() {
	if (estado == JUEGO) {
		mundo.Mueve();
		/*INTRODUCIR LA CONDICION PARA CAMBIAR DE ESTADO*/
		//Acordarse de resetear el valor i al cambiar a estados con animacion
	}
}


void Coordinador::TeclaEspecial(int key) {
	if (estado == JUEGO) {
		mundo.TeclaEspecial(key);
	}
}


void Coordinador::TeclaEspecialUp(int key) {
	if (estado == JUEGO) {
		mundo.TeclaEspecialUp(key);
	}
}


void Coordinador::Tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key >= 0 && key <= 256){
			mundo.Inicializa();
			estado = JUEGO;
		}
	}

	else if (estado == JUEGO) {
		mundo.Tecla(key);
		switch (key) {
		case 27:
			estado = PAUSA;
			break;
		}
	}

	else if (estado == PAUSA) {
		switch (key) {
		case 27:
			exit(0);
			break;
		case 'C':
		case 'c':
			estado = JUEGO;
			break;
		}
	}

	else if (estado == GAMEOVER) {
		switch (key) {
		case 'Y':
		case 'y':
			mundo.Inicializa();
			estado = JUEGO;
			break;
		case 'N':
		case 'n':
			exit(0);
			break;
		}
	}

	else if (estado == FIN) {
		if (key >= 0 && key <= 256) {
			exit(0);
		}
	}
}


void Coordinador::TeclaUp(unsigned char key) {
	if (estado == JUEGO) {
		mundo.TeclaUp(key);
	}
}



void Coordinador::DibujaTextura(const char* path, float zoom, Vector a){
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);

	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1, 1);

	glTexCoord2d(0, 1); glVertex2f(a.getx() - ETSIDI::getTexture(path).width / zoom, a.gety() - ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(0, 0); glVertex2f(a.getx() - ETSIDI::getTexture(path).width / zoom, a.gety() + ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(1, 0); glVertex2f(a.getx() + ETSIDI::getTexture(path).width / zoom, a.gety() + ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(1, 1); glVertex2f(a.getx() + ETSIDI::getTexture(path).width / zoom, a.gety() - ETSIDI::getTexture(path).height / zoom);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}