#include<iostream>
#include<conio.h>
#include"Controladora.h"
using namespace std;
int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	Controladora* controladora;
	controladora = new Controladora();
	controladora->dibujarInicio();
	ConsoleKeyInfo tecla;
	//hay cierto bug, que aveces la pelota se queda atorada dentro de una barra.
	//creo que se esto se reproduce cuando la barra se mueve sobre la pelota
	while (true) {
		controladora->imprimeChoques();
		controladora->moverTodo();
		if (_kbhit()) {
			tecla = Console::ReadKey(true);
			switch (tecla.Key) {
			case ConsoleKey::UpArrow:
				controladora->moverBarras('W');
				break;
			case ConsoleKey::DownArrow:
				controladora->moverBarras('S');
				
				break;
			}
		}
		_sleep(controladora->getTiempo());
	}
	delete controladora;
	system("pause>nul");
	return 0;

}