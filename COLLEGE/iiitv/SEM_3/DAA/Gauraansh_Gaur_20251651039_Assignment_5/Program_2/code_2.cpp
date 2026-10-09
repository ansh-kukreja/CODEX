#include<iostream>
using namespace std;

bool linearSearch(vector<int>& nums, int n, int a) {
    for (int i=0; i<n; i++) {
        if (nums[i] == a) 
            return true;
    }

    return false;
}

bool binarySearch(vector<int>& nums, int n, int a) {
    
    int s = 0;
    int e = n-1;
    int mid = s + ((e-s)/2);

    while(s <= e) {
        if (nums[mid] == a)
            return true;
        
        if (nums[mid] < a) {
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + ((e-s)/2);
    }

    return false;
}

bool ternarySearch(vector<int>& nums, int left, int right, int a) {
    if (left > right)
        return false;

    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (nums[mid1] == a || nums[mid2] == a)
        return true;

    if (a < nums[mid1]) 
        return ternarySearch(nums, left, mid1 - 1, a);
    
    else if (a > nums[mid2]) 
        return ternarySearch(nums, mid2 + 1, right, a);
    
    else 
        return ternarySearch(nums, mid1 + 1, mid2 - 1, a);
    
}

int main(){
    vector<int> nums = {4,5,8,14,17,24,40,49,64};
    int n = nums.size();

    bool found;
    found = linearSearch(nums, n, 40);

    if (found) cout<<"\n\n== Found - from Linear Search ==";
    else cout<<"\n\n== Not Found - from Linear Search ==";


    found = binarySearch(nums, n, 40);

    if (found) cout<<"\n\n== Found - from Binary Search ==";
    else cout<<"\n\n== Not Found - from Binary Search ==";


    found = ternarySearch(nums, 0, n-1, 40);

    if (found) cout<<"\n\n== Found - from Ternary Search ==\n\n";
    else cout<<"\n\n== Not Found - from Ternary Search ==\n\n";

}