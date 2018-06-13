#pragma once
#include "ETSIDI.h"
#include "Arma.h"

using ETSIDI::SpriteSequence;

class Personaje {
protected:
	float vida;
	int dinero;

	Vector posicion;
	Vector velocidad;
	float velocidad_modulo;

	SpriteSequence sprite;

	friend class Interaccion;
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

	virtual float getRango() { return 0; }
	virtual void Interacciona(Vector p, Personaje* p1) {}
	virtual bool Dispara() { return false; }

	virtual void restarVida(float daño) { vida = 1; }
	float getVida() { return vida; }
	virtual void resetVida() {}

	void sumaDinero() { dinero++; }
	float getDinero() { return dinero; }

	virtual void setArma(const char* a){}
	virtual void aumentaDmg() {}
	virtual void setArmaSize(float a, float b){}
};

