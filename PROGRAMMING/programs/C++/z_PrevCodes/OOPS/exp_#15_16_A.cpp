#include<iostream>
using namespace std;

int add(int a, int b){
	return (a+b);
}
int sub(int a, int b){
	return(a-b);
}

int main(){
	cout<<"Gauraansh, 2210997081";
    cout<<endl;
	int(*fun)(int,int);
	fun = add;
	int result = fun(5,10);
	cout<<"Addition is : "<<result<<endl;
	fun = sub;
	result = fun(10,2);
	cout<<"Subtraction is : "<<result<<endl;
	
}