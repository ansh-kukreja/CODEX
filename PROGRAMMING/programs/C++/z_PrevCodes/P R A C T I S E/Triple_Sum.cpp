#include<iostream>
using namespace std;

int main(){
    int arr[6]={1,2,3,4,5,6};

    for(int i=0;i<6;i++){
        int j=i+1;
        for(j;j<6;j++){
            int k=j+1;
            for(k;k<6;k++){
                if((arr[i]+arr[j]+arr[k])==12){
                    cout<<arr[i]<<arr[j]<<arr[k];
                    cout<<endl;

                }
                
            }
        }
    }
}