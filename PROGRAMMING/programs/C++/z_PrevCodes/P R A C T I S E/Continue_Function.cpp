#include<iostream>
using namespace std;

int main(){
    for(int i=0; i<5; i++){

        cout<< "Hi!"<< endl;
        cout<< "Hey!"<< endl;
        continue;

        // NOW BELOW PART IS UNREACHABLE / UNREADABLE

        cout<< "HELLO!"<< endl;
        cout<< "HOLA!"<< endl;
    }

    return 0;
}