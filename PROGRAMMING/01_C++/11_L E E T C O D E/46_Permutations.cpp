#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int>>& ans, int index){
    if(index >= nums.size()-1){
        ans.push_back(nums);
        return;
    }

    for(int i=index; i<nums.size(); i++){
        swap(nums[i], nums[index]);
        solve(nums, ans, index+1);

        // back-tracking
        swap(nums[i], nums[index]); 
    }
}

int main(){
    vector<int> nums = {4,5,6};
    vector<vector<int>> ans;
    solve(nums, ans, 0);
    
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}


    