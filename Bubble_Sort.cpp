#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n-i-1 ; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int i, n;
    cout << "How many numbers: ";
    cin >> n;
    int array[n];
    cout << "Enter The numbers: ";
    for (i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

//    function calling

    bubble_sort(array, n);

//    print the sorted array

    cout << "Sorted Array: ";
    int j;
    for (j = 0; j < n; ++j) {
        cout << array[j] << "\t";
    }

    return 0;
}
