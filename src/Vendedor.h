#pragma once
#include "PersonajeNeutro.h"


class Vendedor :
	public PersonajeNeutro
{
public:
	Vendedor();
	Vendedor(float a, float b, float c, float d, const char* path, int xa, int xb);
	Vendedor(float a, float b, float c, float d, float r, const char* path, int xa, int xb);
	~Vendedor();

	void mostrarArmas();

	void Mueve(float t);
	void Interacciona(Vector p, Personaje* p1);
	void Vender(Personaje* p);
};

