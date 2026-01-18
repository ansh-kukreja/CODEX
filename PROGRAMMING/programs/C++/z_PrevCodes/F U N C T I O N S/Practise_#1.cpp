#include<iostream>
using namespace std;

int sumf(int arr[], int n){
    int sum=0;

    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
}

int main(){
    int arr[100];
    int a;
    cout<<("Enter The Number OF Entries : "); cin>>a;

    for(int i=0;i<a;i++){
        cout<<("Enter "); cout<<i+1; cout<<(" Value : ");
        cin>>arr[i];
    }

    int ans=sumf(arr,a);
    cout<<ans;


}