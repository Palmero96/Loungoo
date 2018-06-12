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
	if (i > 0 && i <= 500) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/Introduccion_1.png").id);

		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(- ETSIDI::getTexture("images/Introduccion_1.png").width / 2,-ETSIDI::getTexture("images/Introduccion_1.png").height /2);
		glTexCoord2d(0, 0); glVertex2f(- ETSIDI::getTexture("images/Introduccion_1.png").width / 2, ETSIDI::getTexture("images/Introduccion_1.png").height / 2);
		glTexCoord2d(1, 0); glVertex2f(  ETSIDI::getTexture("images/Introduccion_1.png").width / 2, ETSIDI::getTexture("images/Introduccion_1.png").height / 2);
		glTexCoord2d(1, 1); glVertex2f(  ETSIDI::getTexture("images/Introduccion_1.png").width / 2,-ETSIDI::getTexture("images/Introduccion_1.png").height / 2);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
	}

	else if (i > 500 && i <= 1000) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/Introduccion_2.png").id);

		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(-ETSIDI::getTexture("images/Introduccion_2.png").width/2,-ETSIDI::getTexture("images/Introduccion_2.png").height/2);
		glTexCoord2d(0, 0); glVertex2f(-ETSIDI::getTexture("images/Introduccion_2.png").width/2, ETSIDI::getTexture("images/Introduccion_2.png").height/2);
		glTexCoord2d(1, 0); glVertex2f( ETSIDI::getTexture("images/Introduccion_2.png").width/2, ETSIDI::getTexture("images/Introduccion_2.png").height/2);
		glTexCoord2d(1, 1); glVertex2f( ETSIDI::getTexture("images/Introduccion_2.png").width/2,-ETSIDI::getTexture("images/Introduccion_2.png").height/2);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
	}

	if (i > 1000) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/Introduccion_3.png").id);

		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(-ETSIDI::getTexture("images/Introduccion_3.png").width/2,-ETSIDI::getTexture("images/Introduccion_3.png").height/2);
		glTexCoord2d(0, 0); glVertex2f(-ETSIDI::getTexture("images/Introduccion_3.png").width/2, ETSIDI::getTexture("images/Introduccion_3.png").height/2);
		glTexCoord2d(1, 0); glVertex2f( ETSIDI::getTexture("images/Introduccion_3.png").width/2, ETSIDI::getTexture("images/Introduccion_3.png").height/2);
		glTexCoord2d(1, 1); glVertex2f( ETSIDI::getTexture("images/Introduccion_3.png").width/2,-ETSIDI::getTexture("images/Introduccion_3.png").height/2);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
	}

	i++;
}
