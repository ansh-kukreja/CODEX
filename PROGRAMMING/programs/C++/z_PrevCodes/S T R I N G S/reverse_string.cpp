#include<iostream>
using namespace std;

void reverse(char name[], int len){

    int s=0;
    int e=len-1;
    char temp;

    while( s<e ){

        temp = name[s];
        name[s] = name[e];
        name[e] = temp;
        s++;
        e--;
    }
    cout<<name;
}

int length(char name[]){

    int count = 0;

    for( int i = 0; name[i] != '\0'; i++){
        count++;
    }

return count;
}

int main(){

    char name[96];
    cout<<"Enter a Word : "; cin>>name;
    int len = length(name);
    cout<<"Reverse of "<<name<<" is : ";
    reverse(name, len);


}