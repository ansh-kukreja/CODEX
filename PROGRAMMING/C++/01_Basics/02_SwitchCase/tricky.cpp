#include<iostream>
using namespace std;

int main(){
    int i=0;
    while(true){

        switch(i){
            case 0:
                cout<<"Zero ";
                break;
            case 1:
                cout<<"One  ";
                break;
            case 2:
                cout<<"Two  ";
                exit(0);        //Exit Function in Switch Case
            default:
                cout<<"--@@--";
        }

        i++;
    }
}