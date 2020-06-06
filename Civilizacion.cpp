#include "Civilizacion.h"
#include "Habitantes.h"
#include "Aldeano.h"
#include "Guerrero.h"
#include "Jinetes.h"
#include "Arqueros.h"
#include "Caballeros.h"
Civilizacion::Civilizacion(string nombre)
{
	this->nombre = nombre;
	this->alimentos=50;
	this->oro = 50;
	this->madera = 50;
	this->numeroHabitantes=4;
	this->casas=2;
	for(int i = 0 ; i < 5 ; i++){
		lista.push_back(new Aldeano());
	}
	lista.push_back(new Jinetes());
	
}

Civilizacion::~Civilizacion()
{
}
void Civilizacion::setNombre(string){
	this->nombre = nombre;
}
void Civilizacion::setOro(int oro){
	this->oro = oro;
}
void Civilizacion::setAlimento(int alimentos){
    this->alimentos = alimentos;
}
void Civilizacion::setMadera(int madera){
   this->madera = madera;
}
void Civilizacion::setNumeroHabitantes(int numeroHabitantes){
	this->numeroHabitantes= numeroHabitantes;
}
void Civilizacion::setCasas(int casas){
	this->casas = casas;
}
void Civilizacion::setCuarteles(int cuarteles){
	this->cuarteles = cuarteles;
}
void Civilizacion::setEstablos(int establos){
	this->establos = establos;
}
string Civilizacion::getNombre(){
	return nombre;
}
int Civilizacion::getOro(){
	return oro;
}
int Civilizacion::getAlimento(){
	return alimentos;
}
int Civilizacion::getMadera(){
	return madera;
}
int Civilizacion::getNumeroHabitantes(){
	return numeroHabitantes;
}
int Civilizacion::getCasas(){
	return casas;
}
int Civilizacion::getCuarteles(){
	return cuarteles;
}
int Civilizacion::getEstablos(){
	return establos;
}
vector<Habitantes*>& Civilizacion::getHabitantes(){
	return lista;
}
void Civilizacion::setHabitante(Habitantes* nuevo){
	lista.push_back(nuevo);
}
void Civilizacion::setHabitante(int posiscion){
	lista.erase(lista.begin() + posiscion);
}

