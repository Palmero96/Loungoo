#include "Mapa.h"
#include <iostream>
#include <fstream>
using namespace std;



Mapa::Mapa(const char* mapa, const char* path1, const char* path2) {
	text1 = path1;
	text2 = path2;

	filM = 0;
	colM = 0;

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
			}
		}
	}

	archivo.close();

	suelo[0] = new Suelo(text1, 4);
	suelo[1] = new Suelo(text2, 4.03);

	anchopixel = (suelo[0]->getAnchotext() / colM);
	altopixel = (suelo[0]->getAltotext() / filM);
}



Mapa::~Mapa() {
}

void Mapa::Dibuja() {
	suelo[0]->Dibuja();
}

void Mapa::Dibuja2() {
	suelo[1]->Dibuja();
}