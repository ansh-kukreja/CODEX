#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare {
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (int i=0; i<lists.size(); i++) {
            if (!lists[i]) continue;

            minHeap.push(lists[i]);
        }

        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        while (!minHeap.empty()) {

            ListNode* currMin = minHeap.top();
            minHeap.pop();

            tail->next = currMin;
            tail = tail->next;

            if (currMin->next)
                minHeap.push(currMin->next);
        }

        return head->next;
    }
};




int main(){
    
}