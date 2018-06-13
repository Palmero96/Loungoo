#pragma once
#include "Personaje.h"
#include "Pixel.h"
#include "Mapa.h"



class Interaccion {

private:
    Vector protagonista;
	Vector enemigo;
public:
	static void Colision(Personaje& p, Pixel& pix);
	static void Colision(Personaje& p, Mapa& m);
	bool Ataque(Personaje& p, Disparo& d);
	bool Choque(Disparo& d, Pixel& pix);
	
	bool ataquecercano(Personaje& p, Personaje& e);

};

