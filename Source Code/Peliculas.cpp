#include "Peliculas.h"

#include <iostream>
#include <string>
using namespace std;

Peliculas::Peliculas() : Videos() {
	clasificacion = '?';
}

Peliculas::Peliculas(string nom, int iden, string gen, Tiempo dur, float pun, char clas) : Videos(nom,gen,pun,iden,dur) {
	clasificacion = clas;
}

Peliculas::~Peliculas() {}

void Peliculas::printDetalles() {
	cout << "\nNombre:" << nombre;
	if (nombre.length() < 10) {
		cout << "\t\tGenero: " << genero;
	}
	else {
		cout << "\tGenero: " << genero;
	}
	
	if (genero.length() < 8) {
		cout << "\t\tID: " << id;
	}
	else {
		cout << "\tID: " << id;
	}
	
	duracion.imprimir();
	cout << "\t\tPuntuacion: " << puntuacion;
	cout << "\tClasificion: " << clasificacion;
}
