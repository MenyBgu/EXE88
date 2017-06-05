/* MenyBuganim 302490610	BaruchRothkoff 311603252 */
#include <iostream>
#include <cassert>
#include "cat.h"
using namespace std;

Cat::Cat(){
	name = "";
	color = "";
	id = 0;
	mLength = 0;
}

Cat::Cat(char*name, int id, double mLength, char*color){
	this->name = _strdup(name);
	this->id = id;
	this->mLength = mLength;
	this->color = _strdup(color);
}

Cat::Cat(const Cat&copy){
	this->name = _strdup(copy.name);
	this->id = copy.id;
	this->mLength = copy.mLength;
	this->color = _strdup(copy.color);
}

const Cat &Cat::operator=(const Cat&c){
	if (this != &c){
		name = _strdup(c.name);
		color = _strdup(c.color);
		id = c.id;
		mLength = c.mLength;
	}
	return *this;
}

Cat::~Cat(){
	delete[]name;
	delete[]color;
}

const StreetCat StreetCat:: operator=(const StreetCat&c){
	name = _strdup(c.name);
	color = _strdup(c.color);
	id = c.id;
	mLength = c.mLength;
	battles = c.battles;
	return *this;
}

const SiamiCat SiamiCat::operator=(const SiamiCat&c){
	name = _strdup(c.name);
	color = _strdup(c.color);
	id = c.id;
	mLength = c.mLength;
	FavFood = c.FavFood;
	return *this;
}


ostream& operator<< (ostream&os, const Cat&c){
	os << "cat name: " << c.name << endl
		<< "cat id: " << c.id << endl
		<< "cat mustach length: " << c.mLength << endl
		<< "cat color: " << c.color << endl;
	return os;
}
istream&operator>>(istream&in, Cat&c){
	c.name = new char[100];
	assert(c.name != 0 && "heap error.");
	c.color = new char[100];
	assert(c.color != 0 && "heap error.");

	cout << "enter name: ";
	in >> c.name;
	while (cin.fail()){
		cout << "error occure,try again: ";
		cin.ignore(INT_MAX, '\n');
		in >> c.name;
	}
	cout << endl << "enter mustach length: ";
	in >> c.mLength;
	while (cin.fail()){
		cout << "error occure,try again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		in >> c.mLength;
	}
	cout << endl << "enter color: ";
	in >> c.color;
	while (cin.fail()){
		cout << "error occure,try again: ";
		cin.ignore(INT_MAX, '\n');
		in >> c.color;
	}
	c.id = ++counter;
	return in;
}

ostream& operator<< (ostream&os, const SiamiCat&cv){	//Siami print out.
	os << static_cast<Cat>(cv);							//receive detailes from cat.
	os << "favorite food: " << cv.FavFood << endl;		//options are A or B.
	return os;
}

istream&operator>>(istream&in, SiamiCat&c){				//Siami cin.
	Cat*temp = &c;										//receive detailes from cat.
	in >> *temp;
	cout << endl << "please enter favorite food(A/B): ";		//options are A or B.
	in >> c.FavFood;
	while (cin.fail()||(c.FavFood!='A'&&c.FavFood!='B')){
		cout << "error occure,try again(A/B): ";
		cin.ignore(INT_MAX, '\n');
		in >> c.FavFood;
	}
	return in;
}

ostream& operator<< (ostream&os, const StreetCat&c){	//StreetCat cout
	os << static_cast<Cat>(c);							//receive detailes from cat.
	os << "cat fights: " << c.battles << endl;
	return os;
}

istream&operator>>(istream&in, StreetCat&c){			//StreetCat cin
	Cat*temp = &c;										//receive detailes from cat.
	in >> *temp;
	cout << endl << "enter cat number of fights: ";
	in >> c.battles;
	while (cin.fail()){
		cout << "error occure,try again: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		in >> c.battles;
	}
	return in;
}
