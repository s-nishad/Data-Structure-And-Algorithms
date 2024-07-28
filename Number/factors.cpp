#include <bits/stdc++.h>

using namespace std;

vector<int> findFactors(int num) {
    vector<int> factors;
    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i != num / i) {
                factors.push_back(num / i);
            }
        }
    }
    return factors;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    vector<int> factors = findFactors(num);

    cout << "Factors of " << num << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
