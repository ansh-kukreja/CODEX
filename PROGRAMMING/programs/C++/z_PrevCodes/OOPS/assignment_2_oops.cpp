
#include<iostream>
using namespace std;

class EmployeePersonal{
	public:
		string name;
		int id;
		char gender;
		
		void readPersonalInfo(){
			cout<<"Enter Name : "; cin>>name;
			cout<<"Enter Employee Id : "; cin>>id;
			cout<<"Enter Gender (M/F) : "; cin>>gender;
		}
};

class EmployeeWork{
	public:
		string nameOfDept;
		string workAssigned;
		string completionTime;
		
		void readWorkInfo(){
			cout<<"Enter Name of department : "; cin>>nameOfDept;
			cout<<"Enter Work Assigned : "; cin>>workAssigned;
			cout<<"Enter Completion Time : "; cin>>completionTime;
		}
};

class Employee : public EmployeePersonal, public EmployeeWork{
	public:
		void printEmployee(){
			cout<<"\nEmployee Information \n";
			cout<<"Name : "<<name<<"\n";
			cout<<"Employee Id : "<<id<<"\n";
			cout<<"Gender : "<<gender<<"\n";
			cout<<"Department : "<<nameOfDept<<"\n";
			cout<<"Work Assigned : "<<workAssigned<<"\n";
			cout<<"Completion Time : "<<completionTime<<"\n\n"; 
		}
};

int main(){
	Employee emp;
	emp.readPersonalInfo();
	emp.readWorkInfo();
	emp.printEmployee();
}
