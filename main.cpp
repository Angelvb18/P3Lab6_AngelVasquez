#include <iostream>
#include "Civilizacion.h"
#include "Habitantes.h"
#include "Aldeano.h"
#include "Guerrero.h"
#include "Jinetes.h"
#include "Arqueros.h"
#include "Caballeros.h"
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(int,vector<Civilizacion*>&);
void guerra(int ,vector<Civilizacion*>& );
int main() {
	int op = 0;
	vector<Civilizacion*> ListaCivilizacion;
	while(op!=3){
		cout << "1.Crear Civilizacion\n2.Jugar\n3.Salir\nIngrese una opcion:";
		cin >> op;
		switch(op){
			case 1:{
				string nombre;
				cout << "Ingrese Nombre:";
				cin >> nombre;
				ListaCivilizacion.push_back(new Civilizacion(nombre));
				break;
			}
			case 2:{
				int posocion;
				for(int i ; i < ListaCivilizacion.size() ; i++){
					cout << i << "." << ListaCivilizacion[i]->getNombre() << endl;
				}
				do{
					cout << "Ingrese Numero de la civilizacion con la que va a jugar:";
					cin >> posocion;
				}while(posocion > ListaCivilizacion.size() || posocion < 0);			
				menu(posocion,ListaCivilizacion);
				break;
			}
			case 3:{
				cout << "Adios" << endl;
				break;
			}
			default:
				cout << "Opcion no valida" << endl;
		}
	}
	return 0;
}
void menu(int posicion , vector<Civilizacion*>& Lista){
	int op = 0;
	while (op !=10){
		cout << "1.Crear aldeano\n2.Crear jinete\n3.Crear arquero\n4.Crear caballero\n5.Construir casa\n6.Construir cuartel\n7.Construir establo\n8.Ir a guerra"
		     << "\n9.Siguiente hora\n10.Salir"<<endl;
		cin >> op;
		switch(op){
			case 1:{
				if(Lista[posicion]->getCasas()*2 > Lista[posicion]->getNumeroHabitantes()){
					Lista[posicion]->setHabitante(new Aldeano());
				}
				break;
			}
			case 2:{
				if(Lista[posicion]->getCasas()*2 > Lista[posicion]->getNumeroHabitantes() && Lista[posicion]->getEstablos() > 0){
					Lista[posicion]->setHabitante(new Jinetes());
					cout << "Jinete Agregado" << endl;
				}
				break;
			}
			case 3:{
				if(Lista[posicion]->getCasas()*2 > Lista[posicion]->getNumeroHabitantes() && Lista[posicion]->getCuarteles() > 0){
					Lista[posicion]->setHabitante(new Arqueros());
					cout << "Arquero Agregado" << endl;
				}
				break;
			}
			case 4:{
				if(Lista[posicion]->getCasas()*2 > Lista[posicion]->getNumeroHabitantes() && Lista[posicion]->getCuarteles() > 0){
					Lista[posicion]->setHabitante(new Caballeros());
					cout << "Caballero Agregado" << endl;
				}
				
				break;
			}
			case 5:{
				Lista[posicion]->setCasas(Lista[posicion]->getCasas()+1);
				cout << "Casa Construida" << endl;
				break;
			}
			case 6:{
				Lista[posicion]->setCuarteles(Lista[posicion]->getCuarteles()+1);
				cout << "Cuartelel Construido" << endl;
				break;
			}
			case 7:{
				Lista[posicion]->setEstablos(Lista[posicion]->getEstablos()+1);
				cout << "Establo Construido" << endl;
				break;
			}
			case 8:{
				
				break;
			}
			case 9:{
				
				break;
			}
			case 10:{
				cout << "Adios" << endl;
				break;
			}
			default:{
				cout << "Opcion no valida" << endl;
				break;
			}
		}
	}
}
