/*
Computer systems and low level programming
Author: Brian Jordan
1.28.2024
Lab 02
*/

#include <stdio.h>
#include <stdbool.h>

float discountPercent(int quantity){
    if (quantity >= 1 && quantity <= 49){
        return 1;
    }
    if (quantity >= 50 && quantity <= 99){
        return .1;
    }
    if (quantity >= 100 && quantity <= 149){
        return .15;
    }
    if (quantity >= 150){
        return .25;
    }
    
    return 1;
}


float discountAmount(float orderPrice, float percent){
    return orderPrice * percent;
}

bool isInt (float quantity){
    int intPart = (int) quantity;
    
    if (quantity - intPart == 0){
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    float itemPrice;
    float quantity;
    
    printf("Welcome to the Temple University store!\n\n");
    
    
    printf("Enter item price: ");
    scanf("%f", &itemPrice);
    
    if (itemPrice > 0){
    
        printf("Enter quantity: ");
        scanf("%f", &quantity);
        
        if (quantity > 0 && isInt(quantity)){
        
            float orderPrice = itemPrice * quantity;
            
            printf("\nThe item price is: $%.2f\n", itemPrice);
            printf("The order is: %.0f item(s)\n", quantity);
            printf("The cost is: $%.2f\n", orderPrice);
            printf("The discount is: %.f%%\n", discountPercent(quantity) * 100);
            printf("The discount amount is: $%.2f\n", discountAmount(orderPrice, discountPercent(quantity)));
            printf("The total is: $%.2f\n", orderPrice - discountAmount(orderPrice, discountPercent(quantity)));
            
            printf("\nThank you for using the Temple University store!");
        }
        else {
            printf("This is not a valid quantity order, please run the program again.");
        }
    }
    else {
        printf("This is not a valid item price, run the program again.");
    }
    
    return 0;
}
