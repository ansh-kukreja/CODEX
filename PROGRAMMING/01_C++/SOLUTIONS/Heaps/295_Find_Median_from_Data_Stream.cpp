#include<iostream>
#include<queue>
using namespace std;


class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    double median = INT_MIN;

    void insert(int num) {
        int a = maxHeap.size();
        int b = minHeap.size();

        if (a == b) {
            if(num >= median) {
                minHeap.push(num);
                median = minHeap.top();
            }
            else {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if (a > b) {
            if (num >= median) {
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
        else if (a < b){
            if (num >= median) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
            else {
                maxHeap.push(num);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
            }
        }
    }

    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        insert(num);
    }
    
    double findMedian() {
        return median;
    }
};




int main(){
    
}