#pragma once
#include "Mundo.h"
#include "Animaciones.h"


class Coordinador {
private:
	enum Estado{INICIO, JUEGO, PAUSA, GAMEOVER, FIN};

	Estado estado;
	Mundo mundo;

	Animaciones anima;
public:
	Coordinador();
	~Coordinador();

	void Dibuja();
	void DibujaTextura(const char* path, float zoom, Vector a);
	void Mueve();

	void TeclaEspecial(int key);
	void TeclaEspecialUp(int key);
	void Tecla(unsigned char key);
	void TeclaUp(unsigned char key);
};

