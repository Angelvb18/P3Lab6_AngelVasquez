#ifndef GUERRERO_H
#define GUERRERO_H
#include "Habitantes.h"

class Guerrero : public Habitantes
{
	public:
		Guerrero(int);
		Guerrero();
		//~Guerrero();
		virtual void atacar(Habitantes*& atacada);
		void setAtaque(int);
		int getAtaque();
	protected:
		int ataque;

		
};

#endif
