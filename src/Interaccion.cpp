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
				m.personajes[i]->Interacciona(p.getPosicion(), &p);
			}
		}
	}
}


bool Interaccion::Colision(Personaje* p, Disparo* d) {
	int margen = 15;

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

	for (int u = 0; u < mapa.numpers; u++) {
		if (Interaccion::Colision(mapa.personajes[u], m) == true) {
			mapa.personajes[u]->restarVida(m->daño);

			if (mapa.personajes[u]->vida <= 0) {
				mapa.agregarBonus(mapa.personajes[u]->getPosicion());
				ETSIDI::play("sounds/Moneda.mp3");
				mapa.eliminarPersonaje(u);
			}
		}
	}
}


bool Interaccion::AtaqueCercano(Personaje* p, Personaje* e) {
	int margen = 6; //margen de colision con otros personajes

	if (p->getPosicion()[e->getPosicion()] <= 2 * margen) {
		return 1;
	}
	else	return 0;
}

void Interaccion::AtaqueCercano(Personaje* p, Mapa& m) {
	for (int i = 0; i < m.numpers; i++) {
		if (Interaccion::AtaqueCercano(p, m.personajes[i])) {
			p->restarVida(0.5);
		}
	}
}


void Interaccion::setVelocidad(Personaje* p1, Personaje* p2) {
	if (p2->posicion.getx() > p1->posicion.getx()) {
		p2->setVelocidad(-20, p2->velocidad.gety());
	}
	else if (p2->posicion.getx() < p1->posicion.getx()) {
		p2->setVelocidad(20, p2->velocidad.gety());
	}
	else if (p2->posicion.getx() == p1->posicion.getx()) {
		p2->setVelocidad(0, p2->velocidad.gety());
	}
	if (p2->posicion.gety() > p1->posicion.gety()) {
		p2->setVelocidad(p2->velocidad.getx(), -20);
	}
	else if (p2->posicion.gety() < p1->posicion.gety()) {
		p2->setVelocidad(p2->velocidad.getx(), 20);
	}
	else if (p2->posicion.gety() == p1->posicion.gety()) {
		p2->setVelocidad(p2->velocidad.getx(), 0);
	}
}


void Interaccion::setVelocidad(Personaje* p1, Mapa& m) {
	for (int i = 0; i < m.numpers; i++) {
		Interaccion::setVelocidad(p1, m.personajes[i]);
	}

	for (int u = 0; u < m.numbon; u++) {
		if (Interaccion::Colision(p1, m.bonus[u])) {
			p1->sumaDinero();
			m.eliminarBonus(u);
		}
	}
}

void Interaccion::Colision(Mapa& mapa) {
	for (int i = 0; i < mapa.numpers; i++) {
		Interaccion::Colision(*mapa.personajes[i], mapa);
	}
}


bool Interaccion::Colision(Personaje* p, Bonus* b) {
	if (b->posicion[p->posicion] <= 10) {
		return 1;
	}
	else return 0;
}