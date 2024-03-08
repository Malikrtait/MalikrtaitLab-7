#include <stdio.h>

void bubbleSort(int arr[], int n, int *total_swaps) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*total_swaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *total_swaps) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            (*total_swaps)++;
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int total_swaps_array1_bubble = 0;
    int total_swaps_array2_bubble = 0;
    int total_swaps_array1_selection = 0;
    int total_swaps_array2_selection = 0;

  
    bubbleSort(array1, n1, &total_swaps_array1_bubble);
    bubbleSort(array2, n2, &total_swaps_array2_bubble);

    
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

 
    selectionSort(array3, n1, &total_swaps_array1_selection);
    selectionSort(array4, n2, &total_swaps_array2_selection);

   
    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d times swapped\n", array1[i], i + 1);
    }
    printf("Total swaps for array1 (Bubble Sort): %d\n", total_swaps_array1_bubble);
    printf("Total swaps for array1 (Selection Sort): %d\n", total_swaps_array1_selection);

    printf("\narray2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d times swapped\n", array2[i], i + 1);
    }
    printf("Total swaps for array2 (Bubble Sort): %d\n", total_swaps_array2_bubble);
    printf("Total swaps for array2 (Selection Sort): %d\n", total_swaps_array2_selection);

    return 0;
}