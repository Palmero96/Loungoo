#include "Vector.h"



Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(float a, float b) {
	x = a;
	y = b;
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

Vector Vector::operator - (Vector a) {
	Vector aux;
	aux.setxy(x - a.getx(), y - a.gety());
	return aux;
}

Vector Vector::operator + (float a) {
	Vector aux;
	aux.setxy(x + a, y);
	return aux;
}

float Vector::operator[] (Vector a) {
	float ret;
	Vector aux;
	aux.setxy(x - a.getx(), y - a.gety());
	ret = sqrt(aux.getx() * aux.getx() + aux.gety()*aux.gety());
	return ret;
}

Vector Vector::difUni (Vector a) {
	Vector aux;
	aux.setxy(a.getx() - x, a.gety() - y);
	aux.setxy(aux.getx() / ((*this)[a]), aux.gety() / ((*this)[a]));
	return aux;
}