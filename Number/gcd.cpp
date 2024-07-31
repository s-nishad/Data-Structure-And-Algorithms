#include <bits/stdc++.h>
using namespace std;

int calculate_gcd(int a, int b) {

    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;

    // recursive way

    // if(b == 0) {
    //     return a;
    // }
    // calculate_gcd(b, a%b);
}

int32_t main() {
    int a, b;
    cin >> a >> b;
    int gcd = calculate_gcd(a, b);
    printf("GCD of %d and %d is: %d\n", a, b, gcd);

    int lcm = (a*b) / gcd;
    printf("LCM of %d and %d is: %d", a, b, lcm);

    return 0;
}
