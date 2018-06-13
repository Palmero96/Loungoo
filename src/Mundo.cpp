#include "Mundo.h"
#include "glut.h"
#include "Interaccion.h"

void Mundo::Inicializa() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);		//Establece el color de fondo como negro opaco
	glClear(GL_COLOR_BUFFER_BIT);				//Limpia el buffer del background
	zoom = 2.2;

	myMap = MAPA1;

	if (myMap == MAPA1) {
		vista.setxy(0, 0);
		protagonista = new Protagonista(20, 20, 0, 0, "images/Protagonista.png", 3, 4);
		protagonista->setVelocidad_modulo(75);

		mapa = new Mapa("sources/Mapa1.txt", "images/Mapa1.png", "images/Mapa1_2.png");

		*mapa += new PersonajeNeutro(20, 20, 40, -40, "images/Misterioso.png", 3, 4);
		*mapa += new Sanador(20, 20, -140, -70, "images/Sanador.png", 3, 4);
		*mapa += new Vendedor(20, 20, 150, 10, "images/Vendedor.png", 3, 4);

		glOrtho((vista.getx() - 320) / zoom, (vista.getx() + 320) / zoom, (vista.gety() - 240) / zoom, (vista.gety() + 240) / zoom, -1, 1);
	}
}


Mundo::~Mundo() {
	delete mapa;
	delete protagonista;
}


void Mundo::Dibuja() {
	mapa->Dibuja();
	protagonista->Dibuja();
	mapa->Dibuja2();


	Interaccion::Interacc_Neutro(interaccion_personaje, *protagonista, *mapa, movimiento.getInteraccion());		
					//Se escribe aqui puesto que es una interaccion que realiza dibujos
}

void Mundo::Mueve() {
	Vector vel = movimiento.getMov_unitario();
	protagonista->setVelocidad(vel.getx() * protagonista->getVelocidad_modulo(), vel.gety() * protagonista->getVelocidad_modulo());
	protagonista->Mueve(0.015f);

	Mundo::Interacciona();
	Mundo::MueveCamara();

	mapa->Mueve(0.015f);

	if (myMap == MAPA1) {
		if (protagonista->getPosiciony() >= 120) {
			myMap = MAPA2;
			delete mapa;
			mapa = new Mapa("sources/Mapa2.txt", "images/Mapa2.png", "images/Mapa2_2.png");
			protagonista->setPosicion(0, -220);

			*mapa += new Enemigo(20, 20, -60, 30, "images/Mono1.png", 6, 4);
			*mapa += new Enemigo(20, 20, -40, 30, "images/Mono2.png", 6, 4);
			*mapa += new Enemigo(20, 20, 40, 30, "images/Mono1.png", 6, 4);
			*mapa += new Enemigo(20, 20, 0, 30, "images/Mono2.png", 6, 4);
			*mapa += new Enemigo(20, 20, -20, 30, "images/Mono1.png", 6, 4);
			*mapa += new Enemigo(20, 20, 80, 30, "images/Mono2.png", 6, 4);
		}
	}

	else if (myMap == MAPA2) {
		if (protagonista->getPosiciony() <= -240) {
			myMap = MAPA1;
			delete mapa;
			mapa = new Mapa("sources/Mapa1.txt", "images/Mapa1.png", "images/Mapa1_2.png");
			protagonista->setPosicion(0, 90);

			*mapa += new PersonajeNeutro(20, 20, 40, -40, "images/Misterioso.png", 3, 4);
			*mapa += new Sanador(20, 20, -100, -70, "images/Sanador.png", 3, 4);
			*mapa += new Vendedor(20, 20, 100, -50, "images/Vendedor.png", 3, 4);
		}
	}
}


void Mundo::MueveCamara() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	vista.setxy(protagonista->getPosicionx()*zoom, protagonista->getPosiciony()*zoom);

	glOrtho((vista.getx() - 320) / zoom, (vista.getx() + 320) / zoom, (vista.gety() - 240) / zoom, (vista.gety() + 240) / zoom, -1, 1);
}


Vector Mundo::getPosicionCamara() {
	Vector aux;
	aux.setxy(protagonista->getPosicionx(), protagonista->getPosiciony());
	return aux;
}


void Mundo::Interacciona() {

	if (movimiento.disparo_on()) {
		protagonista->Dispara();
	}

	Interaccion::Colision(*protagonista, *mapa);
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
	case 'O':
	case 'o':
		zoom = 2;
		break;
	case 'P':
	case 'p':
		zoom = 1;
		break;
	case 'e':
	case 'E':
		if (interaccion_personaje == false) {
			interaccion_personaje = true;
			movimiento.setInteraccion(true);
		}
		else if (interaccion_personaje == true) {
			interaccion_personaje = false;
		}
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
	case 'e':
	case 'E':
		movimiento.setInteraccion(false);
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