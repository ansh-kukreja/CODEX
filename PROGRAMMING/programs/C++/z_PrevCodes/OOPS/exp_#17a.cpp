#include<iostream>
using namespace std;

class rectangle{
	private:
		double length, width;
	public:
		rectangle(double l, double w){
			length = l;
			width = w;
		}
		friend double area(rectangle ob);
};
double area(rectangle ob){
	return ob.length * ob.width;
}
int main(){
	cout<<"Gauraansh, 2210997081\n";
	rectangle ob(15.0, 10.0);
	double ar = area(ob);
	cout<<"The Area of Rectangle is : "<<ar;
	cout<<endl;
}
