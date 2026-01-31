#include<iostream>
#include<stack>
using namespace std;


/* ====== Finding FIRST SMALLER NUMBER that we gets in the RIGHT SIDE of a number, 
          for EACH NUMBER in the given ARRAY ======
*/

vector<int> nextSmallerElement(vector<int> arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];

        while(s.top() >= curr){
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    int size = 4;
    vector<int> arr(size);

    arr = {1,3,2,4};

    vector<int> ans = nextSmallerElement(arr, size);


    cout<<endl<<"Answer Array: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}