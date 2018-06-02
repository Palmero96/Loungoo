#pragma once
#include "Personaje.h"

class PersonajeNeutro : public Personaje {
private:
	float rango;		//Servir� para establecer el rango de actuaci�n de los personajes neutros (Abrir menus, dialogos...)
public:
	PersonajeNeutro();
	PersonajeNeutro(float a, float b, float c, float d);
	PersonajeNeutro(float a, float b, float c, float d, float r);
	~PersonajeNeutro();
};

