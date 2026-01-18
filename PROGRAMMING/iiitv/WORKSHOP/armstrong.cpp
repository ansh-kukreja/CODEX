#include<iostream>
using namespace std;

int numOfDigits(int n){
    if(n == 0) return 1;
    
    int count = 0;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;
}

int power(int n, int p){
    int ans = 1;

    for(int i=0; i<p; i++){
        ans *= n;
    }

    return ans;
}

int main(){
    int n = 153;

    int p = numOfDigits(n);
    int ans = 0, temp = n;

    while(temp > 0){
        int digit = temp % 10;
        ans += power(digit, p);
        temp /= 10;
    }

    if(ans == n){
        cout<<endl<<"Number is Armstrong"<<endl;
    }
    else{
        cout<<endl<<"Number is Not Armstrong"<<endl<<endl;
    }

}