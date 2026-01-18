#include <iostream>
#include <string>
using namespace std;
class Employee 
{
public:
	
    string name;
    string designation;
    double salary;
    string phone;
    string resident;
public:
	
    void get() {
        cout << "Enter name of employee: ";
        cin >> name;
        cout << "Enter designation of employee: ";
        cin >> designation;
        cout << "Enter salary of employee: ";
        cin >> salary;
        cout << "Enter phone number of employee: ";
        cin >> phone;
        cout<<"Enter city of employee:";
        cin>>resident;
    }

    void display() {
        cout << "Name of employee: " << name << endl;
        cout << "Designation of employee: " << designation << endl;
        cout << "Salary of employee: " << salary << endl;
        cout << "Phone of employee: " << phone << endl;
        cout<<"Employee is resident of: "<<resident<<endl;
    }
};

int main()
 {
    int noemp;

    cout << "Enter the number of employees: ";
    cin >> noemp;

    Employee ob[noemp];

    for (int i = 0; i < noemp; i++) 
	{
cout<<endl<<"Enter the details of Employee "<<i+1<<endl<<"++++++++++++++++++++++++++++++++"<<endl;

        ob[i].get();
    }
cout<<endl;
cout<<"-----------------------------------";
cout<<endl;
    int count = 0;
    for (int i = 0; i < noemp; i++) 
	{
    	
        if (ob[i].name[0] == 'n'  && ob[i].salary > 1200) 
		{
            count=count+1;
        }
    }
    cout << "Number of employees whose name starts with 'N' and salary > 1200: " << count << endl;
    cout<<endl;
cout<<"-----------------------------------";
    cout<<endl;
	
    cout << "\nEmployees who are residents of Chandigarh:" << endl;
    for (int i = 0; i < noemp; i++) 
	{
        if (ob[i].resident == "Chandigarh" )
		 {
            ob[i].display();
        }
    }
cout<<endl;
cout<<"-----------------------------------";
cout<<endl;
    
    cout << "\nEmployees with designation 'manager':" << endl;
    for (int i = 0; i < noemp; i++) 
	{
        if (ob[i].designation == "manager")
		 {
            ob[i].display();
        }
    }
cout<<"-----------------------------------";
    return 0;
}