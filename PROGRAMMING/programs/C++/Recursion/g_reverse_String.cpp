#include<iostream>
using namespace std;

void revStr(string &str, int s, int e){
    if(s >= e){
        return;
    }
    char temp = str[s];
    str[s] = str[e];
    str[e] = temp; 

    revStr(str, ++s, --e);
}


int main(){
    string x;
    cout<<"Enter a String: "; cin>>x;
    int s = x.length();

    revStr(x, 0, s-1);
    cout<<x;
}