#pragma once
#include "Vector.h"


class Pixel {
private:
	Vector esquina_infizquierda;
	Vector esquina_infderecha;
	Vector esquina_supizquierda;
	Vector esquina_supderecha;

	float limitex1;
	float limitex2;
	float limitey1;
	float limitey2;

	friend class Interaccion;
public:
	Pixel(float ancho, float alto);
	~Pixel();

	void Dibuja();
};

