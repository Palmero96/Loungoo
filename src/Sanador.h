#pragma once
#include "PersonajeNeutro.h"
#include "Protagonista.h"


class Sanador : public PersonajeNeutro {
public:
	Sanador();
	Sanador(float a, float b, float c, float d, const char* path, int xa, int xb);
	Sanador(float a, float b, float c, float d, float r, const char* path, int xa, int xb);
	~Sanador();

	void Curar(Protagonista& p);

	void Mueve(float t);
};