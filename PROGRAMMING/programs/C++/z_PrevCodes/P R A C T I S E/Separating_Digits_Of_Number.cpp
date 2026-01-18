#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Number: "; cin>>n;

    int one=n%10;    //4
    int i=n/10;      //23
    int two=i%10;      //3
    int three=i/10;      //2

    cout<<"This no is at one's Place: "<<one<<endl;
    cout<<"This no is at ten's Place: "<<two<<endl;
    cout<<"This no is at hundred's Place: "<<three<<endl;

    return 0;
}