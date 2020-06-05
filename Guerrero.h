#ifndef GUERRERO_H
#define GUERRERO_H
#include "Habitantes.h"
class Guerrero : public Habitantes
{
	public:
		Guerrero(int);
		virtual void atacar()=0;
		void setAtaque(int);
		int getAtaque();
	protected:
		int ataque;

		
};

#endif
