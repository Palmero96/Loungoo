#include "PersonajeNeutro.h"



PersonajeNeutro::PersonajeNeutro() : Personaje(){
	rango = 1.0f;
}


PersonajeNeutro::PersonajeNeutro(float a, float b, float c, float d, const char* path, int xa, int xb)
: Personaje(a, b, c, d, path, xa, xb){
	rango = 1.0f;
}


PersonajeNeutro::PersonajeNeutro(float a, float b, float c, float d, float r, const char* path, int xa, int xb)
: Personaje(a, b, c, d, path, xa, xb) {
	rango = r;
}


PersonajeNeutro::~PersonajeNeutro() {

}
