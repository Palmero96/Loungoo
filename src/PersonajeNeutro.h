#pragma once
#include "Personaje.h"

class PersonajeNeutro : public Personaje {
private:
	float rango;		//Servirá para establecer el rango de actuación de los personajes neutros (Abrir menus, dialogos...)
public:
	PersonajeNeutro();
	PersonajeNeutro(float a, float b, float c, float d);
	PersonajeNeutro(float a, float b, float c, float d, float r);
	~PersonajeNeutro();
};

