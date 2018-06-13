#include "Disparo.h"


Disparo::Disparo() : sprite(0, 0, 0){

	sprite.setSize(0, 0);
	sprite.setCenter(0, 0);
	velocidad.setxy(0, vel);
	vel = 100;
}

Disparo::Disparo(float a, const char* path) : sprite(path, 4, 1, 20){
	sprite.setCenter(1, 4.5/2);
	sprite.setSize(a, 2.38*a);
	velocidad.setxy(0, vel);
	vel = 100;
}

Disparo::Disparo(Vector a, const char* path) : sprite(path, 4, 1, 20){
	sprite.setCenter(1, 4.5 / 2);
	sprite.setSize(6*2.38, 6);

	posicion = a;

	velocidad.setxy(0, vel);
	vel = 100;
}

Disparo::~Disparo() {

}

void Disparo::Dibuja() {

	glPushMatrix();
	glTranslatef(posicion.getx(), posicion.gety(), 0);
	glColor3f(1.0f, 1.0f, 1.0f);

	if (velocidad.getx() > 0)							sprite.setAngle(0);
	if (velocidad.gety() > 0 && velocidad.getx() > 0)	sprite.setAngle(45);
	if (velocidad.gety() > 0 && velocidad.getx() == 0)	sprite.setAngle(90);
	if (velocidad.gety() > 0 && velocidad.getx() < 0)	sprite.setAngle(135);
	if (velocidad.getx() < 0)							sprite.setAngle(180);
	if (velocidad.gety() < 0 && velocidad.getx() < 0)	sprite.setAngle(225);
	if (velocidad.gety() < 0 && velocidad.getx() == 0)	sprite.setAngle(270);
	if (velocidad.gety() < 0 && velocidad.getx() > 0)	sprite.setAngle(315);

	if (sprite.getState() == 3)	sprite.setState(3);

	sprite.draw();
	glPopMatrix();
}

void Disparo::Mueve(float t) {
	sprite.loop();
	posicion = posicion + velocidad * t;
}

void Disparo::setPosicion(Vector a) {
	posicion = a;
}

void Disparo::setVelocidad(int a) {
	switch (a) {
	case 0: 
		velocidad.setxy(vel, 0);
		break;
	case 1:
		velocidad.setxy(0, vel);
		break;
	case 2:
		velocidad.setxy(-vel, 0);
		break;
	case 3:
		velocidad.setxy(0, -vel);
		break;
	}
}