#include "Enemigo.h"


Enemigo::Enemigo() : Protagonista() {
	vida = 30;
}


Enemigo::Enemigo(float a, float b, float c, float d, const char* path, int xa, int xb, float hp)
	: Protagonista (a, b, c, d, path, xa, xb) {
	vida = hp;
}

Enemigo::~Enemigo() {

}

void Enemigo::Mueve(float t, Personaje& p)
{
	if (p.getPosicionx() > posicion.getx())
		setVelocidad(0.7, 0);
	if (p.getPosicionx() < posicion.getx())
		setVelocidad(-0.7, 0);
	if (p.getPosiciony() < posicion.gety())
		setVelocidad(0, 0.7);
	if (p.getPosiciony() > posicion.gety())
        setVelocidad(0, -0.7);
	Personaje::Mueve(t);
}

bool Enemigo::Dispara(Personaje& p) {
	float ret;
	ret = posicion[p.getPosicion()];

	if (ret < 50) {
		return 1;
	}
	else {
		return 0;
	}
}