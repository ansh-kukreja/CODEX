#include<iostream>
#include<map>
using namespace std;

int main(){

    // Ordered Map is Based on BST
    // Complexity is "O(logn)"
    // In Unordered Map T.C. is 'O(1)'
    
    unordered_map<string, int> map;


// ============ INSERTION WAYS ============
    pair<string, int> p1 = make_pair("Ansh", 7); 
    map.insert(p1);


    pair<string, int> p2("Kukreja", 9); 
    map.insert(p2);


    map["Overseas"] = 40;


// ============ SEARCHING WAYS ============
    cout<< map["Ansh"] << endl;

    cout<< map.at("Ansh") << endl;

// -- If we search for uncreated key using "map.at()" it will give error
// -- but if we search for uncreated key using "map[]" it will create an entry and returns "0"
// e.g.
    cout<< map["lol"] << endl;
    // cout<< map.at("llooll") << endl;



// ============ SIZE OF MAP ============
    cout<<"Size of Map is : "<< map.size() <<endl;


// ============ TO CHECK IF A KEY IS PRESENT OR NOT ============
   cout<<"Present or Not : "<< map.count("OOPS") <<endl;   // Returns '1' if Present and '0' if Absent


// ============ DELETING FROM MAP ============
    map.erase("Overseas");


// ============ ITERATING IN MAP ============
    cout<<"-------- MAP --------"<<endl;
    for(auto i: map){
        cout<<i.first<<" : "<<i.second<<endl;
    }
    cout<<"---------------------"<<endl;



    unordered_map<string, int> :: iterator it = map.begin();
    cout<<"-------- MAP --------"<<endl;
    while(it != map.end()){
        cout<< it->first <<" : "<< it->second <<endl;
        it++;
    }
    cout<<"---------------------"<<endl;

}