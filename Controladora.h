#pragma once
#include<vector>
#include"Barra.h"
#include"Pelota.h"
using namespace std;
class Controladora {
private:
	vector<Barra*> barras;
	Pelota* pelota;
	float tiempo;
	int choques;
public:
	Controladora() {
		barras.push_back(new Barra(25,10));//5,10
		barras.push_back(new Barra(93,10));//113,10
		pelota = new Pelota();
		tiempo = 40;
		choques = 0;
	}
	/*Barra* getBarra(int pos) {
		return barras[pos];
	}*/
	void imprimeChoques() {
		Console::SetCursorPosition(15,2);
		cout << choques;
	}
	float getTiempo() { return tiempo; }
	void moverBarras(char direccion) {
		for (int i = 0; i < barras.size(); i++) {
			barras[i]->mover(direccion);
		}
	}
	void dibujarInicio() {
		Console::SetCursorPosition(5, 2);
		cout << "Choques:";
		Console::ForegroundColor = ConsoleColor::Yellow;
		for (int i = 0; i < 120; i++) {
			Console::SetCursorPosition(i, 4);
			cout << (char)219;
		}
		Console::ResetColor();
		for (int i = 0; i < barras.size(); i++) {
			barras[i]->dibujar();
		}
	}
	void moverTodo() {
		pelota->mover(barras,tiempo,choques);
	}
	~Controladora() {
		delete pelota;
	}
};