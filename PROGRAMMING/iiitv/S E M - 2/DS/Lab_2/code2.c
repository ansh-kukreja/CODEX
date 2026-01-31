#include<stdio.h>

int main(){
    int size = 9;
    int arr[9] = {1,2,3,4,7,4,3,2,1};

    int s = 0;
    int e = size-1;

    int isPalindrome = 1;

    while(s < e){
        if(arr[s] != arr[e]){
            isPalindrome = 0;
            break;
        }
        s++;
        e--;
    }

    if(isPalindrome){
        printf("\nArray is Palindrome!\n\n");
    }
    else{
        printf("\nArray is NOT Palindrome!\n\n");
    }
}