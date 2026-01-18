#include<iostream>

using namespace std;

int main(){

    char a;
    char ans;
    cout<<"Enter any UpperCase Alphabet : "; cin>>a;

    if(a >= 'a'  && a <= 'z'){
        cout<<a;
    }
    else{
        ans = (a - 'A') + 'a';
        cout<<ans;
    }
}