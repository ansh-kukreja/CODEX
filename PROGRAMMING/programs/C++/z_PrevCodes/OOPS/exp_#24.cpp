#include <iostream>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;
};

class Circle : public Shape 
{
public:
	//int radius;
    Circle(double r)
	{
		radius=r;
	}

    void calculateArea()  
	{
        cout << "Area of the circle: " << 3.14159 * radius * radius << endl;
    }

private:
    double radius;
};

class Rectangle : public Shape 
{
public:
    Rectangle(double l, double w) 
	{
		length=l;
		width=w;
	}

   void calculateArea() 
	{
        cout << "Area of the rectangle: " << length * width << endl;
    }

private:
    double length;
    double width;
};

int main() 
{
    cout<<"\nGauraansh, 2210997081\n";
	Shape *ptr;
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

   circle.calculateArea();
   rectangle.calculateArea();

    return 0;
}
