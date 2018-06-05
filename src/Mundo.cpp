#include "Mundo.h"
#include "glut.h"

void Mundo::Inicializa() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		//Establece el color de fondo como negro opaco
	glClear(GL_COLOR_BUFFER_BIT);				//Limpia el buffer del background

	zoom = 2;
	vista.setxy(0, 0);
	protagonista = new Protagonista(20, 20, 0, 0, "images/Protagonista.png", 3, 4);
	protagonista->setVelocidad_modulo(75);

	//Modificamos la linea mediante vista
	glOrtho((vista.getx() - 320) / zoom, (vista.getx() + 320) / zoom, (vista.gety() - 240) / zoom, (vista.gety() + 240) / zoom, -1, 1);
}

void Mundo::Dibuja() {
	protagonista->Dibuja();
}

void Mundo::Mueve() {
	Vector vel = movimiento.getMov_unitario();
	protagonista->setVelocidad(vel.getx() * protagonista->getVelocidad_modulo(), vel.gety() * protagonista->getVelocidad_modulo());
	protagonista->Mueve(0.015f);
}

void Mundo::Interacciona() {
	if (movimiento.disparo_on()) {
		protagonista->Dispara();
	}
}

void Mundo::Tecla(unsigned char key) {
	// crear una matriz -1 0 1 que se multiplica por velocidad
	
	switch (key) {

	case 'A':
	case 'a':
		movimiento.setInputs(3, true);
		protagonista->setPosicionArma(2);
		protagonista->setVect_desfase();
		break;

	case 'D':
	case 'd':
		movimiento.setInputs(1, true);
		protagonista->setPosicionArma(0);
		protagonista->setVect_desfase();
		break;

	case 'W':
	case 'w':
		movimiento.setInputs(2, true);
		protagonista->setPosicionArma(1);
		protagonista->setVect_desfase();
		break;

	case 'S':
	case 's':
		movimiento.setInputs(4, true);
		protagonista->setPosicionArma(3);
		protagonista->setVect_desfase();
		break;
	}
}

void Mundo::TeclaEspecial(int key) {
	switch (key) {
	case GLUT_KEY_UP:
		movimiento.setInputs(5, true);
		break;
	}
}

void Mundo::TeclaUp(unsigned char key) {
	// crear una matriz -1 0 1 que se multiplica por velocidad

	switch (key) {

	case 'A':
	case 'a':
		movimiento.setInputs(3, false);
		break;

	case 'D':
	case 'd':
		movimiento.setInputs(1, false);
		break;

	case 'W':
	case 'w':
		movimiento.setInputs(2, false);
		break;

	case 'S':
	case 's':
		movimiento.setInputs(4, false);
		break;
	}
}

void Mundo::TeclaEspecialUp(int key) {
	switch (key) {
	case GLUT_KEY_UP:
		movimiento.setInputs(5, false);
		break;
	}
}