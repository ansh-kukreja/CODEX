// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<"Enter The Number: "; cin>>n;

//     int i=1;

//     while(i<=n){
//         int j=1;
//         while(j<=n){
//             int a=n-i;
//             int b=1;
//             while(b<=a){
//                 cout<<' ';
//                 b=b+1;
//                 j=j+1;
//             }
//             int c=i;
//             int d=1;
//             while(d<=c){
//                 cout<<"*";
//                 d=d+1;
//                 j=j+1;
//             }
            
//         }
//         cout<< endl;
//         i=i+1;
//     }

//     return 0;
// }


//                                     A L T E R N A T E   &  E A S Y   W A Y   B Y   M E

// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     int i =1;

//     cout<<"Enter A Number: "; cin>>n;

//     while(i<=n) {
//         int j=1;
//         int k=1;

//         while(j<=(n-i)){
//             cout<<'-';
//             j++;
//         }

//         while(k<=i){
//             cout<<'*';
//             k++;
//         }
        
//         cout<<"\n";
//         i++;
//     }
//     return 0;
// }

                                    //    A L T E R N A T E  A N D  E A S Y  W A Y


#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter The Number: "; cin>>n;

    int i=1;

    while(i<=n){
        int space=n-i;
        while(space){
            cout<<' ';
            space=space-1;
        }

        int star=1;
        while(star<=i){
            cout<<'*';
            star=star+1;

        }
        cout<< endl;
        i=i+1;
    }
        return 0;
    }
