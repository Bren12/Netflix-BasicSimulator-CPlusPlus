#ifndef VIDEOS_H
#define VIDEOS_H

#include "Tiempo.h"
#include <iostream>
#include <string>
using namespace std;

class Videos {
	
	protected:
		string nombre;
		string genero;
		float puntuacion;
		int id;
		Tiempo duracion;
	
	public:
		Videos();
		Videos(string nom, string gen, float pun, int iden, Tiempo dur);
		~Videos();
		
		float getPuntuacion();
		string getGenero();
		string getNombre();
		
		void setPuntuacion(float pun);
		
		virtual void printDetalles() = 0;
		virtual bool puntuarCap(string titu, int calif);
		virtual void imprimirCap(int calif);
		
		void imprimir();
		static void imprimir(int num);
};

#endif
