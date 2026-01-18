#include<iostream>
using namespace std;

int main(){
    int n=1330;
    int no;

    cout<<"Enter Your Desired Note from 100,50,20,1 : "; cin>>no;

    switch(no){

        case 100:{int a=n/100;
                    cout<<"You Need " <<a <<" Notes of 100";}
                    break;

        case 50:{int a=n%100;
                 int b=a/50;
                    cout<<"You Need " <<b <<" Notes of 50";}
                    break;

        case 20:{int a=n%100;
                int b=a/20;
                    cout<<"You Need " <<b <<" Notes of 20";}
                    break;

        case 1:{int a=n%100;
                int b=a%20;
                int c=b/1;
                    cout<<"You Need "<<c <<" Notes Of 1";}
                    break;

        default:{
            cout<<"Error Occured";
        }


    }
    return 0;
}