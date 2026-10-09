#include<iostream>
using namespace std;

int main(){
    vector<int> nums = {-14,61,29,-18,59,13,-67,-16,55,-57,7,74};

    int n = nums.size();

    int mini = INT_MAX;
    int maxi = INT_MIN;
    int minIndex = -1;
    int maxIndex = -1;

    for (int i=0; i<n; i++) {
        int curr = nums[i];

        if (curr < mini) {
            mini = curr;
            minIndex = i;
        }

        if (curr > maxi) {
            maxi = curr;
            maxIndex = i;
        }
    }

    cout<<endl<<"MIN (Index : Value) "<< minIndex <<" : "<<mini<<endl;
    cout<<endl<<"MAX (Index : Value) "<< maxIndex <<" : "<<maxi<<endl;
}