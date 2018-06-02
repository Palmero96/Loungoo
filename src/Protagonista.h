#pragma once
#include "Personaje.h"

class Protagonista : public Personaje {
private:
	Arma arma;
	float desfase;				//Cuan lejos se encuentra el arma del personaje
	int posicion_arma;			//La posicion del arma puede ser		0 --> derecha
								//										1 --> arriba
								//										2 --> izquierda
								//										3 --> abajo
	Vector vect_desfase;
public:
	Protagonista();
	Protagonista(float a, float b, float c, float d);
	~Protagonista();

	void Dibuja();
	void Mueve(float t);
	bool Dispara();

	void setPosicion(float a, float b);
	void setVect_desfase();
	void setPosicionArma(int a);
};

