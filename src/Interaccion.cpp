#include "Interaccion.h"
#include <cmath>



void Interaccion::Colision(Personaje& p, Pixel& pix) {
	int margen = 8;
	int margen2 = 8.2;

	if	  ((p.getPosicionx() + margen) >= pix.limitex1 && (p.getPosicionx() + margen) <= pix.limitex2
		&& (p.getPosiciony() + margen) >= pix.limitey1 && (p.getPosiciony() + margen) <= pix.limitey2
		|| (p.getPosicionx() - margen) >= pix.limitex1 && (p.getPosicionx() - margen) <= pix.limitex2
		&& (p.getPosiciony() - margen) >= pix.limitey1 && (p.getPosiciony() - margen) <= pix.limitey2
		|| (p.getPosicionx() - margen) >= pix.limitex1 && (p.getPosicionx() - margen) <= pix.limitex2
		&& (p.getPosiciony() + margen) >= pix.limitey1 && (p.getPosiciony() + margen) <= pix.limitey2
		|| (p.getPosicionx() + margen) >= pix.limitex1 && (p.getPosicionx() + margen) <= pix.limitex2
		&& (p.getPosiciony() - margen) >= pix.limitey1 && (p.getPosiciony() - margen) <= pix.limitey2) {

		if (p.velocidad.getx() > 0) {
			p.setPosicion(pix.limitex1 - margen2, p.getPosiciony());
		}
		else if (p.velocidad.getx() < 0) {
			/*if (p.velocidad.gety() > 0) {
				p.setPosicion(pix.limitex2 + margen, p.getPosiciony());
			}
			else if (p.velocidad.gety() < 0) {
				p.setPosicion(pix.limitex2 + margen, p.getPosiciony());
			}
			else if (p.velocidad.gety() == 0) {
				p.setPosicion(pix.limitex2 + margen, p.getPosiciony());
			}*/
			p.setPosicion(pix.limitex2 + margen2, p.getPosiciony());
		}
		if (p.velocidad.gety() > 0 && p.velocidad.getx() == 0) {
			p.setPosicion(p.getPosicionx(), pix.limitey1 - margen2);
		}
	}
}


void Interaccion::Colision(Personaje& p, Mapa& m) {
	for (int i = 0; i < m.numpixels; i++) {
		Interaccion::Colision(p, *m.pixColision[i]);
	}
}