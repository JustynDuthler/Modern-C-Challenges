/*
(1) A merge sort (with recursion)
(2) A quick sort (with recursion)
on arrays with sort keys such as double or strings to your liking?
Nothing is gained if you don’t know whether your programs are correct. Therefore, can
you provide a simple test routine that checks if the resulting array really is sorted?
This test routine should just scan once through the array and should be much, much faster
than your sorting algorithms.
*/

#include <stdlib.h>
#include <stdio.h>

#define TEST_ARR_SIZE 13

void mergeArr(int arr[], int start, int middle, int end) {
    int arr1Len = middle - start + 1;
    int arr2Len = end - middle;

    /* allocate temp arrays for merging */
    int *arr1 = (int *)malloc(sizeof(int) * arr1Len);
    int *arr2 = (int *)malloc(sizeof(int) * arr2Len);

    for (int i = 0; i < arr1Len; i++) {
        arr1[i] = arr[start + i];
    }
    for (int i = 0; i < arr2Len; i++) {
        arr2[i] = arr[middle + i + 1];
    }

    int arr1Index = 0;
    int arr2Index = 0;
    int arrIndex = start;

    while (arr1Index < arr1Len && arr2Index < arr2Len) {
        if (arr1[arr1Index] < arr2[arr2Index]) {
            arr[arrIndex] = arr1[arr1Index];
            arrIndex++;
            arr1Index++;
        } else {
            arr[arrIndex] = arr2[arr2Index];
            arrIndex++;
            arr2Index++;
        }
    } 

    while (arr1Index < arr1Len) {
        arr[arrIndex] = arr1[arr1Index];
        arrIndex++;
        arr1Index++;
    } 

    while (arr2Index < arr2Len) {
        arr[arrIndex] = arr2[arr2Index];
        arrIndex++;
        arr2Index++;
    } 

    /* free temp arrays */
    free(arr1);
    free(arr2);
}

void mergeSort(int arr[], int start, int end) {
    /* cannot sort empty arrays */
    if (arr == NULL || end == 0) {
        return;
    }

    if (start < end) {
        int middle = start + (end - start) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        mergeArr(arr, start, middle, end);
    }
}

void sort(int arr[], int arrSize) {
    mergeSort(arr, 0, arrSize - 1);
}

int main (void) {
    int *emptyArry = NULL;
    sort(emptyArry, 0);

    int sortedArry[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    sort(sortedArry, TEST_ARR_SIZE);
    for (int i = 0; i < TEST_ARR_SIZE; i++) {
        if (sortedArry[i] != i + 1) {
            printf("Array Not Sorted\n");
            return EXIT_FAILURE;
        }
    }
    printf("Array Sorted\n");

    int nonSortedArray[] = {13,2,4,6,5,1,3,10,11,12,9,8,7};
    sort(nonSortedArray, TEST_ARR_SIZE);
    for (int i = 0; i < TEST_ARR_SIZE; i++) {
        if (nonSortedArray[i] != i + 1) {
            printf("Array Not Sorted\n");
            return EXIT_FAILURE;
        }
    }
    printf("Array Sorted\n");
    return EXIT_SUCCESS;

}