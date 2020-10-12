/*
* Author: Zeyu Li
* CMPUT 201 Fall 2020 - Lab #5
* l5q3.c - Balancing 1's in columns
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_matrix(int size, int matrix[size][size]);
int check_count(int size, int matrix[size][size], int column);
int get_first_num_col(int size, int matrix[size][size], int column, int collision_col, int num);
void initialization(int size, int matrix[size][size]);
void swap(int size, int matrix[size][size], int row, int index_1, int index_2);
void balance1(int size, int matrix[size][size]);


int main() {
    int size, error;

    printf("Enter the size of matrix, a positive even integer: ");
    error = scanf("%d", &size);

    // wrong type
    if (error != 1) {
        printf("The number is recognized, try again\n");
        return 0;
    }

    // // validates even number and size in range 
    if ((size % 2 != 0) || !(2 <= size && size <= 80)) {
        printf("The number is either not even and/or within the range 2 to 80 inclusive, try again\n");
        return 0;
    }

    // init square matrix
    int matrix[size][size];

    // debuging
    // int matrix[4][4] = {{0,1,1,0},{1,1,0,0},{1,0,1,0},{1,0,1,0}};

    // generates matrix
    initialization(size, matrix);

    // balances matrix
    balance1(size, matrix);

    // print matrix row by row
    print_matrix(size, matrix);

    return 0;
}

void print_matrix(int size, int matrix[size][size]) {
    // prints the matrix

    for (int i = 0; i < size; i++) {
        // every row
        for (int j = 0; j < size; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}


int check_count(int size, int matrix[size][size], int column) {
    // gets the number of 1s in column

    int count = 0;

    // counts 1s in column
    for (int row = 0; row < size; row++) {
        if (matrix[row][column] == 1) {
            count++;
        }
    }

    return count;
}

int get_first_num_col(int size, int matrix[size][size], int column, int collision_col, int num) {
    // gets the row number of the first num in column
    
    for (int i = 0; i < size; i++) {
        if (matrix[i][column] == num && matrix[i][collision_col] != num) {
            return i;
        }
    }

    return -1;
}

void initialization(int size, int matrix[size][size]) {
    // since we are mulimplating an array, no need to return anything

    // zeros matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }

    // sudo random number generator
    srand(time(NULL));
    int picked;

    // randomly pick 1/2 numbers of size and set them to 1
    for (int i = 0; i < size; i++) {
        picked = 0;
        // while picked is not half the size of row length
        while (picked < (int)(size/2)) {
            for (int j = 0; j < size; j++) {
                if (rand() % 2 && matrix[i][j] != 1) {
                    matrix[i][j] = 1;
                    picked++;
                    if (picked == (int)(size/2)) {
                        break;
                    }
                }
            }
        }
    }
}

void swap(int size, int matrix[size][size], int row, int index_1, int index_2) {
    // swaps the two positions in the row
    int temp = matrix[row][index_1];
    matrix[row][index_1] = matrix[row][index_2];
    matrix[row][index_2] = temp;
}

void balance1(int size, int matrix[size][size]) {
    // the number of 1s in each column is size/2 times
    // using swap function

    int count, alt_count, greater, smaller, swap_row;
    
    // for each column
    for (int column = 0; column < size; column++) {
        while (1) {

            // debugging every row swap
            // print_matrix(size, matrix);
            // printf("\n");

            // makes sure it is balance by checking
            count = check_count(size, matrix, column);

            // if balanced, break and go to the next column
            if (count == (int)(size/2)) {
                break;
            } else if (count > (int)(size/2)) {
                // if count is greater than half the size, find column with smaller than half
                for (int temp_column = column + 1; temp_column < size; temp_column++) {
                    alt_count = check_count(size, matrix, temp_column);
                    if (alt_count < (int)(size/2)) {
                        smaller = temp_column;
                        break;
                    }
                }

                // swaps
                // gets the first 1 in current column that works
                swap_row = get_first_num_col(size, matrix, column, smaller, 1);

                // swaps column place with first 1 in row
                swap(size, matrix, swap_row, column, smaller);

            } else {
                // count is smaller than half the size
                // if count is greater than half the size, find column with smaller than half
                for (int temp_column = column + 1; temp_column < size; temp_column++) {
                    alt_count = check_count(size, matrix, temp_column);
                    if (alt_count > (int)(size/2)) {
                        greater = temp_column;
                        break;
                    }
                }

                // swaps
                // gets the first 0 in current column
                swap_row = get_first_num_col(size, matrix, column, greater, 0);

                // swaps column place with first 1 in row
                swap(size, matrix, swap_row, column, greater);
            }
        }
    }
}