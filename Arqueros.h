#ifndef ARQUEROS_H
#define ARQUEROS_H
#include "Guerrero.h"
class Arqueros : public Guerrero
{
	public:
		Arqueros();
		void atacar(Habitantes*& atacada);
	protected:
};

#endif
