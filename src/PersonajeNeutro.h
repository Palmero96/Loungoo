#pragma once
#include "Personaje.h"

class PersonajeNeutro : public Personaje {
private:
	float rango;		//Servirá para establecer el rango de actuación de los personajes neutros (Abrir menus, dialogos...)
	int movale;
public:
	PersonajeNeutro();
	PersonajeNeutro(float a, float b, float c, float d, const char* path, int xa, int xb);
	PersonajeNeutro(float a, float b, float c, float d, float r, const char* path, int xa, int xb);

	~PersonajeNeutro();

	//Funcion para interaccionar si se pulsa una tecla mientras se está en el rango;
	void Interacciona(Vector p);		
	float getRango();
	void setMovimientoale(float t, float y);
	virtual void Mueve(float t);

	void resetMovale();
	void restarVida(float a) { return; }
};

