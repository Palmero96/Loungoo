#pragma once
#include "ETSIDI.h"
#include "Vector.h"

using ETSIDI::SpriteSequence;

class Disparo {
private:
	float daño;
	Vector velocidad;
	Vector posicion;
	float vel;							//Valor modular del vector velocidad

	SpriteSequence sprite;

	friend class Interaccion;
public:
	Disparo();
	Disparo(float a, float c, const char* path);			//Para la posterior creación de disparos de diferentes características (Dimensiones) y (Daño)
	Disparo(Vector a, const char* path);
	~Disparo();

	void Dibuja();
	void Mueve(float t);
	void setPosicion(Vector a);
	void setVelocidad(int a);			//Se ursará de igual forma que el atributo "posicion_arma" de la clase "personaje"
};

