#pragma once
#include "Suelo.h"
#include "Pixel.h"
#include "PersonajeNeutro.h"

class Mapa {
private:
	Suelo* suelo[2];
	int** matrizColision;
	Personaje* personajes[10];
	Pixel** pixColision;
	int numpixels;
	int numpers;

	int colM;
	int filM;

	const char* text1;
	const char* text2;

	float anchopixel, altopixel;

	friend class Interaccion;
public:
	Mapa(const char* mapa, const char* path1, const char* path2);
	~Mapa();

	void Dibuja();
	void Dibuja2();
	void Mueve(float t);
	void setPixels();

	bool operator += (Personaje* p);
};

