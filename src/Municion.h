#pragma once
#include "Disparo.h"

#define AMMO 250

class Municion {
private:
	Disparo * municion[AMMO];
	int contador;

public:
	Municion();
	~Municion();

	int getContador();
	void setContador(int a);
	bool agregar(Disparo *d);
	void Dibuja();
	void Mueve(float t);
};