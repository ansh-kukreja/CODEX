#include<stdio.h> 

int main(){ 
    char a = 'A';
    char b = 'B';
    char t;

    t = a;
    a = b;
    b = t;

    printf("a = %c", a);
    printf("b = %c", b);

    
    return 0;
}