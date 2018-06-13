#include "Interaccion.h"
#include <cmath>



void Interaccion::Colision(Personaje& p, Pixel& pix) {
	int margen = 8;
	int margen2 = 8.5;

	if ((p.getPosicionx() + margen) >= pix.limitex1 && (p.getPosicionx() + margen) <= pix.limitex2
		&& (p.getPosiciony() >= pix.limitey1 && p.getPosiciony() <= pix.limitey2))
		p.setPosicion(pix.limitex1 - margen2, p.getPosiciony());

	else if ((p.getPosicionx() - margen) >= pix.limitex1 && (p.getPosicionx() - margen) <= pix.limitex2
		&& (p.getPosiciony() >= pix.limitey1 && p.getPosiciony() <= pix.limitey2))
		p.setPosicion(pix.limitex2 + margen2, p.getPosiciony());

	else if ((p.getPosicionx() >= pix.limitex1) && (p.getPosicionx() <= pix.limitex2)
		&& (p.getPosiciony() + margen >= pix.limitey1 && p.getPosiciony() + margen <= pix.limitey2))
		p.setPosicion(p.getPosicionx(), pix.limitey1 - margen2);

	else if ((p.getPosicionx() >= pix.limitex1) && (p.getPosicionx() <= pix.limitex2)
		&& (p.getPosiciony() - margen >= pix.limitey1 && p.getPosiciony() - margen <= pix.limitey2))
		p.setPosicion(p.getPosicionx(), pix.limitey2 + margen2);
}


void Interaccion::Colision(Personaje& p, Mapa& m) {
	for (int i = 0; i < m.numpixels; i++) {
		Interaccion::Colision(p, *m.pixColision[i]);
	}
}


void Interaccion::Interacc_Neutro(bool a, Personaje& p, Mapa& m, bool b) {
	for (int i = 0; i < m.numpers; i++) {
		if (a) {
			if (p.posicion[m.personajes[i]->getPosicion()] <= m.personajes[i]->getRango()) {
				//if (b) p.resetMovale();
				m.personajes[i]->Interacciona(p.getPosicion());
			}
		}
	}
}


bool Interaccion::Ataque(Personaje& p, Disparo& d) {
	int margen = 6;

	if ((d.posicion.getx() >= p.getPosicionx() - margen) && (d.posicion.getx() <= p.getPosicionx() + margen)
		&& (d.posicion.gety() >= p.getPosiciony() - margen) && (d.posicion.gety() <= p.getPosiciony() + margen))
		return 1;
	else
		return 0;
}


bool Interaccion::Colision(Disparo& d, Pixel& pix) {
	if ((d.posicion.getx() >= pix.limitex1) && (d.posicion.getx() <= pix.limitex2)
		&& (d.posicion.gety() >= pix.limitey1) && (d.posicion.gety() <= pix.limitey2))
		return 1;
	else
		return 0;
}





bool Interaccion::ataquecercano(Personaje& p, Personaje& e) {


	int margen = 7; //margen de colision con otros personajes

	Vector protagonista;
	Vector enemigo;
	protagonista = (p.getPosicion());
	enemigo = (e.getPosicion());


	if (protagonista[enemigo] < 2 * margen)
		return 1;
	else
		return 0;
}