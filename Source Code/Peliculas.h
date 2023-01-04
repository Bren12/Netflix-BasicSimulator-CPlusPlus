#ifndef PELICULAS_H
#define PELICULAS_H

#include "Videos.h"
#include <iostream>
#include <string>
using namespace std;


class Peliculas : public Videos {
	
	private:
		char clasificacion;
	
	public:
		Peliculas();
		Peliculas(string nom, int iden, string gen, Tiempo dur, float pun,char clas);
		~Peliculas();
		void printDetalles();
};

#endif
