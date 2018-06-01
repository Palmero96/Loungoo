#pragma once
#include "Prisma.h"
#include "Arma.h"

class Personaje {
private:
	//Para comenzar vamos a definir personaje como un cuadrado
	Prisma forma;
	Vector posicion;
	Vector velocidad;
	float velocidad_modulo;
	Arma arma;
	float desfase;				//Cuan lejos se encuentra el arma del personaje
	int posicion_arma;			//La posicion del arma puede ser		0 --> derecha
								//										1 --> arriba
								//										2 --> izquierda
								//										3 --> abajo
	Vector vect_desfase;

public:
	Personaje();
	Personaje(float a, float b, float c, float d);
	~Personaje();

	void Dibuja();
	void setForma(float a, float b);
	void setPosicion(float a, float b);
	void setVelocidad(float a, float b);
	void Mueve(float t);
	bool Dispara();
	float getPosicionx();
	float getPosiciony();
	void setVect_desfase();
	void setPosicionArma(int a);
	void setVelocidad_modulo(float a);
	float getVelocidad_modulo();
};

