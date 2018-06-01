#include "Disparo.h"


Disparo::Disparo() {
	forma.setDimension(2, 4);
	forma.setCentro(posicion);
	forma.setColor(0, 255, 0);
	daño = 10;
	velocidad.setxy(0, vel);
	vel = 100;
}

Disparo::Disparo(float a, float b, float c) {
	forma.setDimension(a, b);
	forma.setCentro(posicion);
	forma.setColor(0, 255, 0);
	daño = c;
	velocidad.setxy(0, vel);
	vel = 100;
}

Disparo::Disparo(Vector a) {
	posicion = a;
	forma.setDimension(2, 4);
	forma.setCentro(posicion);
	forma.setColor(0, 255, 0);
	daño = 10;
	velocidad.setxy(0, vel);
	vel = 100;
}

Disparo::~Disparo() {

}

void Disparo::Dibuja() {
	forma.Dibuja();
}

void Disparo::Mueve(float t) {
	posicion = posicion + velocidad * t;
	forma.setCentro(posicion);
}

void Disparo::setPosicion(Vector a) {
	posicion = a;
}

void Disparo::setVelocidad(int a) {
	switch (a) {
	case 0: 
		velocidad.setxy(vel, 0);
		break;
	case 1:
		velocidad.setxy(0, vel);
		break;
	case 2:
		velocidad.setxy(-vel, 0);
		break;
	case 3:
		velocidad.setxy(0, -vel);
		break;
	}
}