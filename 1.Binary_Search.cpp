#include <bits/stdc++.h>
using namespace std;

int search (int arr[], int n, int k){
    int left, right, mid;
    left = 0;
    right = n-1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == k) {
            return mid;
        }
        if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, k, i;
    cout << "How many numbers: ";
    cin >> n;

    int arr[n];
    cout << "Enter the numbers: ";
    for (i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }

    cout << "Enter the number you want to find: ";
    cin >> k;

//    function calling

    int result = search(arr, n, k);
    (result == -1)
    ? cout << "Element is not present"
    : cout << "Element is Present at index " << result << endl;
    return 0;
}