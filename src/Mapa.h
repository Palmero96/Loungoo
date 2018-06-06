#pragma once
#include "Suelo.h"
#include "PersonajeNeutro.h"


class Mapa {
private:
	Suelo suelo;
	PersonajeNeutro* personajes[10];
public:
	Mapa();
	~Mapa();

	void Dibuja();
	void Dibuja2();
};

