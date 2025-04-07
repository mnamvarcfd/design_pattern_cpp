#include <iostream>

using namespace std;

enum ShapeType {
	CIRCLE,
	RECTANGLE
};

class Shape {

public:
	virtual double area() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {

private:
	int radius;

public:
	Circle(int radius) {
		this->radius = radius;
	}

	double area()
	{
		return 3.14 * radius * radius;
	}
};

class Rectangle : public Shape {
private:
	int length;
	int height;

public:
	Rectangle(int length, int height) {
		this->length = length;
		this->height = height;
	}

	double area()
	{
		return double(length) * double(height);
	}
};


class ShapeFactory {
public:
	static Shape* build(ShapeType shapeType)
	{
		if (shapeType == CIRCLE)
			return new Circle(1);
		else if (shapeType == RECTANGLE)
			return new Rectangle(1,2);
		else
			return nullptr;
	}
};


int main()
{
	Shape* pShape;

	pShape = ShapeFactory::build(CIRCLE);
	cout<< "Circle area is: " << pShape->area() << endl;

	pShape = ShapeFactory::build(RECTANGLE);
	cout << "Rectangle area is: " << pShape->area() << endl;

	return 0;
}
