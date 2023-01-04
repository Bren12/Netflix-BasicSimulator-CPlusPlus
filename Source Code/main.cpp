// Brenda Elena Saucedo González - A00829855
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Peliculas.h"
#include "Tiempo.h"
#include "Series.h"
#include "Episodio.h"
using namespace std;

int main() {
	system("color f0");
	
	Videos::imprimir(1);
	
	Videos *video[30];
	int resp;
	
	do {
		cout << "--------------------------------------- MENU ---------------------------------------\n";
		cout << "1. Cargar archivo de datos\n";
		cout << "2. Mostrar los videos en general con una cierta calificacion o de un cierto genero\n";
		cout << "3. Mostrar los capitulos de una determinada serie con sus calificaciones\n";
		cout << "4. Mostrar las peliculas con cierta calificacion\n";
		cout << "5. Calificar un video\n6. Mostrar los videos en general\n";
		cout << "7. Mostrar los capitulos de una determinada serie con una determinada calificacion\n0. Salir\n";
		cout << "Opcion -> ";
		cin >> resp;
		cout << endl;
		
		switch (resp) {
			case 1: {
				ifstream archivoP, archivoS;
				string gen;
				char nom[20],clas;
				int iden, min;
				float pun;
				
				////////////////////////////////////////////////////// Peliculas //////////////////////////////////////////////////////
				archivoP.open("pelis.txt");
				
				if (archivoP != NULL) {
					for (int i = 0; archivoP >> nom >> iden >> gen >> min >> pun >> clas; i++) {
						// Sobrecarga de Operadores
						Tiempo dur;
						dur + min;
						
						strupr(nom);
						string nomStr(nom);
						
						video[i] = new Peliculas(nomStr,iden,gen,dur,pun,clas);
					}
				}
				else {
					cout << "Archivo no encontrado" << endl;
					exit(1);
				}
				
				archivoP.close();
				
				////////////////////////////////////////////////////// Series //////////////////////////////////////////////////////
				int tem1, tem2;
				string cap[6];
				Episodio capit[6];
				float acum, cali[6],pun2;
				
				archivoS.open("seriesTV.txt");
				
				if (archivoS != NULL) {
					for (int i = 0; archivoS >> nom >> gen >> iden >> min >> tem1 >> cap[0] >> cali[0] >> cap[1] >> cali[1] >> cap[2] >> cali[2] 
					                         >> tem2 >> cap[3] >> cali[3] >> cap[4] >> cali[4] >> cap[5] >> cali[5]; i++) {
						acum = 0;
						strupr(nom);
						string nomStr(nom);
						
						// Sobrecarga de Operadores
						Tiempo dur;
						dur + min;
						
						for (int i = 0; i < 6; i++) {
							if (i < 3) {
								capit[i].setTemporada(tem1);
							}
							else {
								capit[i].setTemporada(tem2);
							}
							capit[i].setTitulo(cap[i]);
							capit[i].setCalificacion(cali[i]);
							// Sobrecarga de Operadores
							acum = capit[i] + acum;
						}
						
						pun = acum/6.0;
						
						video[i+15] = new Series(nomStr,iden,gen,dur,pun,capit);
					}
					cout << endl;
				}
				else {
					cout << "Archivo no encontrado" << endl;
					exit(1);
				}
				
				archivoS.close();
				
				break;
			}
			case 2: {
				int opc;
				int p;
				do {
					cout << "1. Videos con una cierta calificacion\n2. Videos de un cierto genero\nOpcion -> ";
					cin >> opc;
				} while (opc != 1 and opc != 2);
				
				if (opc == 1) {
					bool busqueda = false;
					
					do {
						cout << "\nTeclea la calificacion (1-5): ";
						cin >> p;
					} while (p < 1 or p > 5);
					
					cout << endl;
					for (int i = 0; i < 15; i++) {
						if (video[i]->getPuntuacion() == p*1.0) {
							video[i]->imprimir();
							busqueda = true;
						}
					}
					
					for (int i = 15; i < 30; i++) {
						if (video[i]->getPuntuacion() >= p*1.0 and video[i]->getPuntuacion() < p+1) {
							video[i]->imprimir();
							busqueda = true;
						}
					}
					
					if (busqueda == false) {
						cout << "No se encontro un video con una calificacion de " << p << endl;
					}
					cout << endl << endl;
				}
				else {
					bool busqueda = false;
					char g[20];
					
					cout << "\nTeclea el genero: ";
					cin >> g;
					strlwr(g);
					string gStr(g);
					
					cout << endl;
					for (int i = 0; i < 30; i++) {
						if (video[i]->getGenero() == gStr) {
							video[i]->imprimir();
							busqueda = true;
						}
					}
					if (busqueda == false) {
						cout << "No se encontro un video con el genero de " << gStr << endl;
					}
					
					cout << endl << endl;
				}
				
				break;
			}
			case 3: {
				char nom[20];
				bool busqueda = false;
				
				cout << "Teclee el nombre de la serie a buscar: ";
				cin >> nom;
				strupr(nom);
				string nomStr(nom);
				
				for (int i = 15; i < 30; i++) {
					if (video[i]->getNombre() == nomStr) {
						video[i]->printDetalles();
						busqueda = true;
					}
				}
				
				if (busqueda == false) {
					cout << "No se encontro una serie con el nombre de " << nomStr << endl;
				}
				
				cout << endl;
				
				break;
			}
			case 4: {
				
				int calif;
				bool busqueda = false;
				
				do {
					cout << "Teclee la calificacion a buscar (1-5): ";
					cin >> calif;
				} while (calif < 1 or calif > 5);
				
				for (int i = 0; i < 15; i++) {
					if (video[i]->getPuntuacion() == calif*1.0) {
						video[i]->printDetalles();
						busqueda = true;
					}
				}
				
				if (busqueda == false) {
					cout << "No se encontro una pelicula con una calificacion de " << calif << endl << endl;
				}
				else {
					cout << endl << endl;
				}
				
				break;
			}
			case 5: {
				char nom[20], titu[20];
				int calif, pos = -1;
				bool busqueda = false, busqS = false, cap = false;
				
				cout << "Teclee el titulo del video a calificar: ";
				cin >> nom;
				strupr(nom);
				string nomStr(nom);
				
				for (int i = 0; i < 15; i++) {
					if (video[i]->getNombre() == nomStr) {
						busqueda = true;
						pos = i;
					}
				}
				
				if (busqueda == true) {
					do {
						cout << "Teclee la calificacion a otorgar (1-5): ";
						cin >> calif;
					} while (calif < 1 or calif > 5);
					
					video[pos]->setPuntuacion(calif*1.0);
				}
				
				if (busqueda == false) {
					for (int i = 15; i < 30; i++) {
						if (video[i]->getNombre() == nomStr) {
							busqS = true;
							pos = i;
						}
					}
				}
				
				if (busqS == true) {
					cout << "Teclee el titulo del capitulo: ";
					cin >> titu;
					strlwr(titu);
					string tStr(titu);
					
					do {
						cout << "Teclee la calificacion a otorgar (1-5): ";
						cin >> calif;
					} while (calif < 1 or calif > 5);
					
					cap = video[pos]->puntuarCap(tStr,calif);
				}
				
				if (cap == true or busqueda == true) {
					cout << "\n\nCalificacion modificada con exito!\n\n";
					video[pos]->printDetalles();
					cout << endl << endl;
				}
				else {
					cout << "No se encontro un video con ese titulo" << endl << endl;
				}
				
				break;
			}
			case 6: {
				cout << ".~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~ Peliculas Disponibles ~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~." << endl;
				for (int i = 0; i < 15; i++) {
					video[i]->printDetalles();
				}
				cout << endl;
				system("PAUSE");
				cout << endl << endl;
				cout << ".~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~ Series Disponibles ~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~." << endl;
				for (int i = 15; i < 30; i++) {
					video[i]->printDetalles();
				}
				break;
			}
			case 7: {
				char nom[20];
				bool busqueda = false;
				int calif;
				
				cout << "Teclee el nombre de la serie a buscar: ";
				cin >> nom;
				strupr(nom);
				string nomStr(nom);
				
				for (int i = 15; i < 30; i++) {
					if (video[i]->getNombre() == nomStr) {
						
						do {
							cout << "Teclee la calificacion a buscar en la serie otorgada (1-5): ";
							cin >> calif;
						} while (calif < 1 or calif > 5);
						
						video[i]->imprimirCap(calif);
						busqueda = true;
					}
				}
				
				if (busqueda == false) {
					cout << "No se encontro una serie con el nombre de " << nomStr << endl;
				}
				
				cout << endl << endl;
				break;
			}
		}
	} while(resp != 0);
	
	return 0;
}
