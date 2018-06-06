#include "Interaccion.h"
#include <cmath>



void Interaccion::Colision(Personaje& p, Mapa& m) {
	/*int x,  y;
	float auxx = m.suelo[0]->getAnchotext();
	float auxy = m.suelo[0]->getAltotext();									FALTA MEJORARLO E IMPLEMENTARLO PORQUE NO FUNCIONA

	x = trunc((p.getPosicionx() + auxx / 2) / m.anchopixel);
	y = trunc((p.getPosiciony() + auxy / 2) / m.altopixel);*/

	if (m.matrizColision[x][y] == 1) {
		p.velocidad.setxy(0, 0);
	}
}