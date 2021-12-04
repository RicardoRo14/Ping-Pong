#pragma once
#include<iostream>
#include"Caracter.h"
#include"Barra.h"
using namespace System;
using namespace std;
class Pelota :public Caracter {
private:
	int dx;
public:
	Pelota() {
		x = 9;//59
		y = 5;//14
		ancho = 3;
		alto = 2;
		dx = dy = 1;
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor(color);
		for (int i = 0; i < ancho; i++) {
			for (int j = 0; j < alto; j++) {
				Console::SetCursorPosition(x + i, y + j);
				cout << (char)219;
			}
		}
		Console::ResetColor();
	}
	void borrar() {
		for (int i = 0; i < ancho; i++) {
			for (int j = 0; j < alto; j++) {
				Console::SetCursorPosition(x + i, y + j);
				cout << " ";
			}
		}
	}
	void mover(vector<Barra*> barras,float &tiempo,int &choques) {
		borrar();
		if (x + dx < 0 || x + ancho + dx>120)dx *= -1;
		if (!Rectangle(x + dx, y, ancho, alto).IntersectsWith(barras[0]->getRectangle())) {
			if (!Rectangle(x + dx, y, ancho, alto).IntersectsWith(barras[1]->getRectangle())) {
				x += dx;
			}
			else {
				dx *= -1;
				x += dx;
				if (tiempo > 15) {
					tiempo -= 1;
				}
				choques++;
			}
		}
		else {
			dx *= -1;
			x += dx;
			if (tiempo > 15) {
				tiempo -= 1;
			}
			choques++;
		}
		if (y + dy< 5 || y + alto + dy>30)dy *= -1;
		if (!Rectangle(x, y+dy, ancho, alto).IntersectsWith(barras[0]->getRectangle())) {
			if (!Rectangle(x, y+dy, ancho, alto).IntersectsWith(barras[1]->getRectangle())) {
				y += dy;
			}
			else {
				dy *= -1;
				y += dy;
				if (tiempo > 15) {
					tiempo -= 1;
				}
				choques++;
			}
		}
		else {
			dy*= -1;
			y += dy;
			if (tiempo > 15) {
				tiempo -= 1;
			}
			choques++;
		}
		dibujar();
	}
	~Pelota() {}

};