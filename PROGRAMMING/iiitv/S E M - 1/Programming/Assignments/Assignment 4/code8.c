#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char user[20], pass[20];
    char myUser[10] = "superadmin";
    char myPass[5] = "67899";

    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    bool isUsernameCorrect = true;
    bool isPasswordCorrect = true;

    int lenOfUsername = 10, lenOfPass = 5;

    int i=0;
    while(i < lenOfUsername){
        if(myUser[i] != user[i]){
            isUsernameCorrect = false;
            break;
        }
        i++;
    }
    i=0;
    while(i < lenOfPass){
        if(myPass[i] != pass[i]){
            isPasswordCorrect = false;
            break;
        }
        i++;
    }

    if(!isUsernameCorrect || !isPasswordCorrect)printf("Invalid Login Credentials");
    else printf("Welcome %s!", user);
}
