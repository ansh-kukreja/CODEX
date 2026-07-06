#include<iostream>
using namespace std;


class Node {
    public:
    int data;
    int i;
    int j;

    Node(int val, int row, int col) {
        data = val;
        i = row;
        j = col;
    }
};

class Compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<Node*, vector<Node*>, Compare> minHeap;
        int minRange = INT_MAX;
        vector<int> ans;

        int maxi = INT_MIN;

        for (int i=0; i<nums.size(); i++) {
            
            Node* curr = new Node(nums[i][0], i, 0);
            maxi = max(maxi, nums[i][0]);
            minHeap.push(curr);
        }

        while (!minHeap.empty()) {
            Node* mini = minHeap.top();
            minHeap.pop();

            if (maxi - mini->data < minRange) {
                minRange = maxi - mini->data;
                ans = {mini->data, maxi};
            }

            mini->j += 1;

            int i = mini->i;
            int j = mini->j;

            if (j < nums[i].size()) {

                Node* temp = new Node(nums[i][j], i, j);
                maxi = max(maxi, nums[i][j]);
                minHeap.push(temp);
            }
            else 
                return ans;
        }

        return ans;
    }
};


int main(){
    
}