#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main() {
    int a, b;

    cout << "\n\nEnter two numbers: ";
    cin >> a >> b;

    cout << "GCD = " << gcd(a, b) << endl<<endl;

    return 0;
}