#include <iostream>
#include <vector>
#include "Habitantes.h"
#ifndef CIVILIZACION_H
#define CIVILIZACION_H

using namespace std;
class Civilizacion
{
	// nombre, sus recursos (oro, madera y alimento), el número de habitantes que puede albergar,
//una lista de habitantes, número de casas, de cuarteles y de establos. 
	public:
		Civilizacion(string);
		~Civilizacion();
		void setNombre(string);
		void setOro(int);
		void setAlimento(int);
		void setMadera(int);
		void setNumeroHabitantes(int);
		void setCasas(int);
		void setCuarteles(int);
		void setEstablos(int);
		string getNombre();
		int getOro();
		int getAlimento();
		int getMadera();
		int getNumeroHabitantes();
		int getCasas();
		int getCuarteles();
		int getEstablos();
		vector<Habitantes*>& getHabitantes();
		void setHabitante(Habitantes*);
		void setHabitante(int);
	protected:
	string nombre;
	int oro,madera,alimentos,numeroHabitantes,casas,cuarteles,establos;
	vector<Habitantes*>lista;
};

#endif
