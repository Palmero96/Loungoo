#include "Movimiento.h"


Movimiento::Movimiento() {
	for (int i = 0; i <= numero_teclas; i++) {
		inputs[i] = 0;
	}

	mov_unitario.setxy(0, 0);
}


Movimiento::~Movimiento() {

}


void Movimiento::setInputs(int a, bool b) {
	inputs[a] = b;
}

Vector Movimiento::getMov_unitario() {
	if (inputs[1]) {
		mov_unitario.setxy(mov_unitario.getx() + 1, mov_unitario.gety());
	}

	if (inputs[2]) {
		mov_unitario.setxy(mov_unitario.getx(), mov_unitario.gety() + 1);
	}

	if (inputs[3]) {
		mov_unitario.setxy(mov_unitario.getx() - 1, mov_unitario.gety());
	}

	if (inputs[4]) {
		mov_unitario.setxy(mov_unitario.getx(), mov_unitario.gety() - 1);
	}

	if (!inputs[1] && !inputs[3]) {
		mov_unitario.setxy(0, mov_unitario.gety());
	}

	if (!inputs[2] && !inputs[4]) {
		mov_unitario.setxy(mov_unitario.getx(), 0);
	}

	if (mov_unitario.getx() > 1) mov_unitario.setxy(1, mov_unitario.gety());
	else if (mov_unitario.getx() < -1) mov_unitario.setxy(-1, mov_unitario.gety());
	if (mov_unitario.gety() > 1) mov_unitario.setxy(mov_unitario.getx(), 1);
	else if (mov_unitario.gety() < -1) mov_unitario.setxy(mov_unitario.getx(), -1);

	return mov_unitario;
}

bool Movimiento::disparo_on() {
	if (inputs[5]) {
		return true;
	}
	return false;
}

bool Movimiento::getInteraccion() {
	return interaccion;
}

void Movimiento::setInteraccion(bool a) {
	interaccion = a;
}