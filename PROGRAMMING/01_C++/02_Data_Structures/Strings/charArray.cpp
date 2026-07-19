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
    cin>>name;  // Stops when Space is given as input

    cout<<"Kya haal hai "<<name<<" , Length is : "<<getLength(name)<<endl<<endl;



    // ============= Last Space is Reserved for '\0' called NULL character =============
    // ====== Char Array of Size 'n' can only store 'n-1' elements =======


    // char arr[4] = "ABCD";     ❌ -> Not Allowed


    int size = 90;
    char charArrayWithSpaces[size];
    cout<<"Enter a String with Spaces : ";
    
    cin.getline(charArrayWithSpaces, size);

    cout<<"\nYour String : "<<charArrayWithSpaces<<endl<<endl;



    char str3[40] = {'a','b','c','d'};
    char str4[40] = "Ansh";
}