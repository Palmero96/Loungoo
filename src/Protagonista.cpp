#include "Protagonista.h"



Protagonista::Protagonista() : Personaje() {
	setArma("images/Arma1.png");
	arma->setPosicion(posicion + vect_desfase);
	desfase = 10;
	posicion_arma = 0;
}

Protagonista::Protagonista(float a, float b, float c, float d, const char* path, int xa, int xb) 
: Personaje(a, b, c, d, path, xa, xb) {
	setArma("images/Arma1.png");
	arma->setPosicion(posicion + vect_desfase);
	desfase = 10;
	posicion_arma = 0;
}

Protagonista::~Protagonista()
{
}

void Protagonista::Dibuja() {
	Personaje::Dibuja();
	arma->Dibuja(posicion_arma);
}

void Protagonista::Mueve(float t) {
	Personaje::Mueve(t);
	arma->Mueve(t, posicion + vect_desfase);
}


void Protagonista::setPosicion(float a, float b) {
	Personaje::setPosicion(a, b);
	arma->setPosicion(posicion + vect_desfase);
}


bool Protagonista::Dispara() {
	if (arma->getAmmo() > 0) {
		arma->Dispara(posicion_arma);
		return 1;
	}
	else return 0;
}


void Protagonista::setVect_desfase() {
	switch (posicion_arma) {
	case 1:
		vect_desfase.setxy(desfase, 0);
		arma->setAngulo(90.0f);
		break;
	case 2:
		vect_desfase.setxy(0, desfase);
		arma->setAngulo(180.0f);
		break;
	case 3:
		vect_desfase.setxy(-desfase, 0);
		arma->setAngulo(270.0f);
		break;
	case 0:
		vect_desfase.setxy(0, -desfase);
		arma->setAngulo(0.0f);
		break;
	}
}

void Protagonista::setPosicionArma(int a) {
	posicion_arma = a;
}

void Protagonista::setArma(const char* a) {
	arma = new Arma(a);
}