#pragma once
#include "Vector.h"

class Prisma {
private:
	Vector dimension;
	Vector centro;
	float angulo;

	unsigned char red;
	unsigned char green;
	unsigned char blue;
public:
	Prisma();
	~Prisma();

	void Dibuja();
	void setDimension(float a, float b);
	void setCentro(Vector a);
	void setCentro(float a, float b);
	void setColor(unsigned char a, unsigned char b, unsigned char c);
	float getAngulo();
	void setAngulo(float a);
};

