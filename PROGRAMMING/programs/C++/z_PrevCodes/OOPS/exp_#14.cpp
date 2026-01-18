#include<iostream>
#include<string>
using namespace std;
class Employee // class Employee is created
{
public:
string name; 
int emp_id;
double salary;

Employee()
{
cout<<"Name of employee is ="<<endl;
cin>>name;
cout<<"ID of employee is ="<<endl;
cin>> emp_id;
cout<<"Salary of employee is ="<<endl;
cin>>salary;
cout<<"DATA OF EMPLOYEE DISPLAY (By using default constructor):"<<endl;
cout<<"Name of employee is ="<<name<<endl;
cout<<"ID of employee is ="<<emp_id<<endl;
cout<<"Salary of employee is ="<<salary<<endl;
}

Employee(string emp_name,int id,int sal_emp)
{
name=emp_name;
emp_id=id;
salary=sal_emp;
cout<<"DATA OF EMPLOYEE DISPLAY (By using parameterized constructor):"<<endl;
cout<<"Name of employee is ="<<name<<endl;
cout<<"ID of employee is ="<<emp_id<<endl;
cout<<"Salary of employee is ="<<salary<<endl;
}

Employee(Employee &emp) //copy constructor is created
 {
 name=emp.name; 
 emp_id=emp.emp_id;
 salary=emp.salary;
 cout<<"DISPLAY DATA OF EMPLOYEE (BY USING COPY CONSTRCUCTOR)"<<endl;
 cout<<"COPIED VALUE OF NAME IS :"<<name<<endl;
cout<<"COPIED VALUE OF ID IS :"<<emp_id<<endl;
 cout<<"COPIED VALUE OF SALARY IS:"<<salary<<endl;
 }
 
 //Destructor is called 
 ~Employee()
 {
 cout << "Destructor Called for Employee"<<endl;
 }
};
int main()
{
Employee emp1;
Employee emp2("Gauraansh",7081,90000);
Employee emp3(emp2);
}