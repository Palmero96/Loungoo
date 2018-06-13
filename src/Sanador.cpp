#include "Sanador.h"



Sanador::Sanador() : PersonajeNeutro() {
}


Sanador::Sanador(float a, float b, float c, float d, const char* path, int xa, int xb) :
	PersonajeNeutro(a, b, c, d, path, xa, xb) {

}

Sanador::Sanador(float a, float b, float c, float d, float r, const char* path, int xa, int xb) :
	PersonajeNeutro(a, b, c, d, r, path, xa, xb) {

}


Sanador::~Sanador()
{
}


void Sanador::Curar(Protagonista& p){
	//p.resetVida();
}


void Sanador::Mueve(float t) {
	PersonajeNeutro::setMovimientoale(10, 0);
	Personaje::Mueve(t);
}