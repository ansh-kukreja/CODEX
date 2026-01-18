#include<iostream>
using namespace std;

class Function_call{
	int x,y;
    public:
    void add(int p, int q){
    	int total;
        x=p;
        y=q;
        total=x+y;
    
    	cout<<endl<<"Addition of two number using Call by Value is : "<<total<<endl;
    }
    
    void multiply(int *p, int *q){
    	int multi;
        x=*p;
        y=*q;
        multi=x*y;
        
        cout<<"Multiplication of two numbers using Call by Address is : "<<multi<<endl;
    }
    
    void divide(int &p, int &q){
    	int div;
        x=p;
        y=q;
        if(y==0){
        	cout<<"Denominator is Zero, Division not Possible"<<endl;
        }
        else{
        	div = x/y;
            cout<<"Division of two numbers using Call by Reference is : "<<div<<endl;
        }
    }
};

int main(){
	int n1,n2;
    cout<<endl;
    cout<<"Gauraansh, 2210997081";
    cout<<endl;
    cout<<"\t \t  --ENTER TWO INTEGERS--"<<endl;
    cout<<"Value of First Integer : ";
    cin>>n1;
    cout<<endl<<"Value of Second Integer : ";
    cin>>n2;
    Function_call obj;
    obj.add(n1,n2);
    obj.multiply(&n1, &n2);
    obj.divide(n1,n2);
}