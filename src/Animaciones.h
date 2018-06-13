#pragma once
class Animaciones
{
private:
	int i;
public:
	Animaciones();
	~Animaciones();

	void DibujaAnimacion1();
	void DibujaAnimacion2();
	void DibujaAnimacion3();

	void DibujaTextura(const char* path);
	void resetValori();
};

