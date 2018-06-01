#include "Vector.h"



Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(float a, float b) {
	x = a;
	x = b;
}


Vector::~Vector() {

}


void Vector::setxy(float a, float b) {
	x = a;
	y = b;
}

float Vector::getx() {
	return x;
}

float Vector::gety() {
	return y;
}

Vector Vector::operator * (float a) {
	Vector aux;
	aux.setxy(x * a, y * a);
	return aux;
}

Vector Vector::operator + (Vector a) {
	Vector aux;
	aux.setxy(x + a.getx(), y + a.gety());
	return aux;
}

Vector Vector::operator + (float a) {
	Vector aux;
	aux.setxy(x + a, y);
	return aux;
}