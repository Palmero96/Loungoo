#include "Mapa.h"



Mapa::Mapa() {
}

Mapa::~Mapa() {
}

void Mapa::Dibuja() {
	suelo.Dibuja(4, "images/Mapa1.png");
}

void Mapa::Dibuja2() {
	suelo.Dibuja(4.03, "images/Mapa1_2.png");
}