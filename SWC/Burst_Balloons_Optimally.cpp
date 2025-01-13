#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


int getpoint(vector<int> &v) {
    if(v.size() == 1) {
        return v[0];
    }

    int ans = INT_MIN, temp1, temp2;
    for(int i = 0; i < v.size(); i++) {
        temp1 = v[i];
        v.erase(v.begin() + i);
        temp2 = getpoint(v);
        v.insert(v.begin() + i, temp1);

        if(i == 0) {
            temp2 += v[i+1];
        } else if(i == v.size() - 1) {
            temp2 += v[i-1];
        } else {
            temp2 += (v[i-1] * v[i+1]);
        }
        ans = max(ans, temp2);
    }

    return ans;

}


int main() {
    int n;
    cin>> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << getpoint(a) << endl;
}