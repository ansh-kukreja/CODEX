#include<iostream>
using namespace std;

int main(){
    int n = 9; // -9  ########### For -9 write 9  ###################

    int bi[32] = {0};

    int num=n;
    
    //#################   1's Compliment  #####################
    for(int i=31; i>=0; i--){
        int ld = num&1;
        num = num >> 1;
        if(ld == 0){
            bi[i] = 1;
        }
        else{
            bi[i] = 0;
        }
    }

    //################  2's Compliment  ###################
    int exit=0;
    int index = 31;

    while(!exit){
        int carry=0;
        if(bi[index] == 0){
            bi[index] = 1;
            exit = 1;
        }
        else{
            bi[index] = 0;
            index--;
        }
    }



    for(int i=0;i<32; i++){
        cout<<bi[i]<<" ";
    }
}