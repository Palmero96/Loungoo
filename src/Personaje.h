#pragma once
#include "ETSIDI.h"
#include "Arma.h"

using ETSIDI::SpriteSequence;

class Personaje {
protected:
	Vector posicion;
	Vector velocidad;
	float velocidad_modulo;

	SpriteSequence sprite;

public:
	Personaje();
	Personaje(float a, float b, float c, float d, const char* path, int xa, int xb);
	~Personaje();

	virtual void Dibuja();
	virtual void Mueve(float t);

	virtual void setPosicion(float a, float b);
	void setVelocidad(float a, float b);
	
	Vector getPosicion() { return posicion; }
	float getPosicionx();
	float getPosiciony();
	
	void setVelocidad_modulo(float a);
	float getVelocidad_modulo();
};

