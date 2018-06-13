#include "Interaccion.h"
#include "ETSIDI.h"
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


void Interaccion::Colision(Protagonista& p, Mapa&m) {
	Interaccion::Colision(&p.arma->municion, m);
	Personaje* aux = &p;
	Interaccion::Colision(*aux, m);
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


bool Interaccion::Colision(Personaje* p, Disparo* d) {
	int margen = 17;

	if (d->posicion[p->posicion] <= margen) {
		return true;
	}
	else return false;
}

bool Interaccion::Colision(Personaje* p, Municion* m) {
	for (int i = 0; i < m->contador; i++) {
		if (Interaccion::Colision(p, m->municion[i])) {
			m->eliminarDisparo(i);
			return true;
		}
		else return false;
	}
}


bool Interaccion::Colision(Disparo* d, Pixel* pix) {
	if ((d->posicion.getx() >= pix->limitex1) && (d->posicion.getx() <= pix->limitex2)
		&& (d->posicion.gety() >= pix->limitey1) && (d->posicion.gety() <= pix->limitey2))
		return 1;
	else
		return 0;
}


void Interaccion::Colision(Municion* m, Pixel* pix) {
	for (int i = 0; i < m->contador; i++) {
		if (Interaccion::Colision(m->municion[i], pix)) {
			m->eliminarDisparo(i);
		}
	}
}

void Interaccion::Colision(Municion *m, Mapa& mapa) {
	for (int i = 0; i < mapa.numpixels; i++) {
		Interaccion::Colision(m, mapa.pixColision[i]);
	}

	for (int i = 0; i < mapa.numpers; i++) {
		if (Interaccion::Colision(mapa.personajes[i], m) == true) {
			mapa.personajes[i]->restarVida(m->daño);

			if (mapa.personajes[i]->vida <= 0) {
				mapa.agregarBonus(mapa.personajes[i]->getPosicion());
				ETSIDI::play("sounds/Moneda.mp3");
				mapa.eliminarPersonaje(i);
			}
		}
	}
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