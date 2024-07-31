#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= sqrt(n); i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int32_t main() {
    int limit;
    cin >> limit;
    vector<int> primes(sieveOfEratosthenes(limit));

    for(int i : primes) {
        cout << i << " ";
    }

    printf("\nTotal Number of prime: (1, %d) is %d", limit, primes.size()); 

    return 0;
}
