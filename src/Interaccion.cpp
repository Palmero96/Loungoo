#include "Interaccion.h"
#include <cmath>



void Interaccion::Colision(Personaje& p, Mapa& m) {
	/*int x,  y;
	float auxx = m.suelo[0]->getAnchotext();
	float auxy = m.suelo[0]->getAltotext();									FALTA MEJORARLO E IMPLEMENTARLO PORQUE NO FUNCIONA

	x = trunc((p.getPosicionx() + auxx / 2) / m.anchopixel);
	y = trunc((p.getPosiciony() + auxy / 2) / m.altopixel);*/

	/*if (m.matrizColision[x][y] == 1) {
		p.velocidad.setxy(0, 0);
	}*/


	float distx = p.getPosicionx() + m.suelo[0]->getAnchotext();
	float disty = p.getPosiciony() + m.suelo[0]->getAltotext();

	int truncxr = trunc(distx / 8);
	int truncyr = trunc(disty / 8);
	int truncx1 = trunc((distx + 16) / 8);
	int truncy1 = trunc((disty + 16) / 8);
	int truncx2 = trunc((distx - 16) / 8);
	int truncy2 = trunc((disty - 16) / 8);

	if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncx1, truncyr]) {
		
		p.setPosicion((truncx1 - 1) * 8 - 16, p.getPosiciony());

		if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncx1, truncy1]) {
			p.setPosicion((truncx1 - 1) * 8 - 16, (truncy1 - 1) * 8 - 16);
		}
		else if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncx1, truncy2]) {
			p.setPosicion((truncx1 - 1) * 8 - 16, (truncy2 + 1) * 8 + 16);
		}
	}

	else if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncx2, truncyr]) {
		p.setPosicion((truncx2 + 1) * 8 + 16, p.getPosiciony());

		if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncx1, truncy1]) {
			p.setPosicion((truncx1 + 1) * 8 + 16, (truncy1 - 1) * 8 - 16);
		}
		else if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncx1, truncy2]) {
			p.setPosicion((truncx1 + 1) * 8 + 16, (truncy2 + 1) * 8 + 16);
		}
	}

	else if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncxr, truncy1]) {
		p.setPosicion(p.getPosicionx(), (truncy1 - 1) * 8 - 16);
	}

	else if (m.matrizColision[truncxr, truncyr] < m.matrizColision[truncxr, truncy2]) {
		p.setPosicion(p.getPosicionx(), (truncy1 + 1) * 8 + 16);
	}
}