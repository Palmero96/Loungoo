#pragma once

class Suelo {
private:
	char** colision;
public:
	Suelo();
	~Suelo();

	void Dibuja(float zoom, const char* a);
};

