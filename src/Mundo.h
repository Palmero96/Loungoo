#pragma once
#include "Vector.h"
#include "Protagonista.h"
#include "Sanador.h"
#include "Vendedor.h"
#include "Movimiento.h"
#include "Mapa.h"

#define SPACEBAR 32


/*movimiento --->>> Vector de movimiento con el que se podr� hacer un movimiento 
  fluido actualizando  los estados inputs booleanas  para la creacion del vector
  Se usar�n los inputs de movimiento 1 -> Derecha 
									 2 -> Arriba
									 3 -> Izquierda
									 4 -> Abajo
**Como extra se usara el input 5 para devolver el valor de disparo*/


class Mundo {
private:
	enum map { MAPA1, MAPA2 };

	map myMap;
	float zoom;
	Vector vista;
	Protagonista* protagonista;
	Movimiento movimiento;	
	Mapa* mapa;

	int interaccion_personaje;
public:
	~Mundo();

	void Inicializa();
	void Dibuja();
	void Mueve();
	void MueveCamara();
	Vector getPosicionCamara();
	void Interacciona();
	void Tecla(unsigned char key);
	void TeclaUp(unsigned char key);
	void TeclaEspecial(int key);
	void TeclaEspecialUp(int key);
};