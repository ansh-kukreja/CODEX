#include<iostream>
using namespace std;

void printRevCounting(int n){
    if (n == 0)
    return;

    cout<<n<<" ";
    printRevCounting(n-1);
}

void printCounting(int n){
    if (n == 0)
    return;

    printRevCounting(n-1);
    cout<<n<<" ";
}

int main(){
    printRevCounting(9);
    cout<<endl;
    printCounting(9);
}