#pragma once
#include "ETSIDI.h"
#include "Municion.h"
#include "Vector.h"

using ETSIDI::Sprite;

class Arma {
private:
	Municion municion;
	Vector posicion;

	bool orientacionx, orientaciony;

	Sprite sprite;

	friend class Interaccion;
public:
	Arma();
	Arma(const char* a);
	~Arma();

	void Dibuja(int pos);
	void Mueve(float t, Vector a);
	void Dispara(int a);
	void resetMunicion();
	void setPosicion(Vector a);
	int getAmmo();
	void setAngulo(float a);

	void aumentaDmg() { municion.aumentaDmg(); }
	void setSize(float a, float b);
};

