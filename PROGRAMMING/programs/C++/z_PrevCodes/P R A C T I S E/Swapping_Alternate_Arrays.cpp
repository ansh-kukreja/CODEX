#include<iostream>
using namespace std;

int main(){
    int n[9]={1,2,3,4,5,6,7,8,9};
    int in=9;
    

    for(int i=0;i<in;i+=2){
        if((i+1)<+in){
            swap(n[i],n[i+1]);
        }

    }

    for(int x=0;x<9;x++){
        cout<<n[x]; cout<<endl;

    }
}