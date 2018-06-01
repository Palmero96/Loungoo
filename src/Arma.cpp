#include "Arma.h"


Arma::Arma() {
	forma.setDimension(5, 10);
	forma.setCentro(posicion);
	municion.setContador(0);

	forma.setColor(255, 0, 0);
}

Arma::~Arma() {

}

void Arma::Dibuja() {
	forma.Dibuja();
	municion.Dibuja();
}

void Arma::Mueve(float t, Vector a) {
	posicion = a; 
	forma.setCentro(posicion);
	municion.Mueve(t);
}

void Arma::resetMunicion() {
	municion.setContador(0);
}

void Arma::setPosicion(Vector a) {
	posicion = a;
	forma.setCentro(posicion);
}

int Arma::getAmmo() {
	int result;
	result = AMMO - municion.getContador();
	return result;
}

void Arma::Dispara(int a) {
	Disparo* aux = new Disparo(posicion);
	aux->setVelocidad(a);
	municion.agregar(aux);
}

void Arma::setAngulo(float a) {
	forma.setAngulo(a);
}