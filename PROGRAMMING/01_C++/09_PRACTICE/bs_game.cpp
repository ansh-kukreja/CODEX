#include<iostream>
using namespace std;

int main(){
    cout<<"\n\nThink a number b/w 1-100,000\n\n";

    cout<<"-- Starting the Guess Game --\n\n";

    int n = 100000;


    int s=1;
    int e=n;
    int mid = s + (e-s)/2;
    int gCount = 1;

    while(s <= e){
        int input;
        cout<<"\nIs your number "<<mid<<" ??";
        cout<<"\nGuess No: "<<gCount++;
        cout<<"\nEnter 1 for Yes\nEnter 0 for No: ";
        cin>>input;

        if(input == 1){
            cout<<"\n\nI feel like Godd hahahaha!!\n\n";
            break;
        }
        else{
            int inp;
            cout<<"\n\nIf your number is Less then my Guess then Enter 1 else Enter 2: ";
            cin>>inp;

            if(inp == 1){
                e = mid-1;
            }
            else{
                s = mid+1;
            }

            mid = s + (e-s)/2;
        }
    }

}


// 93649