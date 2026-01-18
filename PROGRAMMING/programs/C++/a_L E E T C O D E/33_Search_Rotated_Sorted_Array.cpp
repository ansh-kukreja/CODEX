#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> arr, int n){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}


int binarySearch(vector<int> arr, int s, int e, int target){
    int mid = s + (e-s)/2;
    // cout<<"XXXX "<<s<<" "<<e<<" "<<mid<<" ";
    // if(s==e && arr[e] == target){
    //     return e;
    // }

    while(s <= e){
        if(arr[s] == target){
            return s;
        }
        if(arr[e] == target){
            return e;
        }
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] < target){
            s=mid+1;
        }
        if(arr[mid] > target){
            e= mid-1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
        if(nums[0] > nums[nums.size()-1]){

            int pivot = findPivot(nums, nums.size());
            //cout<<"Pivot : "<<pivot<<endl;

            if(target >= nums[pivot] && target <= nums[nums.size() - 1]){
                //cout<<"XXOOXOXOXOXO"<<endl;
                return binarySearch(nums, pivot, nums.size()-1, target);
            }
            else{
                return binarySearch(nums, 0, pivot-1, target);
            }
        }
        else{
            return binarySearch(nums, 0, nums.size()-1, target);
        }
}

int main(){
    vector<int> arr={7,8,1,2,3,4,5,6};
    int a = search(arr, 2);
    cout<<"Answer Index: "<<a;
}