#pragma once
#include "Personaje.h"
#include "Mapa.h"


class Interaccion {
public:
	static void Colision(Personaje& p, Mapa& m);
};

