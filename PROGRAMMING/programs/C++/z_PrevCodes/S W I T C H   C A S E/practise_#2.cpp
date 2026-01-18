#include<iostream>
using namespace std;

int main(){
    int n=1330;
    int no;

    cout<<"Enter Your Desired Note from 1, 2, 3, 4 : "; cin>>no;

    switch(no){

        case 1:{
            cout<<"One\n";
        }
                    break;

        case 2:{
            cout<<"Two\n";
        }
                    break;

        case 3:{
            cout<<"Three\n";
        }
                    break;

        case 4:{
            cout<<"Four\n";
        }

        default:{
            cout<<"Error Occured\n";
        }


    }
    return 0;
}