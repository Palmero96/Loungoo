#include "Animaciones.h"
#include "ETSIDI.h"
#include "glut.h"
Animaciones::Animaciones() {
}


Animaciones::~Animaciones() {

}


void Animaciones::resetValori() {
	i = 0;
}


void Animaciones::DibujaAnimacion1() {
	if (i == 0) ETSIDI::play("sounds/Conversacion_1.mp3");
	if (i > 0 && i <= 600) {
		Animaciones::DibujaTextura("images/Introduccion_1.png");
	}
	if (i == 600) ETSIDI::play("sounds/Conversacion_1_2.mp3");
	else if (i > 600 && i <= 1200) {
		Animaciones::DibujaTextura("images/Introduccion_2.png");
	}
	if (i == 1200) ETSIDI::play("sounds/Conversacion_1_2.mp3");
	if (i > 1200) {
		Animaciones::DibujaTextura("images/Introduccion_3.png");
	}
	i++;
}


void Animaciones::DibujaAnimacion2() {
	if (i < 70) {
		Animaciones::DibujaTextura("images/Muerte_1.png");
	}

	else if (i >= 70) {
		Animaciones::DibujaTextura("images/Muerte_2.png");
	}

	i++;
}


void Animaciones::DibujaAnimacion3() {
	if (i == 0) ETSIDI::play("sounds/Conversacion_3.mp3");
	if (i < 160) {
		Animaciones::DibujaTextura("images/Final_1.png");
	}

	else if (i > 175) {
		Animaciones::DibujaTextura("images/Final_2.png");
	}

	i++;
}

void Animaciones::DibujaTextura(const char* path) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);

	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1, 1);

	glTexCoord2d(0, 1); glVertex2f(- ETSIDI::getTexture(path).width / 2, - ETSIDI::getTexture(path).height / 2);
	glTexCoord2d(0, 0); glVertex2f(- ETSIDI::getTexture(path).width / 2, + ETSIDI::getTexture(path).height / 2);
	glTexCoord2d(1, 0); glVertex2f(+ ETSIDI::getTexture(path).width / 2, + ETSIDI::getTexture(path).height / 2);
	glTexCoord2d(1, 1); glVertex2f(+ ETSIDI::getTexture(path).width / 2, - ETSIDI::getTexture(path).height / 2);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

}