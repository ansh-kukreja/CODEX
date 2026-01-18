#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<string> s;

    s.push("Ansh");
    s.push("Kukreja");
    s.push("Dope");

    cout<<s.front();
    s.pop();
    cout<<s.size();
    cout<<s.empty();
    

}
