#pragma once
#include <iostream>

using namespace std;

class Singelton
{
private:
	Singelton(int atr);
	~Singelton();

public:
	static Singelton& createInstance(int atr);
	int atr;
};

