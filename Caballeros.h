#ifndef CABALLEROS_H
#define CABALLEROS_H

#include "Guerrero.h"

class Caballeros: public Guerrero
{
	public:
		Caballeros();
		~Caballeros();
		void atacar(vector<Habitantes*>& atacada);
	protected:
};

#endif
