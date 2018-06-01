#include "Personaje.h"


Personaje::Personaje() {
	forma.setDimension(0, 0);
	posicion.setxy(0, 0);
	arma.setPosicion(posicion + vect_desfase);
	desfase = 16;
	posicion_arma = 0;
	velocidad_modulo = 0;
}

Personaje::Personaje(float a, float b, float c, float d) {
	forma.setDimension(a, b);
	posicion.setxy(c, d);
	arma.setPosicion(posicion + vect_desfase);
	desfase = 16;
	posicion_arma = 0;
	velocidad_modulo = 0;
}


Personaje::~Personaje() {
}

void Personaje::Dibuja() {
	arma.Dibuja();
	forma.Dibuja();
}

void Personaje::setForma(float a, float b) {
	forma.setDimension(a, b);
	forma.setCentro(posicion);
}

void Personaje::setPosicion(float a, float b) {
	posicion.setxy(a, b);
	forma.setCentro(posicion);
	arma.setPosicion(posicion + vect_desfase);
}

void Personaje::setVelocidad(float a, float b) {
	velocidad.setxy(a, b);
}

void Personaje::Mueve(float t) {
	posicion = velocidad * t + posicion;
	forma.setCentro(posicion); 
	arma.Mueve(t, posicion + vect_desfase);
}

bool Personaje::Dispara() {
	if (arma.getAmmo() > 0) {
		arma.Dispara(posicion_arma);
		return 1;
	}
	else return 0;
}

float Personaje::getPosicionx() {
	return posicion.getx();
}

float Personaje::getPosiciony() {
	return posicion.gety();
}

void Personaje::setVect_desfase() {
	switch (posicion_arma) {
	case 1:
		vect_desfase.setxy(desfase, 0);
		arma.setAngulo(0);
		break;
	case 2:
		vect_desfase.setxy(0, desfase);
		arma.setAngulo(90.0f);
		break;
	case 3:
		vect_desfase.setxy(-desfase, 0);
		arma.setAngulo(180.0f);
		break;
	case 0:
		vect_desfase.setxy(0, -desfase);
		arma.setAngulo(270.0f);
		break;
	}
}

void Personaje::setPosicionArma(int a){
	posicion_arma = a;
}

void Personaje::setVelocidad_modulo(float a) {
	velocidad_modulo = a;
}

float Personaje::getVelocidad_modulo() {
	return velocidad_modulo;
}