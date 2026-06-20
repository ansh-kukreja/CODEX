#include<iostream>
using namespace std;

string revInvert(string st){
    for(int i=0; i<st.length(); i++){
        st[i] = (st[i] == '1') ? '0' : '1';
    }

    int s = 0;
    int e = st.length()-1;

    while(s<e){
        swap(st[s++], st[e--]);
    }
    return st;
}

char findKthBit(int n, int k) {
    string st = "0";

    for(int i=2; i<=n; i++){
        string post = revInvert(st);
        st = st + "1" + post;
    }

    cout<<endl;
    for(int i=0; i<st.length(); i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;

    
    return st[k];
}

int main(){
    findKthBit(3,1);
}