#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int count(ll n) {
    ll count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    ll x;
    cin >> x;
    if (x==0) {
        cout << "1\n";
        return 0;
    }
    cout << pow(2, count(x)) << endl;
    return 0;
}
