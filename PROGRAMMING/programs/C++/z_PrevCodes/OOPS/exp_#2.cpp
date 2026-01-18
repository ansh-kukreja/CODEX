#include<iostream>
using namespace std;

int main(){
    int a,toggle,check = 0;

    cout<<"\nGauraansh 2210997081\n\n";
    cout<<"Enter a Number : ";
    cin>>a;
    cout<<endl;

    cout<<"MENU ~\n";
    cout<<"Enter 1 for checking Even or Odd\n";
    cout<<"Enter 2 for checking Prime\n";
    cout<<"Enter 3 to exit..\n";
    cout<<"ENTER HERE --> : ";
    cin>>toggle;

    switch(toggle){
        case 1:
        {
            if((a % 2) == 0){
                cout<<"Number is an Even number";
            }
            else{
                cout<<"Number is an Odd number";
            }
        }
        break;

        case 2:
        {
            for(int i = 2; i < a; i++){
                if(a % i == 0){
                    check++;
                }
            }

            if(check == 0){
                cout<< "Number is a Prime Number";
            }
            else{
                cout<<"Number is not a Prime number";
            }
        }
        break;

        case 3:
        {
            cout<<"Exiting the Program..";
        }
        break;

        default:
        {
            cout<<"Invalid Input!!";
        }
    }
}