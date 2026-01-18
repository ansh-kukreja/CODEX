#include<iostream>
using namespace std;

int findNumber(int arr[], int size, int num){
    int start=0;
    int end=size-1;
    int mid= (start+end)/2;

    while(start<=end){
        if(arr[mid] == num){
            return mid;
        }
        else if(num>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;

    }
    return -1;
}

int main(){
    int oddarr[7]={2,7,9,20,98,99,109};
    int evenarr[8]={1,4,6,8,54,69,78,96};

    int index1=findNumber(oddarr,7,2);
    int index2=findNumber(evenarr,8,96);

    cout<<"Index of Your Number 1 is : "<<index1<<endl;
    cout<<"Index of Your Number 2 is : "<<index2<<endl;

}