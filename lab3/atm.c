/*
Author: Brian Jordan
Class: Computer Systems and Low Level Programming
Lab 3: ATM Machine
2/4/2024
*/

#include <stdio.h>
#define PIN 3014
double currentBalance = 5000;
int withdrawnTotal = 0;
double depositedTotal = 0;
int totalTransactions = 0;


double balance(){
    totalTransactions++;
    return currentBalance;
}

void withdrawal(){
    int amount = 0.0;
    printf("How much would you like to withdrawal? $");
    scanf("%d", &amount);
    
    if(withdrawnTotal + amount <= 1000)
    {
        if (amount%20 == 0){
           if(amount > currentBalance){
                printf("Insufficient Funds.");
            }
            else{
                currentBalance -= amount;
                withdrawnTotal += amount;
                totalTransactions++;
            } 
        }
        else {
            printf("\nWithdrawal amount must be a multiple of 20\nTry again\n\n");
            withdrawal();
        }
    }
    else 
    {
        printf("\n\nThe daily withdrawal limit is $1000\nYou can only withdraw $%d more.\n\n", 1000 - withdrawnTotal);
    }
}

void deposit(){
    double amount = 0;
    printf("\nHow much would you like to deposit? $");
    scanf("%lf", &amount);
    
    if (depositedTotal + amount <= 10000){
        if (amount > 0){
            depositedTotal += amount;
            currentBalance += amount;
            totalTransactions++;
        }
        else{
            printf("\nYou must enter a positive number.\n\n");
            deposit();
        }
        
    }
    else {
        printf("%s", "\nThe maximum daily amount you can deposit is $10,000.\nEnter a valid amount.\n\n");
        deposit();
    }
}

void atmTransaction(){
    
    int choice = 0;
    while (choice != 4){
        printf("%s", "\n1. Balance\n2. Cash Withdrawal\n3. Cash Deposit\n4. Quit\n\n");
        printf("%s", "Option #: ");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("\nYour balance is: $%.2lf\n\n", balance());
            break;
        case 2: 
            withdrawal();
            break;
        case 3:
            deposit();
            break;
        case 4:
            break;
        default:
            printf("\nEnter a number 1-4\n");
            break;
        }
    } 
    
}

void receipt(){
    int decision = 0;
    printf("\nWould you like a receipt?\n1. Yes\n2. No\n\nOption #: ");
    scanf("%d", &decision);

    if(decision == 1){
        printf("\n\n\nBank Receipt\n\n");
        printf("Total Transactions: %d\n", totalTransactions);
        printf("Deposited amount: $%.2lf\n", depositedTotal);
        printf("Withdrawn amount: $%d\n", withdrawnTotal);
        printf("Your balance is: $%.2lf\n\n", currentBalance);
        printf("Have a nice day!\n\n");
    }
    else{
        printf("\nHave a nice day!\n\n");

    }
}




int main(void)
{

int userPin = 0;
int guesses = 0;

while (userPin != PIN && guesses < 3){
    guesses++;
    printf("%s", "\nEnter pin: ");
    scanf("%d", &userPin);

    if (userPin == PIN){
        atmTransaction();
        receipt();
    }
}

if(userPin != PIN){
    printf("\nYou've entered the incorrect password too many times.\n\n");
}



return 0;

}
