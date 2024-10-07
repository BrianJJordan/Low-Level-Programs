/*
Author: Brian Jordan
Class: Computer Systems and Low Level Programming
Date: 2/11/2024
Lab 4: Processing 1D Arrays
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RAND_MIN 0
#define RAND_MAX 100
#define ARRAY_SIZE 40

void fillArray(int array[]){
    for (int i = 0; i < ARRAY_SIZE; i++){
        int randomNumber = rand() % (RAND_MAX + 1) + RAND_MIN;
        array[i] = randomNumber;
    }
}

int findWithRange(int array[], int low, int high){
    int largest = 0;

    for (int i = low; i <= high; i++){
        if (array[i] > largest){
            largest = array[i];
        }
    }
    return largest;
}

void reverseArray(int array[]){
    for (int i = 0; i < ARRAY_SIZE/2; i++){
        int temp = array[i];
        array[i] = array[ARRAY_SIZE - 1 - i];
        array[ARRAY_SIZE - 1 - i] = temp;
    }
}

void reverseSelectedRangeWithinArray(int array[], int startRange, int endRange){
    int j = 0;

    for (int i = startRange; i <= (endRange + startRange)/2; i++){
        int temp = array[i];
        array[i] = array[endRange - j];
        array[endRange - j] = temp;
        j++;
    }
}

int findSequence(int array[], int tom, int jerry){
    for (int i = 0; i < ARRAY_SIZE; i++){
        if (array[i] == tom && array[i+1] == jerry){
            return i;
        }
    }
    
    return -1;
}

// extra
void printArray(int array[]){
    // for (int i = 0; i < ARRAY_SIZE; i++){
    //     printf("%d: %d\n", i, array[i]);
    // }
    printf("%s", "\n");

    printf("%s", "[ ");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("%d", array[i]);
        printf("%s", " ");
    }
    puts("]");
    puts("");

}

// extra
void copyArray(int array1 [], int array2[]){
    for (int i = 0; i < ARRAY_SIZE; i++){
        array2[i] = array1[i];
    }
}

//extra
void printBoth(int array1[], int array2[]){
    puts("\n");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("%d: %d %d\n", i, array1[i], array2[i]);
    }
}


int main(void){
    srand((unsigned)time(NULL));

    int array1 [ARRAY_SIZE];
    int original [ARRAY_SIZE]; 
    fillArray(array1); // puts 40 random integers into an array

    printf("%s", "\nHere is the array of 40 random integers:");
    printArray(array1);

    printf("%s", "\nHere is the array in reverse order:");
    reverseArray(array1);
    printArray(array1);

    reverseArray(array1); // this puts the array back to the normal order

    printf("%s", "\nHere is the largest number in the index range from 1-25:");
    printf("\n%d\n", findWithRange(array1, 1, 25));

    printf("%s", "\nHere is the reverse of the values from indexs 1-10:");
    reverseSelectedRangeWithinArray(array1, 1, 10);
    printArray(array1);


    int one = 0, two = 0;
    printf("%s", "\nEnter two numbers: ");
    scanf("%d%d", &one, &two);
    if (findSequence(array1, one, two) == -1){
        printf("%s", "\nSequence not found.\n\n");
    }
    else {
        printf("\nSequence found at %d\n", findSequence(array1, one, two));
    }

    // copyArray(array1, original);

    // printArray(array1);

    // printf("\n\n%d\n\n", findWithRange(array1, 30, 39));
    
    // reverseArray(array1);
    // printArray(array1);

    // printBoth(array1, original);

    // reverseSelectedRangeWithinArray(original, 1, 4);
    // printArray(original);

    // int TOMnJerry [] = {1,2,3,4,5,6,7,8,9,10};
    // printf("\nsequence found at %d\n", findSequence(TOMnJerry, 1, 2));

    return 0;
}