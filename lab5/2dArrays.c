/*
Author: Brian Jordan
Class: Computer Systems and Low Level Programming
Date: 2/11/2024
Lab 5: Processing 2D Arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void fillArray (int rows, int cols, int array[rows][cols]){
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
            
        }
    }
}

void printArray (int rows, int cols, int array[rows][cols]){
    puts("");
    for (int i = 0; i < rows; i++){
        printf("%s", "[ ");
        for (int j = 0; j < cols; j++){
           printf("%d ", array[i][j]);
        }
        printf("%s", "]");
        printf("%s", "\n");
    }
    puts("");
}

int rowSum (int whichRow, int rows, int cols, int array[rows][cols]){
    if (whichRow > rows - 1){
        printf("\nThis is a %dx%d array, row #%d does not exist.\n", rows + 1, cols, whichRow);
        return -1;
    }

    int sum = 0;

    for (int i = 0; i < cols; i++){
        sum += array[whichRow][i];
    }

    return sum;
}

int columnSum (int whichCol, int rows, int cols, int array[rows][cols]){
    if (whichCol > cols - 1){
        printf("\nThis is a %dx%d array, column #%d does not exist.\n", cols + 1, rows, whichCol);
        return -1;
    }

    int sum = 0;

    for (int i = 0; i < rows; i++){
        sum += array[i][whichCol];
    }

    return sum;
}

bool isSquare (int rows, int cols){
    if (rows == cols){
        return true;
    }
    return false;
}



int main (void){
    puts("\nLets create a 2D array!");

    int rows = 0, cols = 0;
    printf("%s", "How many rows: ");
    scanf("%d", &rows);
    printf("%s", "How many cols: ");
    scanf("%d", &cols);

    if (cols < 1 || rows < 1){
        puts("That is not a valid sized array.");
    }
    else{

        int array[rows][cols];
        fillArray(rows, cols, array);

        rowSum(0, rows, cols, array);
        rowSum(1, rows, cols, array);
        rowSum(2, rows, cols, array);

        {
            for (int i = 0; i < rows; i++){
                printf("Sum of row %d: %d\n", i+1, rowSum(i, rows, cols, array));
            }
            puts(" ");
        }

        {
            for (int i = 0; i < cols; i++){
                printf("Sum of column %d: %d\n", i+1, columnSum(i, rows, cols, array));
            }
            puts(" ");
        }

        {
            if (isSquare(rows, cols)){
                puts("This is a square array.");
            }
            else{
                puts("This is not a square array.");
            }
            puts(" ");
        }

        printf("Here is your %dx%d array.\n", rows, cols);
        printArray(rows, cols, array);
    }
    
    return 0;
}
