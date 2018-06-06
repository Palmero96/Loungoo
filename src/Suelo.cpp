#include "Suelo.h"
#include "ETSIDI.h"
#include "glut.h"



Suelo::Suelo(const char* a) {
	path = a;
	anchotext = ETSIDI::getTexture(path).width;
	altotext = ETSIDI::getTexture(path).height;

	offset.setxy(0, 0);
}

Suelo::Suelo(const char* a, float b, float c) {
	path = a;
	anchotext = ETSIDI::getTexture(path).width;
	altotext = ETSIDI::getTexture(path).height;

	offset.setxy(b, c);
}

Suelo::~Suelo()
{
}

void Suelo::Dibuja(float zoom) {
	glEnable(GL_BLEND);									
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);

	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1, 1);

	glTexCoord2d(0, 1); glVertex2f(offset.getx() - ETSIDI::getTexture(path).width / zoom,
		offset.gety() - ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(0, 0); glVertex2f(offset.getx() - ETSIDI::getTexture(path).width / zoom, 
		offset.gety() + ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(1, 0); glVertex2f(offset.getx() + ETSIDI::getTexture(path).width / zoom, 
		offset.gety() + ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(1, 1); glVertex2f(offset.getx() + ETSIDI::getTexture(path).width / zoom, 
		offset.gety() - ETSIDI::getTexture(path).height / zoom);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}