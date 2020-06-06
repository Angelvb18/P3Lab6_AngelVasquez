#include "Arqueros.h"
Arqueros::Arqueros() : Guerrero(20){
	
}
void Arqueros::atacar(Habitantes*& atacada){
		atacada->setVida(atacada->getVida()-ataque + 0.085*vida);
}
