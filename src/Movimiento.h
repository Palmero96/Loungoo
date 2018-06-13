#pragma once
#include "Vector.h"
#define numero_teclas	5

class Movimiento {
private:
	bool inputs[numero_teclas];
	bool interaccion;
	Vector mov_unitario;
public:
	Movimiento();
	~Movimiento();

	void setInputs(int a, bool b);
	Vector getMov_unitario();
	bool disparo_on();
	bool getInteraccion();
	void setInteraccion(bool a);
};