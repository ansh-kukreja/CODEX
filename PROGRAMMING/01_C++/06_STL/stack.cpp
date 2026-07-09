#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> s;

    s.push("Ansh");
    s.push("Kukreja");
    s.push("Dope");

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    s.pop(); 
}
