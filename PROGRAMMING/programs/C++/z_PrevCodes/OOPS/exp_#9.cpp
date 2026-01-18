#include <iostream>
using namespace std;

class Array_operations 
{
private:
    int arr[100];
    int size;

public:
    Array_operations() 
	{
        size = 0;
    }

    void get() 
	{
       cout << "Enter the size of the array: ";
       cin >> size;

       cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; ++i) 
		{
        	cin >> arr[i];
        }
    }

    void display() 
	{
    cout << "Array elements: ";
        for (int i = 0; i < size; ++i) 
		{
         cout << arr[i] << " ";
        }
        cout << std::endl;
    }

    int findLargest() 
	{
        int largest = arr[0];
        for (int i = 1; i < size; ++i) 
		{
            if (arr[i] > largest) 
			{
                largest = arr[i];
            }
        }
        return largest;
    }

    void insertElement(int position, int element) 
	{
        if (position < 0 || position > size) 
		{
            cout << "Invalid position for insertion." << std::endl;
            return;
        }

        for (int i = size - 1; i >= position; --i) 
		{
            arr[i + 1] = arr[i];
        }
        arr[position] = element;
        size++;
    }

    void deleteElement(int position) 
	{
        if (position < 0 || position >= size) 
		{
            cout << "Invalid position for deletion." << endl;
            return;
        }

        for (int i = position; i < size - 1; ++i) 
		{
            arr[i] = arr[i + 1];
        }
        size--;
    }
};

int main() {
    Array_operations arrayObj;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Get array elements\n";
        cout << "2. Display array elements\n";
        cout << "3. Find largest element\n";
        cout << "4. Insert element\n";
        cout << "5. Delete element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                arrayObj.get();
                break;
            case 2:
                arrayObj.display();
                break;
            case 3:
                std::cout << "Largest element: " << arrayObj.findLargest() << std::endl;
                break;
            case 4:
                int pos, element;
                std::cout << "Enter position and element to insert: ";
                std::cin >> pos >> element;
                arrayObj.insertElement(pos, element);
                break;
            case 5:
                std::cout << "Enter position to delete: ";
                std::cin >> pos;
                arrayObj.deleteElement(pos);
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}

