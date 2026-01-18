#include<iostream>
using namespace std;

void fiboSeries(int n){

    int a = 0, b = 1, next;
    cout<<"Series : ";

    for(int i = 0; i<n; i++){

        cout<<a<<" ";
        next = a+b;
        a=b;
        b=next;
    }
    cout<<endl;
}

void isPalindrome(int num){

    int originalNum = num;
    int reverseNum = 0;

    while( num>0 ){
        int digit = num % 10;
        reverseNum = reverseNum * 10 + digit;
        num = num / 10;
    }

    if(originalNum == reverseNum){
        cout<<originalNum<<" : is a Palindrome number";
    }
    else{
        cout<<originalNum<<" : is Not a Palindrome Number";
    }

}

void isArmstrong(int num){

    int arm,temp,n;
    n = num;

    while( num>0 ){
        temp = num % 10;
        num = num / 10;
        arm = arm + (temp * temp * temp);
    }

    if( arm == n){
        cout<<"Number is Armstrong";
    }
    else{
        cout<<"Number is not an armstrong number";
    }
}

int main(){

    int choice, num;

    cout<<"\nGauraansh 2210997081\n\n";
    cout<<"\n Menu \n";
    cout<<"Press 1 to Generate Fibonacci Series\n";
    cout<<"Press 2 to Check Palindrome\n";
    cout<<"Press 3 to Check Armstrong\n";
    cout<<"Press 4 to Exit\n";
    cout<<endl;
    cout<<"Enter Your Choice : "; cin>>choice;

    switch(choice){

        case 1: {
            cout<<"Enter the number of Digits you want in the series : "; cin>>num;
            fiboSeries(num);
            break;
        }

        case 2: {
            cout<<"Enter the number you want to check : "; cin>>num;
            isPalindrome(num);
            break;
        }

        case 3: {
            cout<<"Enter the number you want to check : "; cin>>num;
            isArmstrong(num);
            break;
        }
        case 4: {
            return 0;
        }
        default: {
            cout<<"Invalid Input!";
        }
    }
}