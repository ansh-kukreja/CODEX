#include<iostream>
using namespace std;

int main() {

    cout<<"\nHarpreet , 2210997092\n\n";

    int num1, num2, num3;
    int largest, secondLargest, smallest;

    cout<<"Enter the First Number : ";
    cin>>num1;
    cout<<"\nEnter the Second Number : ";
    cin>>num2;
    cout<<"\nEnter the Third Number : ";
    cin>>num3;
    cout<<endl;


// finding largest

    if (num1 >= num2 && num1 >= num3){
        largest = num1;
    }
    else if (num2 >= num1 && num2 >= num3){
        largest = num2;
    }
    else{
        largest = num3;
    }


// finding smallest

    if (num1 <= num2 && num1 <= num3){
        smallest = num1;
    }
    else if (num2 <= num1 && num2 <= num3){
        smallest = num2;
    }
    else{
        smallest = num3;
    }
        

// finding second largest

    if(num1 != largest && num1 != smallest){
        secondLargest = num1;
    }
    else if(num2 != largest && num2 != smallest){
        secondLargest = num2;
    }
    else{
        secondLargest = num3;
    }

    cout << "Largest: " << largest << endl;
    cout << "Second Largest: " << secondLargest << endl;
    cout << "Smallest: " << smallest << endl;

}