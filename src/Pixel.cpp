#include "Pixel.h"
#include "glut.h"


Pixel::Pixel(float esquinax, float esquinay) {
	esquina_infderecha.setxy(esquinax + 16, esquinay);
	esquina_infizquierda.setxy(esquinax, esquinay);
	esquina_supderecha.setxy(esquinax + 16, esquinay + 16);
	esquina_supizquierda.setxy(esquinax, esquinay + 16);

	limitex1 = esquinax;
	limitex2 = esquinax + 16;
	limitey1 = esquinay;
	limitey2 = esquinay + 16;
}


Pixel::~Pixel()
{
}


void Pixel::Dibuja() {
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glColor3f(255, 0, 0);
	glBegin(GL_QUADS);

	glTexCoord2f(0, 1);			glVertex2f(esquina_supderecha.getx(), esquina_supderecha.gety());
	glTexCoord2f(0, 0);			glVertex2f(esquina_infderecha.getx(), esquina_infderecha.gety());
	glTexCoord2f(1, 0);			glVertex2f(esquina_infizquierda.getx(), esquina_infizquierda.gety());
	glTexCoord2f(1, 1);			glVertex2f(esquina_supizquierda.getx(), esquina_supizquierda.gety());

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
