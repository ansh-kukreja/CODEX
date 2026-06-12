#include<iostream>
#include<math.h>
using namespace std;

// ####### the default "pow" function sometimes gives incorrect outputs in offline compilers. ########
int fpow(int i, int j){
    int ans=1;
    for(int k=0; k<j; k++){
        ans *= i;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;

    int ans = 0;
    int i=0;

    while(n !=0 ){
        int bit = n & 1;
        ans = (bit * fpow(10,i++)) + ans;
        n = n >> 1;
    }

    cout<<"Answer: "<<ans;
}