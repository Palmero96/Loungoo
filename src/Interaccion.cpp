#include "Interaccion.h"
#include <cmath>



void Interaccion::Colision(Personaje& p, Pixel& pix) {
	int margen = 8; //margen de colision con paredes
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
bool Interaccion::Ataque(Personaje& p, Disparo& d) {
	int margen = 6;

	if ((d.getPosicionx() >= p.getPosicionx() - margen) && (d.getPosicionx() <= p.getPosicionx() + margen)
		&& (d.getPosiciony() >= p.getPosiciony() - margen) && (d.getPosiciony() <= p.getPosiciony() + margen))
		return 1;
	else
		return 0;
}


bool Interaccion::Choque(Disparo& d, Pixel& pix) {

	if ((d.getPosicionx() >= pix.limitex1) && (d.getPosicionx() <= pix.limitex2)
		&& (d.getPosiciony() >= pix.limitey1) && (d.getPosiciony() <= pix.limitey2))
		return 1;
	else
		return 0;



}