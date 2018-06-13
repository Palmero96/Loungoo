#include "Vendedor.h"


Vendedor::Vendedor() : PersonajeNeutro() {
}


Vendedor::Vendedor(float a, float b, float c, float d, const char* path, int xa, int xb) :
	PersonajeNeutro(a, b, c, d, path, xa, xb) {

}

Vendedor::Vendedor(float a, float b, float c, float d, float r, const char* path, int xa, int xb) :
	PersonajeNeutro(a, b, c, d, r, path, xa, xb) {

}


Vendedor::~Vendedor()
{
}


void Vendedor::mostrarArmas() {

}


void Vendedor::Mueve(float t) {
	PersonajeNeutro::setMovimientoale(0, -10);
	Personaje::Mueve(t);
}