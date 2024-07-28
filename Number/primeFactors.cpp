#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findPrimeFactors(int num) {
    vector<int> primeFactors;
    
    // Divide by 2 until num becomes odd
    while (num % 2 == 0) { // O(log n)
        primeFactors.push_back(2);
        num /= 2;
    }
    
    // Check for odd factors from 3 upwards
    for (int i = 3; i <= sqrt(num); i += 2) { // O(sqrt(n))
        while (num % i == 0) { // O(log n) per factor
            primeFactors.push_back(i);
            num /= i;
        }
    }
    
    // If num is a prime number greater than 2
    if (num > 2) {
        primeFactors.push_back(num);
    }
    
    return primeFactors;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    vector<int> primeFactors = findPrimeFactors(num);

    cout << "Prime factors of " << num << " are: ";
    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
