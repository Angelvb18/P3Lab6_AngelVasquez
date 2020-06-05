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
void guerra(Civilizacion*& ,Civilizacion*&);
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
	int hjinete=0,harquero=0,hcaballero=0;
	vector<Caballeros*>precaballeros;
	vector<Jinetes*>preJinetes;
	vector<Arqueros*>prearqueros;
	vector<Aldeano*>prealdeano;
	while (op !=10){
		cout << "1.Crear aldeano\n2.Crear jinete\n3.Crear arquero\n4.Crear caballero\n5.Construir casa\n6.Construir cuartel\n7.Construir establo\n8.Ir a guerra"
		     << "\n9.Siguiente hora\n10.Salir"<<endl;
		cin >> op;
		switch(op){
			case 1:{
				if(Lista[posicion]->getNumeroHabitantes() > 0){
					prealdeano.push_back(new Aldeano());
					cout << "Aldeano Agreado a la cola" << endl;
				}else{
					cout << "No se peude Agregar" << endl;
				}
				break;
			}
			case 2:{
				if(Lista[posicion]->getNumeroHabitantes() > 0 && Lista[posicion]->getEstablos() > 0){
					preJinetes.push_back(new Jinetes());
					cout << "Jinete Agregado a la cola" << endl;
				}else{
					cout << "No se peude Agregar" << endl;
				}
				break;
			}
			case 3:{
				if(Lista[posicion]->getNumeroHabitantes() > 0 && Lista[posicion]->getCuarteles() > 0){
					 prearqueros.push_back(new Arqueros());
					cout << "Arquero Agregado" << endl;
				}else{
						cout << "No se peude Agregar" << endl;
				}
				break;
			}
			case 4:{
				if(Lista[posicion]->getNumeroHabitantes() > 0 && Lista[posicion]->getCuarteles() > 0){
					precaballeros.push_back(new Caballeros());
					cout << "Caballero Agregado" << endl;
				}
				
				break;
			}
			case 5:{
				if(Lista[posicion]->getMadera() >=50){
					Lista[posicion]->setCasas(Lista[posicion]->getCasas()+1);
					Lista[posicion]->setMadera(Lista[posicion]->getMadera()-50);
					Lista[posicion]->setNumeroHabitantes(Lista[posicion]->getNumeroHabitantes()+5); 
					cout << "Casa Construida" << endl;
					
					break;
				}else{
					cout << "Faltan materiales " << endl;
				}
				
			}
			case 6:{
				if(Lista[posicion]->getMadera()>= 200 && Lista[posicion]->getOro() >= 50){
					Lista[posicion]->setCuarteles(Lista[posicion]->getCuarteles()+1);
					cout << "Cuartelel Construido" << endl;
				}else{
					cout << "Faltan materiales " << endl;
				}
				
				break;
			}
			case 7:{
				if(Lista[posicion]->getMadera()>= 150 && Lista[posicion]->getOro() >= 50){
					Lista[posicion]->setEstablos(Lista[posicion]->getEstablos()+1);
					cout << "Establo Construido" << endl;
				}else{
					cout << "Faltan materiales " << endl;
				}
				break;
			}
			case 8:{
				if(Lista.size() > 1){
					
					int posiataque;
					for(int i ; i < Lista.size() ; i++){
						cout << i << "." << Lista[i]->getNombre() << endl;
					}
					do{
					cout << "Ingrese a que civilizacion va a ataca:";
					cin >> posiataque;
					}while(posiataque > Lista.size() || posiataque < 0);
					guerra(Lista[posicion],Lista[posiataque]);
				}else{
	    			cout << "Solo esta su civilizacion" << endl;
				}
			
				break;
			}
			case 9:{	
				if(prearqueros.size() != 0){
					harquero++;
				}
				if(precaballeros.size() != 0){
					hcaballero++;
				}
				if(preJinetes.size() != 0){
					hjinete++;
				}
				for (int i = 0 ; i < prealdeano.size();i ++){
					if(Lista[posicion]->getAlimento() > 25 && Lista[posicion]->getNumeroHabitantes() > 0){
					   Lista[posicion]->setHabitante(prealdeano[i]);
					   prealdeano.erase(prealdeano.begin() + i);
					   Lista[posicion]->setAlimento(Lista[posicion]->getAlimento()-25);
					   Lista[posicion]->setNumeroHabitantes(Lista[posicion]->getNumeroHabitantes() -1);
				   }else{
				   	  // cout << "Nesecita mas recursos" << endl;
				   }
			   }
			   for (int i = 0 ; i < prearqueros.size();i ++){
					if(Lista[posicion]->getMadera() >= 10 && Lista[posicion]->getOro() >= 10 &&Lista[posicion]->getAlimento() >= 50 && Lista[posicion]->getNumeroHabitantes() > 0 && harquero==4 ){
					   Lista[posicion]->setHabitante(prearqueros[i]);
					   prearqueros.erase(prearqueros.begin() + i);
					   Lista[posicion]->setAlimento(Lista[posicion]->getAlimento()-50);
					   Lista[posicion]->setOro(Lista[posicion]->getOro()-10);
					   Lista[posicion]->setMadera(Lista[posicion]->getMadera()-10);
					   Lista[posicion]->setNumeroHabitantes(Lista[posicion]->getNumeroHabitantes() -1); 
				   }else{
				   	  // cout << "Nesecita mas recursos" << endl;
				   }
			   }
			   for (int i = 0 ; i < precaballeros.size();i ++){
					if(Lista[posicion]->getMadera() >= 5 && Lista[posicion]->getOro() >= 15 &&Lista[posicion]->getAlimento() >= 50 && Lista[posicion]->getNumeroHabitantes() > 0 && harquero==4 ){
					   Lista[posicion]->setHabitante(precaballeros[i]);
					   precaballeros.erase(precaballeros.begin() + i);
					   Lista[posicion]->setAlimento(Lista[posicion]->getAlimento()-50);
					   	Lista[posicion]->setOro(Lista[posicion]->getOro()-15);
					   Lista[posicion]->setMadera(Lista[posicion]->getMadera()-5);
					   Lista[posicion]->setNumeroHabitantes(Lista[posicion]->getNumeroHabitantes() -1); 
				   }else{
				   	  // cout << "Nesecita mas recursos" << endl;
				   }
			   }
			   for (int i = 0 ; i < preJinetes.size();i ++){
					if(Lista[posicion]->getMadera() >= 5 && Lista[posicion]->getOro() >= 20 &&Lista[posicion]->getAlimento() >= 75 && Lista[posicion]->getNumeroHabitantes() > 0 && harquero==6 ){
					   Lista[posicion]->setHabitante(preJinetes[i]);
					   preJinetes.erase(preJinetes.begin() + i);
					   Lista[posicion]->setAlimento(Lista[posicion]->getAlimento()-75);
					   Lista[posicion]->setOro(Lista[posicion]->getOro()-20);
					   Lista[posicion]->setMadera(Lista[posicion]->getMadera()-5);
					   Lista[posicion]->setNumeroHabitantes(Lista[posicion]->getNumeroHabitantes() -1); 
				   }else{
				   	  // cout << "Nesecita mas recursos" << endl;
				   }
			   }
				if(hjinete == 6){
					hjinete =0;
				}
				if(hcaballero == 4){
					hcaballero =0;
				}
				if(harquero == 4){
					harquero++;
				}
				cout << "Alimento:" << Lista[posicion]->getAlimento() << "\nOro:"<<Lista[posicion]->getOro() << "\nMadera:" << Lista[posicion]->getMadera() << endl;
				cout << "Numero de Habitantes:" << Lista[posicion]->getNumeroHabitantes() << endl;
				if(prealdeano.size() != 0){
					cout << "Para crear un Aldeano falta una 1 Hora "<< endl; 
				}
				
				if(prearqueros.size() != 0){
					cout << "Para crear un Arquero faltan " << 4-harquero<<" Horas"<< endl; 
				}
				if(precaballeros.size() != 0){
					cout << "Para crear un Caballeros faltan " << 4-hcaballero<<" Horas"<< endl; 
				}
				if(preJinetes.size() != 0){
					cout << "Para crear un Arquero Jinete" << 6-harquero<<" Horas"<< endl;
				}
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
void guerra(Civilizacion*& mia,Civilizacion*& atacada){
	
	
	
}
