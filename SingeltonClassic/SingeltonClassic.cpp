
#include <string>
#include <iostream>
#include <vector>
#include <thread>
using namespace std;

class Singleton {
private:
	// static pointer which will points to the instance of this class
	static Singleton* instancePtr;

	Singleton(int atr)
	{
		this->atr = atr;
	}

public:
	int atr;

	// deleting copy constructor
	Singleton(const Singleton& obj) = delete;

	/*
		getInstance() is a static method that returns an instance when it is invoked. It is static because we have to invoke this
		method without any object of Singleton class and static method can be invoked without object of class
	*/
	static Singleton* getInstance(int atr)
	{
		if (instancePtr == NULL)
		{
			instancePtr = new Singleton(atr);
			cout << "New instance created \n" << endl;

			return instancePtr;
		}
		else
		{
			return instancePtr;
		}
	}

};

// initializing instancePtr with NULL
Singleton* Singleton::instancePtr = NULL;

int main()
{
	Singleton* obj1 = Singleton::getInstance(12);

	Singleton* obj2 = Singleton::getInstance(1);

	cout << "obj1 " << obj1->atr << endl;
	cout << "obj2 " << obj2->atr << endl;

	//vector<thread> threads;

	//for (int i = 0; i < 5; i++) {
	//	threads.emplace_back(thread([i]() {
	//		Singleton::getInstance(i);
	//	}));
	//}

	//for (auto& t : threads) {
	//	cout <<  t.get_id() << endl;
	//	if (t.joinable()) {
	//		t.join();
	//	}
	//}
	return 0;
}
