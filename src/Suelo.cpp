#include "Suelo.h"
#include "ETSIDI.h"
#include "glut.h"



Suelo::Suelo() {
}


Suelo::~Suelo()
{
}

void Suelo::Dibuja(float zoom, const char* a) {
	
	glEnable(GL_BLEND);									
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(a).id);

	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1, 1);

	glTexCoord2d(0, 1); glVertex2f(-ETSIDI::getTexture(a).width / zoom, -ETSIDI::getTexture(a).height / zoom);
	glTexCoord2d(0, 0); glVertex2f(-ETSIDI::getTexture(a).width / zoom, ETSIDI::getTexture(a).height / zoom);
	glTexCoord2d(1, 0); glVertex2f(ETSIDI::getTexture(a).width / zoom, ETSIDI::getTexture(a).height / zoom);
	glTexCoord2d(1, 1); glVertex2f(ETSIDI::getTexture(a).width / zoom, -ETSIDI::getTexture(a).height / zoom);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}