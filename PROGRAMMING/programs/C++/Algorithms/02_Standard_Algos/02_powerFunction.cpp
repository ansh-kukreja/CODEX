#include<iostream>
using namespace std;

int optimizedPower(int x, int n){
    long long power = n;
    if(power < 0){
        x = 1 / x;
        power = -power;
    }

    double ans = 1.0;

    while(power){
        if(power & 1) ans *= x;
        x *= x;
        power >>= 1;
    }

    return ans;
}

int main(){
    cout<<optimizedPower(4,7)<<endl;
}