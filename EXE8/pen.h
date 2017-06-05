/* MenyBuganim 302490610	BaruchRothkoff 311603252 */
#include <iostream>
#include <cassert>
#include "cat.h"
using namespace std;

#ifndef Pen_H
#define Pen_H

class CatsPen{
	StreetCat*street;
	SiamiCat*siami;
	int catsNum;
	int freeCaves;		//total can be 5.
	int streetC;
	int siamiC;
public:
	CatsPen();
	~CatsPen();
	int getCatsNum(){ return catsNum; }
	friend ostream&operator<<(ostream &os, const CatsPen&c);	
	bool place();
	bool addStreet();
	bool addSiami();
};

#endif // !Pen_H