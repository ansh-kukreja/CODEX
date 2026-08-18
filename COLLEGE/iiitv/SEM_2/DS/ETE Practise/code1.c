#include <stdio.h>

int main() {
    // Integer types
    int a = 10;
    short int b = 20;
    long int c = 300000;
    long long int d = 9000000000;

    // Unsigned types
    unsigned int e = 50;
    unsigned short int f = 60;
    unsigned long int g = 700000;

    // Character
    char h = 'A';

    // Floating types
    float i = 5.75;
    double j = 123.456789;
    long double k = 123456.789123;

    // Printing values and sizes
    printf("int: %d, size = %lu bytes\n", a, sizeof(a));
    printf("short int: %hd, size = %lu bytes\n", b, sizeof(b));
    printf("long int: %ld, size = %lu bytes\n", c, sizeof(c));
    printf("long long int: %lld, size = %lu bytes\n", d, sizeof(d));

    printf("unsigned int: %u, size = %lu bytes\n", e, sizeof(e));
    printf("unsigned short int: %hu, size = %lu bytes\n", f, sizeof(f));
    printf("unsigned long int: %lu, size = %lu bytes\n", g, sizeof(g));

    printf("char: %c, size = %lu byte\n", h, sizeof(h));

    printf("float: %f, size = %lu bytes\n", i, sizeof(i));
    printf("double: %lf, size = %lu bytes\n", j, sizeof(j));
    printf("long double: %Lf, size = %lu bytes\n", k, sizeof(k));

    return 0;
}