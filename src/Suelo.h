#pragma once
#include "Vector.h"

class Suelo {
private:
	float anchotext;
	float altotext;

	Vector offset;

	const char* path;
public:
	Suelo(const char* a);
	Suelo(const char* a, float b, float c);
	~Suelo();

	float getAnchotext() { return anchotext; }
	float getAltotext() { return altotext; }

	void Dibuja(float zoom);
};

