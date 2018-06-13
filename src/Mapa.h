#pragma once
#include "Suelo.h"
#include "Pixel.h"
#include "PersonajeNeutro.h"
#include "Bonus.h"

class Mapa {
private:
	Suelo* suelo[2];
	int** matrizColision;
	Personaje* personajes[10];
	Bonus* bonus[10];
	Pixel** pixColision;
	int numpixels;
	int numpers;
	int numbon;

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

	void eliminarPersonaje(int index);
	bool agregarBonus(Vector a);
	void eliminarBonus(int index);

	int getNumPer() { return numpers; }
};

