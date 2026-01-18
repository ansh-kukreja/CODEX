#include<iostream>
using namespace std;

int powerF(int n, int pow){
    int ans = n;
    if(pow == 0){
        return 1;
    }
    for(int i=1; i<pow; i++){
        ans = ans * n;
    }
    return ans;
}

int bitwiseComplement(int n) {
    int temp = n, count = 0;
    int mask = 0;

    while(temp != 0){
        count++;
        temp = temp >> 1;
    }

    for(int i=count-1; i>=0; i--){
        mask = mask + powerF(2, i);
    }

    return (~n) & mask;
}

int main(){
    // cout<<bitwiseComplement(5);
    cout<<powerF(10,9);
}