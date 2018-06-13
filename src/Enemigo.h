#pragma once
#include "Personaje.h"

class Enemigo : public Personaje{

	
public:
	Enemigo();
    Enemigo(float a, float b, float c, float d, const char* path, int xa, int xb);
	~Enemigo();

	void Dibuja();
	void Mueve(float t, Personaje& p);
	bool Dispara(Personaje& p);

	void setPosicion(float a, float b);
	
};

