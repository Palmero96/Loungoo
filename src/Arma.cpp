#include "Arma.h"


Arma::Arma() : sprite(0, 0, 0) {
	sprite.setSize(5, 5);
	sprite.setCenter(posicion.getx(), posicion.gety());

	municion.setContador(0);
}

Arma::Arma(const char* path) : sprite(path) {
	sprite.setSize(7, 7);
	sprite.setCenter(posicion.getx(), posicion.gety());

	municion.setContador(0);
}

Arma::~Arma() {

}

void Arma::Dibuja(int pos) {
	
	glPushMatrix();
	glTranslatef(posicion.getx(), posicion.gety(), 0);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (pos == 0)	sprite.flip(false, false);
	if (pos == 1)	sprite.flip(true, false);
	if (pos == 2)	sprite.flip(false, true);
	if (pos == 3)	sprite.flip(true, false);


	sprite.draw();
	glPopMatrix();

	municion.Dibuja();
}

void Arma::Mueve(float t, Vector a) {
	posicion.setxy(a.getx(), a.gety() - 3.5f);
	municion.Mueve(t);
}

void Arma::resetMunicion() {
	municion.setContador(0);
}

void Arma::setPosicion(Vector a) {
	posicion = a;
}

int Arma::getAmmo() {
	int result;
	result = AMMO - municion.getContador();
	return result;
}

void Arma::Dispara(int a) {
	Disparo* aux = new Disparo(posicion, "images/Disparo1.png");
	aux->setVelocidad(a);
	municion.agregar(aux);
}

void Arma::setAngulo(float a) {
	sprite.setAngle(a);
}