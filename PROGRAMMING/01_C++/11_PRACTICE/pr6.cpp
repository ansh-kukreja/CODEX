#include<iostream>
#include<vector>
using namespace std;

vector<int> limitOccurrences(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> ans;

    for(int i=0; i<n; i++) {
        int count = 1;
        while((i < n-1) && (nums[i] == nums[i+1])) {
            if(count <= k) ans.push_back(nums[i]);
            count++;
            i++;
        }
        if(count <= k) ans.push_back(nums[i]);
    }
    return ans;
}

int main(){
    vector<int> a = {1,1,1,2,2,3};
    int k= 2;

    vector<int> ans = limitOccurrences(a, k);

    cout<<endl<<endl;
    for(auto i : ans) cout<<i<<" ";
    cout<<endl<<endl;

}