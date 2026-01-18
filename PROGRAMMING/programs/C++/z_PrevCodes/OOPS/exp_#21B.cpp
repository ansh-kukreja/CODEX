#include<iostream>
using namespace std;

class A{
	public:
		static int x, y;
		void get(){
			cout<<"Enter x and y : "; cin>>x>>y;
		}
};

class B: public A{
	public:
		void add(){
			cout<<"Addition of X and Y is : "<<x+y<<endl;
		}
};

class C: public A{
	public:
		void sub(){
			cout<<"Subtraction of X and Y is : "<<x-y<<endl;
		}
};

class D:public A{
	public:
		void mul(){
			cout<<"Multiplication of X and Y is : "<<x*y<<endl;
		}
};
int A::x;
int A::y;

int main(){
	cout<<"\nGauraansh, 2210997081\n";
	D ob1;
	B ob2;
	C ob3;
	
	ob1.get();
	ob2.add();
	ob3.sub();
	ob1.mul();
}
