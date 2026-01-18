#include<iostream>
using namespace std;

class Shape{
	
	public:
		int l, b, s;
		
		void getVal(){
			cout<<"Enter Length : "; cin>>l;
			cout<<"Enter Breadth : "; cin>>b;
			cout<<"Enter Side : "; cin>>s;
		}
};

class Rectangle: public Shape{
	public:
	void rectArea(){
		cout<<"Area of Rectangle is : "<<l*b;
		cout<<endl;
	}
};

class Square: public Rectangle{
	public:
	void areaSq(){
		cout<<"Area of Square is : "<<s*s;
		cout<<endl;
	}
};

int main(){
	cout<<"Gauraansh, 2210997081\n";

	Square x;
	x.getVal();
	cout<<endl;
	x.rectArea();
	x.areaSq();
	
}
