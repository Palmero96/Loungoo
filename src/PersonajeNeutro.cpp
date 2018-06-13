#include "PersonajeNeutro.h"



PersonajeNeutro::PersonajeNeutro() : Personaje(){
	rango = 50.0f;
	movale = 0;
}


PersonajeNeutro::PersonajeNeutro(float a, float b, float c, float d, const char* path, int xa, int xb)
: Personaje(a, b, c, d, path, xa, xb){
	rango = 50.0f;
	movale = 0;
}


PersonajeNeutro::PersonajeNeutro(float a, float b, float c, float d, float r, const char* path, int xa, int xb)
: Personaje(a, b, c, d, path, xa, xb) {
	rango = r;
	movale = 0;
}


PersonajeNeutro::~PersonajeNeutro() {

}


void PersonajeNeutro::Interacciona(Vector p) {
	const char* path = "images/Conversacion_1.png";
	Vector a(0, 0);
	float zoom = 4.3;

	if (movale < 340) {
		path = "images/Conversacion_1.png";
	}
	if (movale >= 340 && movale < 440) {
		path = "images/Conversacion_1_2.png";
	}
	if (movale >= 440) {
		path = "images/Sidi.png";
		const char* path2 = "images/Etsi.png";
		a.setxy(1020 - 2*movale, 0);
		Vector b(2*movale - 1020, 0);

		if (movale > 510) {
			a.setxy(0, 0);
			b.setxy(0, 0);
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path2).id);

		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor4f(1, 1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(p.getx() + b.getx() - ETSIDI::getTexture(path2).width / zoom, 
			p.gety() + b.gety() - ETSIDI::getTexture(path2).height / zoom);
		glTexCoord2d(0, 0); glVertex2f(p.getx() + b.getx() - ETSIDI::getTexture(path2).width / zoom, 
			p.gety() + b.gety() + ETSIDI::getTexture(path2).height / zoom);
		glTexCoord2d(1, 0); glVertex2f(p.getx() + b.getx() + ETSIDI::getTexture(path2).width / zoom, 
			p.gety() + b.gety() + ETSIDI::getTexture(path2).height / zoom);
		glTexCoord2d(1, 1); glVertex2f(p.getx() + b.getx() + ETSIDI::getTexture(path2).width / zoom, 
			p.gety() + b.gety() - ETSIDI::getTexture(path2).height / zoom);

		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
	}


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //Mediante estas dos lineas de codigo se activa el canal alpha

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(path).id);

	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor4f(1, 1, 1, 1);

	glTexCoord2d(0, 1); glVertex2f(p.getx() + a.getx() - ETSIDI::getTexture(path).width / zoom, 
		p.gety() + a.gety() - ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(0, 0); glVertex2f(p.getx() + a.getx() - ETSIDI::getTexture(path).width / zoom, 
		p.gety() + a.gety() + ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(1, 0); glVertex2f(p.getx() + a.getx() + ETSIDI::getTexture(path).width / zoom, 
		p.gety() + a.gety() + ETSIDI::getTexture(path).height / zoom);
	glTexCoord2d(1, 1); glVertex2f(p.getx() + a.getx() + ETSIDI::getTexture(path).width / zoom, 
		p.gety() + a.gety() - ETSIDI::getTexture(path).height / zoom);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}


float PersonajeNeutro::getRango() {
	return rango;
}


void PersonajeNeutro::setMovimientoale(float t=0, float y=0) {
	if (movale % 300 == 0) {
		this->setVelocidad(t, y);
	}
	if (movale % 300 != 0 && movale % 150 == 0) {
		this->setVelocidad(-t, -y);
	}

	movale++;
}

void PersonajeNeutro::Mueve(float t) {
	PersonajeNeutro::setMovimientoale();
	Personaje::Mueve(t);
}


void PersonajeNeutro::resetMovale() {
	movale = 0;
}