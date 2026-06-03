#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> nums = {4,3,2,7,8,2,3,1};
    int n = nums.size();

        nums.push_back(0);
        vector<int> res;
        for (int i = 0; i <= n ; ++i)
        {
            while(nums[i] != nums[nums[i]])  //  -------\__>
                swap(nums[i], nums[nums[i]]); // -------/  >  #######  Un-Identified Sorting Algorithm  #########
        }
        for (int i = 0; i <= n; ++i)
        {
            cout<<nums[i]<<" ";
            if (nums[i] != i)
                res.push_back(nums[i]);
        }
}