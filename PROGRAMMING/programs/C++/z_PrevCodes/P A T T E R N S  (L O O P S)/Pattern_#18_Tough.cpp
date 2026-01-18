#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Number: "; cin>>n;

    int i = 1;

    while(i<=n){

        int space=n-i;
        while(space){
            cout<<'_';
            space=space-1;
            
        }

        int j=1;
        int py=1;
        while(j<=i){
            cout<<py;
            py=py+1;
            j=j+1;
        }
        
        int i2=i-1;
        while(i2){
            cout<<i2;
            i2=i2-1;
        }
        
        cout<< endl;
        i=i+1;        
    }

    return 0;
}