#include "Personaje.h"


Personaje::Personaje() {
	forma.setDimension(0, 0);
	posicion.setxy(0, 0);
	velocidad_modulo = 0;
}

Personaje::Personaje(float a, float b, float c, float d) {
	forma.setDimension(a, b);
	posicion.setxy(c, d);
	velocidad_modulo = 0;
}


Personaje::~Personaje() {
}

void Personaje::Dibuja() {
	forma.Dibuja();
}

void Personaje::setForma(float a, float b) {
	forma.setDimension(a, b);
	forma.setCentro(posicion);
}

void Personaje::setPosicion(float a, float b) {
	posicion.setxy(a, b);
	forma.setCentro(posicion);
}

void Personaje::setVelocidad(float a, float b) {
	velocidad.setxy(a, b);
}

void Personaje::Mueve(float t) {
	posicion = velocidad * t + posicion;
	forma.setCentro(posicion); 
}

float Personaje::getPosicionx() {
	return posicion.getx();
}

float Personaje::getPosiciony() {
	return posicion.gety();
}


void Personaje::setVelocidad_modulo(float a) {
	velocidad_modulo = a;
}

float Personaje::getVelocidad_modulo() {
	return velocidad_modulo;
}