#include<stdio.h>

int main(){
    int arr[9]={1,2,4,7,26,54,67,96,98};
    int find=54;




    int s=0;
    int e=8;
    int m=(s+e)/2;

    while(s<=e){

    if(arr[m]==find){
        printf("The Required Element Is at %d Index", m);
        break;
    }
    else if(arr[m]>find){
        e=m-1;
    }
    else if(arr[m]<find){
        s=m+1;
    }
    m=(s+e)/2;

    }

}

