#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int s = 0;
        int e = nums.size() - 1;
        int mid = s + ((e-s)/2);

        if(target <= nums[0]) return 0;
        if(target > nums[nums.size()-1]) return nums.size();

        while(s < e){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }

            mid = s + ((e-s)/2);
        }
        return mid;
}

int main(){
    vector<int> a = {1,2,4,6};

    cout<<endl<<"Insert at : "<<binarySearch(a, 5)<<endl<<endl;
}