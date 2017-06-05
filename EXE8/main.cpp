/* MenyBuganim 302490610	BaruchRothkoff 311603252 */
#include <iostream>
#include "cat.h"
#include "pen.h"
using namespace std;

int main(){
	{
		std::cout << "========================================================" << std::endl;		//our names.
		std::cout << "Meny Buganim  302490610 ---- Baruch Rothkoff  311603252" << std::endl;
		std::cout << "========================================================" << std::endl << std::endl;

		int menu = 0;
		CatsPen catsPen;
		do{
			cout << "#######################   MENU   ########################" << endl;
			cout << "1-add StreetCat." << endl;
			cout << "2-add SiamiCat." << endl;
			cout << "3-print cat's details." << endl;
			cout << "4-print current cat number in PensCat." << endl;
			cout << "5-Exit." << endl;
			cout << ">";
			cin >> menu;
			cout << endl;
			while (cin.fail() || menu < 1 || menu>5){
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "Error, options are 1-5." << endl;
				cout << "try again: >";
				cin >> menu;
				cout << endl << endl;
			}
			if (menu == 1){
				catsPen.addStreet();
			}
			else if (menu == 2){
				catsPen.addSiami();
			}
			else if (menu == 3){
				cout << catsPen << endl;
			}
			else if (menu == 4)	{
				cout <<"number of cats is:	"<< catsPen.getCatsNum() << endl;
			}
		} while (menu != 5); 
	}

	system("pause");
	return 0;
}