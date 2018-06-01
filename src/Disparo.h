#pragma once
#include "Prisma.h"

class Disparo {
private:
	Prisma forma;
	float da�o;
	Vector velocidad;
	Vector posicion;
	float vel;							//Valor modular del vector velocidad
public:
	Disparo();
	Disparo(float a, float b, float c);			//Para la posterior creaci�n de disparos de diferentes caracter�sticas (Dimensiones) y (Da�o)
	Disparo(Vector a);
	~Disparo();

	void Dibuja();
	void Mueve(float t);
	void setPosicion(Vector a);
	void setVelocidad(int a);			//Se ursar� de igual forma que el atributo "posicion_arma" de la clase "personaje"
};

