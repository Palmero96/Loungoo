#include "Personaje.h"


Personaje::Personaje() : sprite(0, 0, 0) {
	sprite.setCenter(1, 0);
	sprite.setSize(0, 0);

	forma.setDimension(0, 0);
	posicion.setxy(0, 0);
	velocidad_modulo = 0;
}

Personaje::Personaje(float a, float b, float c, float d, const char* path, int xa, int xb) : sprite(path, xa, xb) {
	sprite.setSize(a, b);
	sprite.setCenter(1, 0);

	forma.setDimension(a, b);
	posicion.setxy(c, d);
	velocidad_modulo = 0;
}


Personaje::~Personaje() {
}

void Personaje::Dibuja() {
	//forma.Dibuja();
	glPushMatrix();
	glTranslatef(posicion.getx(), posicion.gety(), 0);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (velocidad.getx() > 0.01) {
		sprite.setCenter(3, 0);
	}
	if (velocidad.getx() < -0.01) {
		sprite.setCenter(2, 0);
	}
	if (velocidad.gety() > 0.01) {
		sprite.setCenter(4, 0);
	}
	if (velocidad.gety() < -0.01) {
		sprite.setCenter(1, 0);
	}
	if (velocidad.getx() >= -0.01 && velocidad.getx() <= 0.01 && velocidad.gety() >= -0.01 && velocidad.gety() <= 0.01) {
		sprite.setState(0);
	}
	else if (sprite.getState() == 0) {
		sprite.setState(1, false);
	}

	sprite.draw();
	glPopMatrix();
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