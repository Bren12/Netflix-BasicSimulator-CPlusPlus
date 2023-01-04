#include "Videos.h"

#include "Tiempo.h"
#include <iostream>
#include <string>
using namespace std;

Videos::Videos() {
	nombre = "NA";
	genero = "NA";
	puntuacion = 0;
	id = 0;
	
	Tiempo dur;
	duracion = dur;
}

Videos::Videos(string nom, string gen, float pun, int iden, Tiempo dur) {
	nombre = nom;
	genero = gen;
	puntuacion = pun;
	id = iden;
	duracion = dur;
}

Videos::~Videos() {}

float Videos::getPuntuacion() {
	return puntuacion;
}

string Videos::getGenero() {
	return genero;
}

string Videos::getNombre() {
	return nombre;
}

void Videos::setPuntuacion(float pun) {
	puntuacion = pun;
}

bool Videos::puntuarCap(string titu, int calif) {
	return false;
}

void Videos::imprimirCap(int calif) {}

void Videos::imprimir() {
	cout << "Nombre:" << nombre;
	
	if (nombre.length() < 9) {
		cout << "\t\tGenero: " << genero;
	}
	else {
		cout << "\tGenero: " << genero;
	}
	
	if (genero.length() < 8) {
		cout << "\t";
		duracion.imprimir();
	}
	else {
		duracion.imprimir();
	}
	
	cout << "\t\tID: " << id;
	
	cout << "\t\tPuntuacion: " << puntuacion; 
	
	cout << endl;
}

void Videos::imprimir(int num) {
	cout << ".~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~ Bienvenido al portal de Netflix Latino #" << num << " ~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.\n\n";
}
