#pragma once
#include "Personaje.h"
#include "Pixel.h"
#include "Mapa.h"
#include "Disparo.h"


class Interaccion {
public:
	static void Colision(Personaje& p, Pixel& pix);
	static void Colision(Personaje& p, Mapa& m);
	static void Interacc_Neutro(bool a, Personaje& p, Mapa& m, bool b);
	static bool Ataque(Personaje& p, Disparo& d);
	static bool Colision(Disparo& d, Pixel& pix);
	static bool ataquecercano(Personaje& p, Personaje& e);
	static void Colision(Municion& m, Pixel& pix);
};

