#include <iostream>
using namespace std;

class Sample
{
	public:
		int data;
		Sample(int data)
		{
			this->data=data;
		}
		void print()
		{
			cout<<"Data is "<<this->data;
            cout<<endl;
		}
		void setdata(int data)
		{
			this->data=data;
		}
		void display()
		{
			cout<<"Address of object "<<this;
            cout<<endl;
		}
};

int main()
{
    cout<<"Gauraansh, 2210997081"<<endl;
	Sample ob1(10);
	Sample ob2(20);
	ob1.print();
	ob2.print();
	ob1.setdata(25);
	ob1.print();
	ob1.display();
	ob2.display();
}