#include <iostream>
using namespace std;

class vehicle
{
	public:
		virtual void StartEngine()
		{
			cout<<"Vehicle's Engine Started"<<endl;
		}
};
class car:public vehicle
{
	public:
		void StartEngine()
		{
			cout<<"Car's Engine Started"<<endl;
		}
};
int main()
{
	cout<<"\nGauraansh, 2210997081\n";
	vehicle v;
	car c;
	vehicle *ptr;
	ptr = &v;
	ptr->StartEngine();
	ptr = &c;
	ptr->StartEngine();
}