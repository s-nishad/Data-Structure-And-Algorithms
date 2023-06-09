#include <stdio.h>
#include <iostream>

using namespace std;

int search(int array[], int n, int x) {
    int i;
    for (i = 0; i < n; ++i)
        if (array[i] == x) {
            return i;
        }
    return -1;
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
    int x;
    cout << "Enter The Number You Want To Find: ";
    cin >> x;

//    function calling

    int result = search(array, n, x);
    (result == -1)
    ? cout << "Element is not present"
    : cout << "Element is Present at index " << result << endl;
    return 0;
}