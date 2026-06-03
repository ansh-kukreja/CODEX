#include<stdio.h>

void sayHello(char[40]);

int main(){
    sayHello("Ansh");
}

void sayHello(char n[40]){
    printf("Hello %s", n);
}