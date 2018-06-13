#include "Mapa.h"
#include <iostream>
#include <fstream>
using namespace std;



Mapa::Mapa(const char* mapa, const char* path1, const char* path2) {
	text1 = path1;
	text2 = path2;

	filM = 0;
	colM = 0;

	numpixels = 0;
	numpers = 0;

	ifstream archivo;
	string texto;

	archivo.open(mapa, ios::in);
	if (archivo.fail()) {
		exit(1);
	}

	archivo >> filM;
	archivo >> colM;
	matrizColision = new int*[filM];
	for (int i = 0; i < filM; i++) {
		matrizColision[i] = new int[colM];
	}

	while (!archivo.eof()) {
		for (int i = 0; i < filM; i++) {
			for (int j = 0; j < colM; j++) {
				archivo >> matrizColision[i][j];
				if (matrizColision[i][j] == 1) {
					numpixels++;
				}
			}
		}
	}

	archivo.close();

	pixColision = new Pixel*[numpixels];
	numpixels = 0;

	suelo[0] = new Suelo(text1, 4);
	suelo[1] = new Suelo(text2, 4.03);

	anchopixel = (suelo[0]->getAnchotext() / colM);
	altopixel = (suelo[0]->getAltotext() / filM);

	Mapa::setPixels();
}


Mapa::~Mapa() {
	for (int i = 0; i < numpers; i++) {
		delete personajes[i];
	}
	numpers = 0;

	delete suelo[1];
	delete suelo[2];

	for (int i = 0; i < numpixels; i++) {
		delete pixColision[i];
	}
	numpixels = 0;
}


void Mapa::Dibuja() {
	suelo[0]->Dibuja();

	for (int i = 0; i < numpers; i++) {
		personajes[i]->Dibuja();
	}
}

void Mapa::Dibuja2() {
	suelo[1]->Dibuja();

	/*for (int i = 0; i < numpixels; i++) {
		pixColision[i]->Dibuja();
	}*/
}


void Mapa::Mueve(float t) {
	for (int i = 0; i < numpers; i++) {
		personajes[i]->Mueve(t);
	}
}


void Mapa::setPixels() {
	for (int i = 0; i < colM; i++) {
		for (int u = 0; u < filM; u++) {
			if (matrizColision[u][i] == 1) {
				pixColision[numpixels++] = new Pixel(-(suelo[0]->getAnchotext()/2) + i*16, suelo[0]->getAltotext()/2 - 16 - u*16);
			}
		}
	}
}


bool Mapa::operator += (Personaje* p) {
	if (numpers < 10) {
		personajes[numpers++] = p;
		return true;
	}
	else return false;
}