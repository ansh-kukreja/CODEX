#include<iostream>
#include<queue>
using namespace std;


// ==== Custom Value for MinHeap ====
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

// ==== Custom Class to Compare two Values ====
class Compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};



vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {

    // ======= Created Custom Min Heap =======
    priority_queue<Node*, vector<Node*>, Compare> minHeap;


    // ===== Putting First Elements of All the Arrays ====
    for (int i=0; i<k; i++) {
        Node* curr = new Node(kArrays[i][0], i, 0);
        minHeap.push(curr);
    }

    vector<int> ans;

    while (!minHeap.empty()) {

        Node* smallest = minHeap.top();
        minHeap.pop();

        ans.push_back(smallest->data);

        smallest->j += 1;

        int i = smallest->i;
        int j = smallest->j;

        if (j < kArrays[i].size()) {

            Node* temp = new Node(kArrays[i][j], i, j);
            minHeap.push(temp);
        }
    }

    return ans;
}




int main() {

}