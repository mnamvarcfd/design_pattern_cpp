#include <iostream>

using namespace std;

#include "Singelton.h"


int main()
{
	
	Singelton& obj1 = Singelton::createInstance(1);
	Singelton& obj2 = Singelton::createInstance(2);


	cout << "obj1 " << obj1.atr << endl;
	cout << "obj2 " << obj2.atr << endl;

	return 0;
}



