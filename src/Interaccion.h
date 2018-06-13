#pragma once
#include "Personaje.h"
#include "Pixel.h"
#include "Mapa.h"


class Interaccion {
public:
	static void Colision(Personaje& p, Pixel& pix);
	static void Colision(Personaje& p, Mapa& m);
	static void Interacc_Neutro(bool a, Personaje& p, Mapa& m, bool b);
};

