#include<iostream>
using namespace std;

int getLength(char arr[]){
    int count=0;

    for(int i=0; arr[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main(){
    char name[40];

    cout<<"Enter your Name : "; 
    cin>>name;

    cout<<"Kya haal hai "<<name<<" , Length is : "<<getLength(name)<<endl<<endl;



    // ============= Last Space is Reserved for '\0' =============
    // ====== Char Array of Size 'n' can only store 'n-1' elements =======

    // char arr[4] = "ABCD";



    int size = 90;
    char charArrayWithSpaces[size];
    cout<<"Enter a String with Spaces : ";
    cin.getline(charArrayWithSpaces, size);

    cout<<"Your String : "<<charArrayWithSpaces<<endl<<endl;


}