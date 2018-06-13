#include "Sanador.h"



Sanador::Sanador() : PersonajeNeutro() {
}


Sanador::Sanador(float a, float b, float c, float d, const char* path, int xa, int xb) :
	PersonajeNeutro(a, b, c, d, path, xa, xb) {

}

Sanador::Sanador(float a, float b, float c, float d, float r, const char* path, int xa, int xb) :
	PersonajeNeutro(a, b, c, d, r, path, xa, xb) {

}


Sanador::~Sanador()
{
}


void Sanador::Curar(Personaje* p){
	p->resetVida();
}


void Sanador::Mueve(float t) {
	PersonajeNeutro::setMovimientoale(10, 0);
	Personaje::Mueve(t);
}


void Sanador::Interacciona(Vector p, Personaje* p1) {
	const char* path2 = "images/Conversacion_2.png";
	Vector b(0, 0);
	float zoom = 6;

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

	Sanador::Curar(p1);
}