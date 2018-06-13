#pragma once
#include "Protagonista.h"

class Enemigo : public Protagonista{

	
public:
	Enemigo();
	Enemigo(float a, float b, float c, float d, const char* path, int xa, int xb, float hp);
	~Enemigo();

	bool Dispara(Personaje& p);
};

