#include <iostream>
#include <cmath>
using namespace std;

double fact(int n) {
    double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double powerF(double n, int p) {
    double ans = 1;
    for (int i = 1; i <= p; i++) {
        ans *= n;
    }
    return ans;
}

int main() {
    double x = 10 * 3.141592653589793 / 180.0; // convert 10° to radians
    double ans = 0;

    int terms = 25;
    for (int i = 0; i < terms; i++) {
        int power = 2 * i + 1;
        double term = powerF(x, power) / fact(power);
        if (i % 2 == 0)
            ans += term;
        else
            ans -= term;
    }

    cout << "sin(10°) ≈ " << ans << endl;
    cout << "Actual sin(10°) = " << sin(x) << endl;

    return 0;
}
