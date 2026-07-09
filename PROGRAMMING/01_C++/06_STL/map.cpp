#include<iostream>
#include<map>
using namespace std;

int main(){

    // ==== Unordered Map (can pass key and get value or pass value and get key) ====
    unordered_map<string, string> mapp;
    // ==============================================================================

    map<int,string> m;
    
    m[9] = "Ansh";
    m[0] = "Kukreja";

    m.insert({65,"Jack"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
}