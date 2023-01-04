#include "Episodio.h"

Episodio::Episodio() {
	titulo = "NA";
	temporada = 0;
	calificacion = 0;
}

Episodio::Episodio(string title, int season, int calif) {
	titulo = title;
	temporada = season;
	calificacion = calif;
}

Episodio::~Episodio() {}

void Episodio::setCalificacion(int calif) {
	calificacion = calif;
}

void Episodio::setTemporada(int season) {
	temporada = season;
}

void Episodio::setTitulo(string title) {
	titulo = title;
}

int Episodio::getCalificacion() {
	return calificacion;
}

int Episodio::getTemporada() {
	return temporada;
}

string Episodio::getTitulo() {
	return titulo;
}
