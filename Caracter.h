#pragma once
using namespace System::Drawing;
class Caracter {
protected:
	int x, y;
	int dy;
	int ancho, alto;
	int color;
public:
	Caracter(){
		color = rand() % 15+1;
	}
	~Caracter(){}
	virtual void dibujar() = 0;
	virtual void borrar() = 0;
	
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};

//virtual void mover();