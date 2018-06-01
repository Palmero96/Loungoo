#pragma once
#include "Prisma.h"
#include "Municion.h"

class Arma {
private:
	Prisma forma;
	Municion municion;
	Vector posicion;

public:
	Arma();
	~Arma();

	void Dibuja();
	void Mueve(float t, Vector a);
	void Dispara(int a);
	void resetMunicion();
	void setPosicion(Vector a);
	int getAmmo();
	void setAngulo(float a);
};

