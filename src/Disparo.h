#pragma once
#include "Prisma.h"

class Disparo {
private:
	Prisma forma;
	float daño;
	Vector velocidad;
	Vector posicion;
	float vel;							//Valor modular del vector velocidad
public:
	Disparo();
	Disparo(float a, float b, float c);			//Para la posterior creación de disparos de diferentes características (Dimensiones) y (Daño)
	Disparo(Vector a);
	~Disparo();

	void Dibuja();
	void Mueve(float t);
	void setPosicion(Vector a);
	void setVelocidad(int a);			//Se ursará de igual forma que el atributo "posicion_arma" de la clase "personaje"
};

