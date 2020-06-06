#include "Guerrero.h"
Guerrero::Guerrero(int ataque) :Habitantes(){
	this->ataque = ataque;
}
void Guerrero::setAtaque(int ataque){
	this->ataque = ataque;
}
int Guerrero::getAtaque(){
	return ataque;
}
void Guerrero::atacar(vector<Habitantes*>& atacada){
}
