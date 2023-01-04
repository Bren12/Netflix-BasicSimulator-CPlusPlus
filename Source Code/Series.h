#ifndef SERIES_H
#define SERIES_H

#include "Videos.h"
#include "Episodio.h"
#include <string>
using namespace std;

class Series : public Videos {
	
	private:
		Episodio capitulo[6];
	
	public:
		Series();
		Series(string nom, int iden, string gen, Tiempo dur, float pun, Episodio cap[]);
		~Series();
		
		void printDetalles();
		bool puntuarCap(string titu, int calif);
		void imprimirCap(int calif);
};

#endif
