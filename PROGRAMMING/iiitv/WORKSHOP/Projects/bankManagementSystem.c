#include<stdio.h>

typedef struct {
    int balance;
    int transactions[100];
    char transactionType[100];
    int transactionCount;
} Bank;

int main(){
    Bank myBank;
    myBank.balance = 0;
    myBank.transactionCount = 0;

    int n;

    while(1){
        printf("\n-------------- MENU ---------------\n");
        printf("Enter 1 to check Bank Balance\n");
        printf("Enter 2 to Deposit Money\n");
        printf("Enter 3 to Withdraw Money\n");
        printf("Enter 4 to View Transaction history\n");
        printf("Enter 0 to Exit\n");
        printf("Enter Your Option: ");
        scanf("%d", &n);
        printf("---------------------------------\n");

        if(n == 0){
            printf("\n==== THANKS FOR USING OUR BANK ====\n");
            break;
        }

        if(n == 1){
            printf("Bank Balance: %d", myBank.balance);
            printf("\n");
        }
        else if(n == 2){
            int amount;
            printf("Enter Amount to Deposit: ");
            scanf("%d", &amount);
            myBank.balance += amount;

            myBank.transactions[myBank.transactionCount] = amount;
            myBank.transactionType[myBank.transactionCount] = 'D';
            myBank.transactionCount += 1;

            printf("\nDEPOSIT SUCCESSFULL!\n");
        }
        else if(n == 3){
            int amount = 0;
            printf("Enter Amount to Withdraw: ");
            scanf("%d", &amount);

            if(amount <= myBank.balance){
                myBank.balance -= amount;
                myBank.transactions[myBank.transactionCount] = amount;
                myBank.transactionType[myBank.transactionCount] = 'W';
                myBank.transactionCount += 1;

                printf("\nWITHDRAWL SUCCESSFULL!\n");
            }
            else{
                printf("\nYOU DON'T HAVE ENOUGH BALANCE TO WITHDRAW!\n");
            }
            
        }
        else if(n == 4){
            printf("------- Transaction History -------\n");
            for(int i=0; i<myBank.transactionCount; i++){
                char type[40];
                if(myBank.transactionType[i] == 'D'){
                    type[0] = 'D';
                    type[1] = 'E';
                    type[2] = 'P';
                    type[3] = 'O';
                    type[4] = 'S';
                    type[5] = 'I';
                    type[6] = 'T';
                    type[7] = '\0';
                }
                else{
                    type[0] = 'W';
                    type[1] = 'I';
                    type[2] = 'T';
                    type[3] = 'H';
                    type[4] = 'D';
                    type[5] = 'R';
                    type[6] = 'A';
                    type[7] = 'W';
                    type[8] = '\0';
                }
                printf("%s : %d", type, myBank.transactions[i]);
                printf("\n");
            }
        }

    }
}