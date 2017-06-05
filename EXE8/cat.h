/* MenyBuganim 302490610	BaruchRothkoff 311603252 */
#include <iostream>	
#include <cassert>
using namespace std;

#ifndef Cat_H
#define Cat_H

static int counter = NULL;

class Cat{
protected:
	char*name;
	int id;
	double mLength;
	char*color;
public:
	Cat();
	Cat(char*name, int id, double mLength, char*color);
	Cat(const Cat&copy);
	~Cat();
	const Cat& operator=(const Cat&c);
	friend ostream& operator<< (ostream&os, const Cat&c);
	friend istream&operator>>(istream&in, Cat&c);
};
class StreetCat :public Cat{
	int battles;
public:
	StreetCat(){}
	StreetCat(const Cat&c, int battles) : Cat(c), battles(battles){}
	StreetCat(const StreetCat&copy) :Cat(copy), battles(copy.battles){}
	~StreetCat(){}
	const StreetCat operator=(const StreetCat&c);
	friend ostream& operator<< (ostream&os, const StreetCat&c);
	friend istream&operator>>(istream&in, StreetCat&c);
};
class SiamiCat :public Cat{
	char FavFood;
public:
	SiamiCat(){}
	SiamiCat(const Cat&c, char food) :Cat(c), FavFood(food){}
	SiamiCat(const SiamiCat&copy) :Cat(copy), FavFood(copy.FavFood){}
	~SiamiCat(){}
	const SiamiCat operator=(const SiamiCat&c);
	friend ostream& operator<< (ostream&os, const SiamiCat&cv);
	friend istream&operator>>(istream&in, SiamiCat&c);
};
#endif // !Cat_H