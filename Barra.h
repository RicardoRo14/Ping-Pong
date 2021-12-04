#pragma once
#include<iostream>
#include"Caracter.h"
using namespace std;
using namespace System;
class Barra:public Caracter {
public:
	Barra(int _x,int _y) {
		dy= 2;
		ancho = 2;
		alto = 10;
		x = _x;
		y = _y;
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor(color);
		for (int i = 0; i < alto; i++){
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x+j, y + i);
				cout << (char)219;
			}
		}
		Console::ResetColor();
	};
	

	void borrar() {
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	};
	void mover(char direccion) {
		borrar();
		switch (direccion) {
		case 'W':
			if (y - dy > 5) {
				y -= dy;
			}
			else if (y > 5) {
				y = 5;
			}
			break;
		case 'S':
			if (y + dy + alto < 30) {
				y += dy;
			}
			else if (y + alto < 30) {
				y = 30 - alto;
			}
			break;
		}
		dibujar();
	}
	~Barra(){}


};