#include "Personaje.h"


Personaje::Personaje() : sprite(0, 0, 0) {
	sprite.setCenter(0, 0);
	sprite.setSize(0, 0);

	posicion.setxy(0, 0);
	velocidad_modulo = 0;
}

Personaje::Personaje(float a, float b, float c, float d, const char* path, int xa, int xb) : sprite(path, xa, xb) {
	sprite.setSize(a, b);
	sprite.setCenter(a/2, b/2);

	posicion.setxy(c, d);
	velocidad_modulo = 0;
}


Personaje::~Personaje() {
}

void Personaje::Dibuja() {

	glPushMatrix();
	glTranslatef(posicion.getx(), posicion.gety(), 0);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (velocidad.getx() > 0.01 ) {
		if (sprite.getState() < 6 || sprite.getState() >= 9)		sprite.setState(6, false);
	}
	if (velocidad.getx() < -0.01) {
		if (sprite.getState() < 3 || sprite.getState() >= 6)		sprite.setState(3, false);
	}
	if (velocidad.gety() > 0.01 && velocidad.getx() == 0) {
		if (sprite.getState() < 9)		sprite.setState(9, false);
	}
	if (velocidad.gety() < -0.01 && velocidad.getx() == 0) {
		if (sprite.getState() >= 3) 	sprite.setState(0, false);
	}
	if (velocidad.getx() >= -0.01 && velocidad.getx() <= 0.01 && velocidad.gety() >= -0.01 && velocidad.gety() <= 0.01) {
		sprite.setState(1, false);
	}

	sprite.draw();
	glPopMatrix();
}

void Personaje::setPosicion(float a, float b) {
	posicion.setxy(a, b);
}

void Personaje::setVelocidad(float a, float b) {
	velocidad.setxy(a, b);
}

void Personaje::Mueve(float t) {
	posicion = velocidad * t + posicion;
	sprite.loop();
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