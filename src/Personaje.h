#pragma once
#include "Prisma.h"
#include "Arma.h"

class Personaje {
protected:
	//Para comenzar vamos a definir personaje como un cuadrado
	Prisma forma;
	Vector posicion;
	Vector velocidad;
	float velocidad_modulo;

public:
	Personaje();
	Personaje(float a, float b, float c, float d);
	~Personaje();

	virtual void Dibuja();
	virtual void Mueve(float t);

	void setForma(float a, float b);
	virtual void setPosicion(float a, float b);
	void setVelocidad(float a, float b);

	float getPosicionx();
	float getPosiciony();
	
	void setVelocidad_modulo(float a);
	float getVelocidad_modulo();
};

