#pragma once
#include "Vector.h"
#include "Protagonista.h"
#include "Movimiento.h"

#define SPACEBAR 32


/*movimiento --->>> Vector de movimiento con el que se podrá hacer un movimiento 
  fluido actualizando  los estados inputs booleanas  para la creacion del vector
  Se usarán los inputs de movimiento 1 -> Derecha 
									 2 -> Arriba
									 3 -> Izquierda
									 4 -> Abajo
**Como extra se usara el input 5 para devolver el valor de disparo*/


class Mundo {
private:
	float zoom;
	Vector vista;
	Protagonista protagonista;
	Movimiento movimiento;	

public:
	void Inicializa();
	void Dibuja();
	void Mueve();
	void Interacciona();
	void Tecla(unsigned char key);
	void TeclaUp(unsigned char key);
	void TeclaEspecial(int key);
	void TeclaEspecialUp(int key);
};