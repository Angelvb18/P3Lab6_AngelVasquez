#include "Habitantes.h"
Habitantes::Habitantes(){
	this->vida=100;
}
void Habitantes::setVida(int vida){
	this->vida = vida;
}
int Habitantes::getVida(){
	return vida;
}
Habitantes::~Habitantes(){
}
