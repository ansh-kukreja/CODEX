#include <iostream>
#include <iomanip> // Include the <iomanip> header for manipulators
using namespace std;
int main() 
{
    cout << "Demonstrating Different Manipulators:" <<endl;

    // setw() and setfill()
    int num1 = 123;
    cout << "setw(10) and setfill('*'): " << setw(9) << setfill('*') << num1 << endl;

    // setprecision()
    double pi = 3.14159265359;
    cout << "setprecision(4): " << setprecision(4) << pi << endl;

    // setbase()
    int num2 = 255;
    cout << "setbase(16): " << setbase(16) << num2 << endl;

    // reset manipulators
    cout << setbase(10); // Reset to default base (decimal)
    cout << setfill(' '); // Reset to default fill character (space)

    // endl
    cout << "This is a line with endl." << endl;
    cout << "This is another line with endl." << endl;

    return 0;
}