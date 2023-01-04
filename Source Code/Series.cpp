#include "Series.h"
#include <iostream>
#include <string>
using namespace std;

Series::Series() : Videos() {
	Episodio cap[6];
	
	for (int i = 0; i < 6; i++) {
		capitulo[i] = cap[i];
	}
}

Series::Series(string nom, int iden, string gen, Tiempo dur, float pun, Episodio cap[]) : Videos(nom,gen,pun,iden,dur) {
	for (int i = 0; i < 6; i++) {
		capitulo[i] = cap[i];
	}
}

Series::~Series() {}

void Series::printDetalles() {
	cout << "\nNombre:" << nombre;
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
	
	cout << "\tPuntuacion: " << puntuacion;
	
	cout << "\n\nTemporada " << capitulo[0].getTemporada() << "\t\t\t\t\tTemporada " << capitulo[3].getTemporada() << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Capitulo " << i+1 << ": " << capitulo[i].getTitulo() << "\tCalificacion: " << capitulo[i].getCalificacion() 
		<< "\t\tCapitulo " << i+1 << ": " << capitulo[i+3].getTitulo() << "\tCalificacion: " << capitulo[i+3].getCalificacion() << endl;
	}
	
	cout << endl << endl;
	
}

bool Series::puntuarCap(string titu, int calif) {
	int acum = 0;
	float cal;
	for (int i = 0; i < 6; i++) {
		if (capitulo[i].getTitulo() == titu) {
			capitulo[i].setCalificacion(calif);
			for (int j = 0; j < 6; j++) {
				acum = capitulo[j] + acum;
			}
			puntuacion = acum/6.0;
			return true;
		}
	}
	return false;
}

void Series::imprimirCap(int calif) {
	int cont =  0;
	cout << "\nNombre:" << nombre << endl;
	for (int i = 0; i < 6; i++) {
		if (capitulo[i].getCalificacion() == calif) {
			if (capitulo[i].getTemporada() == 1) {
				cout << "\nTemporada " << capitulo[i].getTemporada() << "\tCapitulo " << i+1 << ": " 
				<< capitulo[i].getTitulo() << "\tCalificacion: " << capitulo[i].getCalificacion();
				cont++;
			}
			else {
				cout << "\nTemporada " << capitulo[i].getTemporada() << "\tCapitulo " << i-2 << ": " 
				<< capitulo[i].getTitulo() << "\tCalificacion: " << capitulo[i].getCalificacion();
				cont++;
			}
		}
	}
	
	if (cont == 0) {
		cout << "No se encontraron capitulos con la puntuacion otorgada" << endl;
	}
}







