#include "Prisma.h"
#include "glut.h"


Prisma::Prisma() {
	dimension.setxy(0, 0);
	centro.setxy(0, 0);
	angulo = 0;

	red = 255.0;
	green = 255.0;
	blue = 0.0;
}

Prisma::~Prisma()
{
}

void Prisma::Dibuja() {
	//glRotatef(angulo, 0.0f, 0.0f, 1.0f);				//PROBLEMA AL DIBUJAR
	glTranslatef(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glColor3ub(red, green, blue);
		glVertex2f(centro.getx() - dimension.getx() / 2, centro.gety() - dimension.gety() / 2);
		glVertex2f(centro.getx() - dimension.getx() / 2, centro.gety() + dimension.gety() / 2);
		glVertex2f(centro.getx() + dimension.getx() / 2, centro.gety() + dimension.gety() / 2);
		glVertex2f(centro.getx() + dimension.getx() / 2, centro.gety() - dimension.gety() / 2);
	glEnd();
}

void Prisma::setDimension(float a, float b) {
	dimension.setxy(a, b);
}

void Prisma::setCentro(Vector a) {
	centro = a;
}

void Prisma::setCentro(float a, float b) {
	centro.setxy(a, b);
}

void Prisma::setColor(unsigned char a, unsigned char b, unsigned char c) {
	red = a;
	green = b;
	blue = c;
}

float Prisma::getAngulo() {
	return angulo;
}

void Prisma::setAngulo(float a) {
	angulo = a;
}