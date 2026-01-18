#include<iostream>
using namespace std;

class student{
	
	string name;
	double roll;
	double phone;
	string city;
	int marks[5];
	int average_marks;
	int sum = 0;
	int i;
	
	public:
	void get(){
		cout<<"Enter The Name of Student : "; cin>>name;
		cout<<"Enter Roll No. of Student : "; cin>>roll;
		cout<<"Enter Phone No. of Student : "; cin>>phone;
		cout<<"Enter The City of Student : "; cin>>city; cout<<endl;
		cout<<"* Enter Marks in 5 Subjects *"; cout<<endl;
		cout<<endl;
		for(i=0; i<5; i++){
			cout<<"Enter Marks of Subject "<<i+1<<" : ";
			cin>>marks[i];
			sum += marks[i];
		}	
		average_marks = sum/5;
	}
	
	void display(){
		cout<<"Name of The Student is "<<name<<endl;
		cout<<"Roll No. of The Student is "<<roll<<endl;
		cout<<"Phone No. of The Student is "<<phone<<endl;
		cout<<"City The Student is "<<city<<endl;
		cout<<"Average Marks of The Student is "<<average_marks<<endl;	
	}
};

int main(){
	student *ob,ob1[5];
	int i;
	for(i=0; i<5; i++){
		cout<<"ENTER DETAILS OF STUDENT "<<i+1<<endl;
		ob=&ob1[i];
		ob->get();
		cout<<endl;
	}
	for(i=0; i<5; i++){
		cout<<"DETAILS OF STUDENT "<<i+1<<endl;
		ob=&ob1[i];
		ob->display();
		cout<<endl;
	}
}