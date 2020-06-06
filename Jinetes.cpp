#include "Jinetes.h"

Jinetes::Jinetes():Guerrero(30)
{
}

Jinetes::~Jinetes()
{
}
void Jinetes::atacar(Habitantes*& atacada){
		atacada->setVida(atacada->getVida()-ataque + 0.065*vida);
	
}
