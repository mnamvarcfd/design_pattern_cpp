#include "Singelton.h"

Singelton::Singelton(int atr) {
	this->atr = atr;
	cout << "Constructor \n";
}

Singelton::~Singelton() {
	cout << "Destructor \n";
}

Singelton& Singelton::createInstance(int atr)
{
	static Singelton instance(atr);
	return instance;
}

