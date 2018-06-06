#pragma once
#include "Vector.h"

class Suelo {
private:
	float anchotext;
	float altotext;
	float zoom;

	Vector offset;

	const char* path;
public:
	Suelo(const char* a, float z);
	Suelo(const char* a, float b, float c, float z);
	~Suelo();

	float getAnchotext() { return anchotext; }
	float getAltotext() { return altotext; }

	void Dibuja();
};

