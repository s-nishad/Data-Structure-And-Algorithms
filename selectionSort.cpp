//
// C++ program for implementation of selection sort
// Created by Nishad on 6/6/2021.
//
#include <bits/stdc++.h>
using namespace std;

void selectionSort (int arr[], int size) {
    int i, index_min, j, temp;

    for (i = 0; i < size-1; i++) {
        index_min = i;
        for (j = i+1; j < size; ++j) {
            if (arr[j] < arr[index_min]) {
                index_min = j;
            }
        }
        if (index_min != i) {
            temp = arr[i];
            arr[i] = arr[index_min];
            arr[index_min] = temp;
        }
    }
}

void printArray (int arr[], int size) {
    cout << "Sorted Array is: ";
    int i;
    for (i = 0; i < size; ++i) {
        cout << arr[i] << "\t" ;
    }
}

int main() {
    int size;
    cout << "How many numbers: ";

    cin >> size;
    int arr[size];
    cout << "Enter the numbers: ";
    int i;
    for (i = 0; i < size; ++i) {
        scanf("%d",&arr[i]);
    }
//    calling selectionSort function
    selectionSort(arr, size);

//    calling function for print array
    printArray(arr, size);

    return 0;
}
