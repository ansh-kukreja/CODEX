#include<iostream>
using namespace std;

int main() 
{
    cout<<"Harpreet 2210997092\n";
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array in ascending Order:" << endl;
    for (int i = 0; i < n; ++i) 
	{
        cin >> arr[i];
    }
    int choice;
 
        cout << "Menu:" << endl;
        cout << "1. Search an element using linear search" << endl;
        cout << "2. Search an element using binary search" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        int target, index;
        switch (choice) 
		{
            case 1:
                cout << "Enter the element to search: ";
                cin >> target;
                index = -1; // Element not found by default
                for (int i = 0; i < n; ++i) 
				{
                    if (arr[i] == target) 
					{
                        index = i;
                        break;
                    }
                }
                if (index != -1) 
				{
                    cout << "Element found at index " << index << endl;
                } 
				else 
				{
                    cout << "Element not found" << endl;
                }
                break;

            case 2:
            	int num;
                cout << "Enter the element to search: ";
                cin >>num;
                int middle;
                int first = 0;
                int last = n - 1;
                index = -1; // Element not found by default

        while(first <= last)
    	{
    		middle = (first+last)/2;
        	if(arr[middle]<num)
	        	{
        	   		first = middle+1;
				}
         
        	else if(arr[middle]==num)
        		{
            		cout<<"\nThe number, "<<num<<" found at Position "<<middle;
            		break;
        		}
        	else
	        	{
        	   last = middle-1;
        	   middle = (first+last)/2;
				}
         
    	}	
    		if(first>last)
    		{
    			cout<<"\nThe number, "<<num<<" is not found in given Array";
			}
       		
    			cout<<endl;
                break;
    }
    return 0;
}

