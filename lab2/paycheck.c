/*
Computer systems and low level programming
Author: Brian Jordan
1.28.2024
Lab 02
*/

#include <stdio.h>
#include <stdbool.h>

float overtime (float hourlySalary, float weeklyTime){
    float total;
    float extraTime = 1; // cannot do 0 otherwise this will make the NetPay 0 b/c of multiplication
    
    if (weeklyTime > 40){
        extraTime = weeklyTime - 40;
    }
    
    total = 1.5 * extraTime * hourlySalary;
    return total;
}

bool isInt (double employeeNumber){
    int intPart = (int) employeeNumber;
    
    if (employeeNumber - intPart == 0){
        return true;
    }
    else {
        return false;
    }
}

int main(void){
    
    float employeeNumber;
    float hourlySalary;
    float weeklyTime;

    printf("Enter Employee Number: ");
    scanf("%f", &employeeNumber);
    
    if (employeeNumber > 0 && isInt(employeeNumber)){
        printf("Enter Hourly Salary: ");
        scanf("%f", &hourlySalary);
        
        if (hourlySalary > 0){
        
            printf("Enter Weekly Time: ");
            scanf("%f", &weeklyTime);
            
            if (weeklyTime > 0){
            
                printf("\n");
                
                float regularPay = hourlySalary * 40;
                float overtimePay = overtime(hourlySalary, weeklyTime);
                float netPay = regularPay + overtimePay;
                
                printf("Employee #: %f\n", employeeNumber);
                printf("Hourly Salary: $%.2f\n", hourlySalary);
                printf("Weekly Time: %.1f\n", weeklyTime);
                printf("Regular pay: $%.2f\n", regularPay);
                printf("Overtime Pay: $%.2lf\n", overtimePay);
                printf("Net Pay: $%.2lf\n", netPay);
            }
            
            else {
                printf("This is not a valid weekly time.\nPlease run the program again.");

            }
        }
        
        else {
            printf("This is not a valid hourly salary.\nPlease run the program again.");
        }
        
    }
        
    else {
        printf("This is not a valid employee number.\nPlease run the program again.");
    }

    
    return 0;
}
