#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Number: "; cin>>n;

    int i=1;

    while(i<=n){
        int j=1;
        while(j<=n){
            char ch='A'+i-1;
            cout<<ch;           //Practise to make Formulaes like this: 'A'+i-1

            j=j+1;

        }
        cout<< endl;
        i=i+1;
    }

    



    return 0;
}