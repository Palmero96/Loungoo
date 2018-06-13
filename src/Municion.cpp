#include "Municion.h"



Municion::Municion() {
	daño = 5;
	int contador = 0;
	for (int i = 0; i < AMMO; i++) {
		municion[i] = 0;
	}
}

Municion::~Municion() {

}

int Municion::getContador() {
	return contador;
}

void Municion::setContador(int a) {
	contador = a;
}

bool Municion::agregar(Disparo *d) {
	if (contador < AMMO) {
		municion[contador++] = d;
	}

	else {
		return false;
	}

	return true;
}


void Municion::Dibuja() {
	for (int i = 0; i < contador; i++) {
		municion[i]->Dibuja();
	}
}


void Municion::Mueve(float t) {
	for (int i = 0; i < contador; i++) {
		municion[i]->Mueve(t);
	}
}


void Municion::eliminarDisparo(int index) {
	if ((index < 0) || (index >= contador)) {
		return;
	}
	delete municion[index];
	contador--;
	for (int i = index; i < contador; i++) {
		municion[i] = municion[i + 1];
	}
}