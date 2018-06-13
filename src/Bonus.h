#pragma once
#include "ETSIDI.h"
#include "Vector.h"
using ETSIDI::Sprite;

class Bonus {
private:
	Vector posicion;

	Sprite sprite;
public:
	~Bonus();
	Bonus(Vector pos);

	void Dibuja();
};