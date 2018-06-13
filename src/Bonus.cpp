#include "Bonus.h"



Bonus::Bonus(Vector pos) : sprite("images/Moneda.png") {
 posicion = pos;

 sprite.setSize(7, 7);
 sprite.setCenter(pos.getx() , pos.gety());
}


Bonus::~Bonus() {
 
}


void Bonus::Dibuja() {
 glPushMatrix();
 glTranslatef(posicion.getx(), posicion.gety(), 0); 
 glColor3f(1.0f, 1.0f, 1.0f);

 sprite.draw();
 glPopMatrix();

}