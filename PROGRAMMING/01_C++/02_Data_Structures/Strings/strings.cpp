#include<iostream>
#include<limits>
using namespace std;


// ==== STRING is a Class in C++ also ====


int main(){
    string name, name2;

    cout<<"Enter Your Full Name: ";
    cin>>name;   // Stops when Space is Entered



    cin.ignore();   // clears leftover '\n'

    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clears all the leftover buffer in cin



    cout<<"Enter Your Full Name: ";
    getline(cin, name2);   // Doesn't Stops when Space is Entered


    cout<<"Kive aa "<<name<<endl;
    cout<<"Kive aa "<<name2<<endl<<endl;
    
    


    // =========================

    string s1 = "Hello";

    string s2("Hello");

    string s3(5, 'A');  // Stores "AAAAA"
    cout<<s3<<endl;


    // ==== Both are Correct/Same ====
    cout<<s2.length()<<endl;
    cout<<s2.size()<<endl;


    
    // =========================
    string s = "Hello";

    s.push_back('x');
    s.pop_back();

    s.erase(1,2);  // Hlo

    s.insert(1, "el"); // Hello

    cout << s;

    // =========================


    s = "Hello";

    cout<<endl<<"sizeof: " << sizeof(s);  // 's' is an Object of class 'string'
    cout<<endl<<"Size of: "<< s.size() <<endl<<endl;


    // ========================

    char a[20];
    // a = "Hello";    // This is NOT Allowed !!
    
}