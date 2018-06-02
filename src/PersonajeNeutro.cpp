#include "PersonajeNeutro.h"



PersonajeNeutro::PersonajeNeutro() : Personaje(){
	rango = 1.0f;
}


PersonajeNeutro::PersonajeNeutro(float a, float b, float c, float d) : Personaje(a, b, c, d){
	rango = 1.0f;
}


PersonajeNeutro::PersonajeNeutro(float a, float b, float c, float d, float r) : Personaje(a, b, c, d) {
	rango = r;
}


PersonajeNeutro::~PersonajeNeutro()
{
}
