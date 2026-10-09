#include <iostream>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}


int main() {
    vector<int> arr = {49,24,40,4,8,64,5,14,17};
    int n = arr.size();

    cout << "\n\nOriginal array: ";
    for (int x : arr)
        cout << x << " ";

    mergeSort(arr, 0, n-1);

    cout << "\n\nSorted array: ";
    for (int x : arr)
        cout << x << " ";

    cout<<endl<<endl;
}