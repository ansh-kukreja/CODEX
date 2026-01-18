#include<iostream>
using namespace std;

class counter{
	int x = 9;
	public:
	void operator++(){
		x+=1;
	}
		
	void disp(){
		cout<<x<<endl;
	}
		
};

int main(){
	cout<<"Gauraansh, 2210997081\n";
	
	counter w;
	w.disp();
	++w;
	w.disp();
}
