#include<iostream>

using namespace std;

int main(){

    int amount = 4790;
    int n = amount;

int twoThousand, fiveHundred, twoHundred, oneHundred, fifty, twenty, ten, one;


twoThousand = n / 2000;

n = n % 2000;

fiveHundred = n / 500;

n = n % 500;

twoHundred = n / 200;

n = n % 200;

oneHundred = n / 100;

n = n % 100;

fifty = n / 50;

n = n % 50;

twenty = n / 20;

n = n % 20;

ten = n / 10;

n = n % 10;

one = n / 1;

n = n % 1;

cout<<"2000 : "<<twoThousand<<endl;
cout<<"500 : "<<fiveHundred<<endl;
cout<<"200 : "<<twoHundred<<endl;
cout<<"100 : "<<oneHundred<<endl;
cout<<"50 : "<<fifty<<endl;
cout<<"20 : "<<twenty<<endl;
cout<<"10 : "<<ten<<endl;
cout<<"1 : "<<one<<endl;

}