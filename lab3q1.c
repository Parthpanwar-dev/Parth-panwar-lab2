#include <stdio.h>
#include <stdbool.h>

#define SIZE 5
#define NROWS 2
#define NCOLS 3

// Function to check if the position is valid in the array
bool isValid(const int arr[], int length, int pos) {
    return (pos >= 0 && pos < length);
}

// Function to remove an element at a specific position in the array
void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position for removal.\n");
        return;
    }
    
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0; // Optional: Set the last element to zero
}

// Function to insert an element at a specific position in the array
void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position for insertion.\n");
        return;
    }

    for (int i = length - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
}

// Function to reshape a 1D array into a 2D array if dimensions match
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]) {
    if (length != nRows * nCols) {
        printf("Error: Dimensions do not match for reshaping.\n");
        return;
    }

    for (int col = 0, idx = 0; col < nCols; col++) {
        for (int row = 0; row < nRows; row++) {
            arr2d[row][col] = arr[idx++];
        }
    }
}

// Function to transpose a matrix
void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = mat[i][j];
        }
    }
}

// Function to check for duplicates in an array
bool found_duplicate(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

// Main function to test the utility functions
int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50};
    int arr2d[NROWS][NCOLS] = {0};

    // Testing isValid
    printf("isValid(arr, SIZE, 2): %d\n", isValid(arr, SIZE, 2));
    printf("isValid(arr, SIZE, 5): %d\n", isValid(arr, SIZE, 5));

    // Testing remove_element
    printf("Original array: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr[i]);
    printf("\n");
    
    remove_element(arr, SIZE, 2);
    printf("Array after removing element at position 2: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr[i]);
    printf("\n");

    // Testing insert_element
    insert_element(arr, SIZE, 2, 80);
    printf("Array after inserting 80 at position 2: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr[i]);
    printf("\n");

    // Testing reshape
    int arr1D[6] = {1, 2, 3, 4, 5, 6};
    reshape(arr1D, 6, NROWS, NCOLS, arr2d);
    printf("2D array after reshaping:\n");
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }

    // Testing trans_matrix
    int transposed[NCOLS][NROWS] = {0};
    trans_matrix(NROWS, NCOLS, arr2d, transposed);
    printf("Transposed matrix:\n");
    for (int i = 0; i < NCOLS; i++) {
        for (int j = 0; j < NROWS; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }

    // Testing found_duplicate
    int arrWithDuplicates[5] = {1, 2, 3, 2, 5};
    printf("found_duplicate(arrWithDuplicates, 5): %d\n", found_duplicate(arrWithDuplicates, 5));
    
    return 0;
}
