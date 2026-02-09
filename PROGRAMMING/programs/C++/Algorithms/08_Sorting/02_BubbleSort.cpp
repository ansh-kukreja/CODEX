#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int arr[7] = {2,6,31,0,6,8,9};

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout<< "\nSorted : ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl<<endl;
}