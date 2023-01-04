#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo {
	
	private:
		int hora, min;
		
	public:
		Tiempo();
		Tiempo(int h, int m);
		~Tiempo();
		void operator + (int m) {
			int aux = m + min + hora*60;
			min = aux%60;
			hora = aux/60;
		}
		void imprimir();
};

#endif
