#pragma once
#include <cmath>

class Vector {
private:
	float x;
	float y;

public:
	Vector();
	Vector(float a, float b);
	~Vector();

	void setxy(float a, float b);
	float getx();
	float gety();
	Vector operator * (float t);
	Vector operator + (Vector a);
	Vector operator + (float t);
	Vector operator - (Vector a);
	float operator[] (Vector a);
	Vector difUni (Vector a);
};