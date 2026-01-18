#include<iostream>
using namespace std;

int getLength( char name[] ){

        int len = 0;

        for(int i=0; name[i] != '\0'; i++){
            len++;
        }
        return len;

    }

int main(){

    char name[69];

    cout<<"Enter your name : ";
    cin>>name;
    cout<<endl;
    cout<<"Length of your name is : "<<getLength(name);
}