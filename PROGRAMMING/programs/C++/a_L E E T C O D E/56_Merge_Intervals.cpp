#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    vector<vector<int>> intervals = {{1,4}, {4,6}, {3,7}, {9,12}, {12,14}};  // 1,7  9,14
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> temp;

    for(int i=0; i<intervals.size(); i++){
        if(i == 0){
            ans.push_back(intervals[0]);
        }
        else{
            vector<int>&lastPushedInterval= ans.back();

            if(intervals[i][0] <= lastPushedInterval[1]){
                lastPushedInterval[1] = max(intervals[i][1], lastPushedInterval[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
    }


    for(int i=0; i<ans.size(); i++){
        cout<<"{"<<ans[i][0]<<","<<ans[i][1]<<"}"<<" ";
    }

}