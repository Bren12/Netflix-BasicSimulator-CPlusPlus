#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
using namespace std;

class Episodio {
	
	private:
		string titulo;
		int temporada, calificacion;
		
	public:
		Episodio();
		Episodio(string title, int season, int calif);
		~Episodio();
		
		int operator + (int acum) {
			return acum + calificacion;
		}
		
		void setTitulo(string title);
		void setTemporada(int season);
		void setCalificacion(int calif);
		
		string getTitulo();
		int getTemporada();
		int getCalificacion();
};

#endif
