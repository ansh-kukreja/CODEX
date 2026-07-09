#include<iostream>

using namespace std;

string toString(int s, int e){
    string ans;
    char start = '0' + (s - 0);
    char end = '0' + (e - 0);
    ans.push_back(start);
    ans.push_back('-');
    ans.push_back('>');
    ans.push_back(end);
    return ans;
}

int main(){
    string s = toString(4,9);
    cout<<s;
}