#include <iostream>
#include <vector>
using namespace std;
#ifndef HABITANTES_H
#define HABITANTES_H

class Habitantes
{
	public:
		Habitantes();
		virtual ~Habitantes();
		void setVida(int);
		int getVida();
		//virtual void atacar(vector<Habitantes*>& atacada)=0;
	protected:
		int vida;
		
};

#endif
