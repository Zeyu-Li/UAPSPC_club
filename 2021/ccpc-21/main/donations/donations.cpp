#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    // years = n, start = x, y = amount to donate
    // z = z min, c=tax credit,r=compound interest
    int n,x,y,z,c,r;
    ll total;
    cin >> n >> x >> y >> z >> c >> r;
    if (x <= 100) {
        // donate the last year
        for (int i = 0; i < n;i++) {
            total+=total*(r/100);
        }
        if (total > )
    }
    return 0;
}
