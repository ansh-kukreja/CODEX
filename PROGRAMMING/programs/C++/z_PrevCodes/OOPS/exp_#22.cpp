#include <iostream>
using namespace std;

class base
{
	public:
		int x,y;
		void get()
		{
			cout<<"Input x and y : "<<endl;
			cin>>x>>y;
		}
};
class base1:virtual public base
{
	public:
		void mul()
		{
			cout<<"mul : "<<x*y<<endl;
		}
};
class base2:virtual public base
{
	public:
		void add()
		{
			cout<<"Add : "<<x+y<<endl;
		}
};
class base3:public base1 , public base2
{
	public:
		void disp()
		{
			cout<<"Sub : "<<x-y<<endl;
		}
};

int main()
{
	cout<<"\nGauraansh, 2210997081\n";
	base3 ob;
	ob.get();
	ob.mul();
	ob.add();
	ob.disp();
}