/* MenyBuganim 302490610	BaruchRothkoff 311603252 */
#include <iostream>
#include <cassert>
#include "cat.h"
#include "pen.h"
using namespace std;

static int streetC=0;
static int siamiC=0;

CatsPen::CatsPen() :catsNum(0), freeCaves(5){		//default values.
		street = new StreetCat[5];					//max size of 5.
		assert(street != NULL&&"Heap error.");
		siami = new SiamiCat[5];
		assert(siami != NULL&&"Heap error.");
}

CatsPen::~CatsPen(){
	delete[]street;
	delete[]siami;
}

bool CatsPen::place(){
	if (freeCaves){			//while its different from 0 true.
		return true;
	}
	else{					//else mean 0 and that's means no free caves.
		cout << "sorry,full capacity.	" << endl;
		return false;
	}
}

ostream&operator<<(ostream &os, const CatsPen&c){
	int counter = 0;
	if (streetC == 0&&siamiC){
		os << "Lists are empty." << endl;
	}
	else if (streetC == 0){
		os << "street cat list empty." << endl;
		while (siamiC > counter){
			os << c.siami[counter] << endl;
			counter++;
		}
	}
	else if (siamiC == 0){
		os << "siami cat list empty." << endl;
		while (streetC > counter){
			os << c.street[counter] << endl;
			counter++;
		}
	}
	else{
		int counter2 = 0;
		while (streetC > counter){
			os << c.street[counter] << endl;
			counter++;
		}
		while (siamiC > counter2){
			os << c.siami[counter2] << endl;
			counter2++;
		}
	}
	return os;

}

bool CatsPen::addStreet(){
	if (place()){			//while place true.
		StreetCat temp;
		cin >> temp;		//receive new streetCat;
		cout << "Succes adding." << endl;
		cout << temp<<endl;
		street[streetC++] = temp;
		freeCaves--;
		catsNum++;
	}
	return false;
}

bool CatsPen::addSiami(){
	if (place()){			//while place true.
		SiamiCat temp;		
		cin >> temp;		//receive new siamiCat;
		cout << "Succes adding." << endl;
		cout << temp << endl;
		siami[siamiC++] = temp;
		freeCaves--;
		catsNum++;
	}
	return false;
}