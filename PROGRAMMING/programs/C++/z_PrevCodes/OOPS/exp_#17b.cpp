#include<iostream>
using namespace std;

class person{
	
	private:
		string name;
		int age;
	public:
		person(string n, int a){
			name = n;
			age = a;
		}
	friend class student;
	void display(){
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
	}
};

class student{
	public:
		void show(person ob){
			cout<<"Name : "<<ob.name<<endl;
			cout<<"Age : "<<ob.age<<endl;
		}
};

int main(){
	person ob1("Ansh", 20);
	student ob2;
	ob1.display();
	ob2.show(ob1);
}


