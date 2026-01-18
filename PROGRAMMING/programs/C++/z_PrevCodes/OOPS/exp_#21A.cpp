#include<iostream>
using namespace std;

class A{
	public:
		int x,y;
		void get(){
			cout<<"\nEnter Any two Numbers : ";
			cin>>x>>y;
		}
};

class B{
	public:
		int a,b;
		void get(){
			cout<<"\nEnter Any two Numbers : ";
			cin>>a>>b;
		}
};

class C : public A, public B{
	public:
		void disp(){
			A::get();
			B::get();
			cout<<"Addition of all variables is : "<<a+b+x+y;
		}
};

int main(){
	cout<<"\nGauraansh, 2210997081\n";
	C ob;
	ob.disp();
}
