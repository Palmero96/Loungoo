#pragma once
#include "ETSIDI.h"
#include "Vector.h"
using ETSIDI::Sprite;

class Bonus {
private:
	Vector posicion;

	Sprite sprite;

	friend class Interaccion;
public:
	~Bonus();
	Bonus(Vector pos);

	void Dibuja();
};