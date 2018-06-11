#include "Animaciones.h"
#include "ETSIDI.h"
#include "glut.h"

Animaciones::Animaciones() {
	i = 0;
}


Animaciones::~Animaciones() {

}


void Animaciones::DibujaAnimacion1() {
	//do{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/Introduccion_1.png").id);

		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(- ETSIDI::getTexture("images/Introduccion_1.png").width, ETSIDI::getTexture("images/Introduccion_1.png").height);
		glTexCoord2d(0, 0); glVertex2f(- ETSIDI::getTexture("images/Introduccion_1.png").width, - ETSIDI::getTexture("images/Introduccion_1.png").height);
		glTexCoord2d(1, 0); glVertex2f(ETSIDI::getTexture("images/Introduccion_1.png").width, - ETSIDI::getTexture("images/Introduccion_1.png").height);
		glTexCoord2d(1, 1); glVertex2f(ETSIDI::getTexture("images/Introduccion_1.png").width, ETSIDI::getTexture("images/Introduccion_1.png").height);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
/*
		i++;
	} while (i < 1);

	do{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/Introduccion_2.png").id);

		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(ETSIDI::getTexture("images/Introduccion_2.png").width, ETSIDI::getTexture("images/Introduccion_2.png").height);
		glTexCoord2d(0, 0); glVertex2f(ETSIDI::getTexture("images/Introduccion_2.png").width, ETSIDI::getTexture("images/Introduccion_2.png").height);
		glTexCoord2d(1, 0); glVertex2f(ETSIDI::getTexture("images/Introduccion_2.png").width, ETSIDI::getTexture("images/Introduccion_2.png").height);
		glTexCoord2d(1, 1); glVertex2f(ETSIDI::getTexture("images/Introduccion_2.png").width, ETSIDI::getTexture("images/Introduccion_2.png").height);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);

		i++;
	} while (i < 2);


	do{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/Introduccion_3.png").id);

		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(ETSIDI::getTexture("images/Introduccion_3.png").width, ETSIDI::getTexture("images/Introduccion_3.png").height);
		glTexCoord2d(0, 0); glVertex2f(ETSIDI::getTexture("images/Introduccion_3.png").width, ETSIDI::getTexture("images/Introduccion_3.png").height);
		glTexCoord2d(1, 0); glVertex2f(ETSIDI::getTexture("images/Introduccion_3.png").width, ETSIDI::getTexture("images/Introduccion_3.png").height);
		glTexCoord2d(1, 1); glVertex2f(ETSIDI::getTexture("images/Introduccion_3.png").width, ETSIDI::getTexture("images/Introduccion_3.png").height);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);

		i++;
	} while (i < 3);*/

}
