#include "Caballeros.h"

Caballeros::Caballeros():Guerrero(10)
{
}

Caballeros::~Caballeros()
{
}
void Caballeros::atacar(Habitantes*& atacada){
		atacada->setVida(atacada->getVida()-ataque + 0.095*vida);
	
}
