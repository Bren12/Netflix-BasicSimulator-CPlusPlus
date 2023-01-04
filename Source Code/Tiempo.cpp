#include "Tiempo.h"

#include <iostream>
#include <string>
using namespace std;

Tiempo::Tiempo() {
	hora = 0;
	min = 0;
}

Tiempo::Tiempo(int h, int m) {
	hora = h;
	min = m;
}

Tiempo::~Tiempo() {}

void Tiempo::imprimir() {
	cout << "\tDuracion: " << hora << " horas y " << min << " minutos";
}
