#include<iostream>
using namespace std;

int main(){
    string s="lbg", t="g";
    int tlen = t.length();
    int slen = s.length();

    int ans = tlen;

    int i=0;
    int j=0;

    while(i < tlen && j < slen){
        if(t[i] == s[j]){
            ans--;
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    cout<<"Answer: "<<ans;

}