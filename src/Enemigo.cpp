#include "Enemigo.h"


#include "Protagonista.h"




Enemigo::Enemigo(float a, float b, float c, float d, const char* path, int xa, int xb)
	: Personaje(a, b, c, d, path, xa, xb) {
	
}

void Enemigo::Dibuja() {
	Personaje::Dibuja();
}

void Enemigo::Mueve(float t, Personaje& p)
{
	if (p.getPosicionx() > posicion.getx())
		setVelocidad(0.7, 0);
	if (p.getPosicionx() < posicion.getx())
		setVelocidad(-0.7, 0);
	if (p.getPosiciony() < posicion.gety())
		setVelocidad(0, 0.7);
	if (p.getPosiciony() > posicion.gety())
        setVelocidad(0, -0.7);
	Personaje::Mueve(t);
	
}

bool Enemigo::Dispara(Personaje& p) {

	Vector aux;
	float ret;
	aux.setxy(p.getPosicionx()- posicion.getx(), p.getPosiciony()- posicion.gety());
	ret = sqrt(aux.getx() * aux.getx() + aux.gety()*aux.gety());
	return ret;


	if (ret<50)
		return 1;
	else 
		return 0;


}





void Enemigo::setPosicion(float a, float b) {
	Personaje::setPosicion(a, b);
}


Enemigo::Enemigo()
{
}


Enemigo::~Enemigo()
{
}
