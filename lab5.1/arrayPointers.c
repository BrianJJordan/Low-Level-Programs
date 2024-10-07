/*
Author: Brian Jordan
Class: Computer Systems and Low Level Programming
Date: 2/11/2024
Lab 6: Array Of Pointers
*/

#include <stdio.h>

void fillArray(int rows, int cols, int array[rows][cols]);
void printArray(int rows, int cols, int array[rows][cols]);
void maxGrade(int rows, int cols, int array[rows][cols]);
void minGrade(int rows, int cols, int array[rows][cols]);
void testAverage(int rows, int cols, int array[rows][cols]);

int main (void){
    int rows = 0, cols = 0;
    printf("%s", "How many students: ");
    scanf("%d", &rows);
    printf("%s", "How many exams: ");
    scanf("%d", &cols);

    int array[rows][cols];
    fillArray(rows, cols, array);

    void (*f[4])(int, int, int[rows][cols]) = {printArray, minGrade, maxGrade, testAverage};

    size_t choice = 0;
    while (choice >= 0 && choice < 4) {
        printf("Enter a choice:\n0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n3 Print the average on all tests for each student\n4 End program\n");
        scanf("%zu", &choice);

        if (choice < 4) {
            (*f[choice])(rows, cols, array); 
        }
    }
    puts("Program terminated");
    return 0;
}


void fillArray (int rows, int cols, int array[rows][cols]){
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter [Student%d][Exam%d]: ", i+1, j+1);
            scanf("%d", &array[i][j]);
            
        }
    }
}

void printArray(int rows, int cols, int array[rows][cols]){
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


void maxGrade(int rows, int cols, int array[rows][cols]) {
    int max = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    printf("Maximum grade: %d\n", max);
}

void minGrade(int rows, int cols, int array[rows][cols]) {
    int min = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }
    printf("Minimum grade: %d\n", min);
}

void testAverage(int rows, int cols, int array[rows][cols]) {
    printf("Average grades for each student:\n");
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
        }
        double average = sum / cols;
        printf("Student %d average: %.2f\n", i + 1, average);
    }
}