#include<iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 21 34 55 89

int findFib(int n){
    cout<<"N: "<<n<<endl;
    if(n == 0){
        cout<<"-- In 0 --"<<endl;
        return 0;
    }
    if(n == 1){
        cout<<"-- In 1 --"<<endl;
        return 1;
    }

    int ans =  findFib(n-1) + findFib(n-2);
    cout<<"ANS: "<<ans<<endl;
    return ans;
}

int main(){
    int n = 4;
    cout<<findFib(n);
}