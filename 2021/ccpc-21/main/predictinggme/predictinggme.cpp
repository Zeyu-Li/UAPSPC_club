#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> predictions;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        int k = x - '0';
        predictions.push_back(k);
    }

    // base case
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    // dp for sure
    // y is sell time, buy is x
    int opt[n][n-1];

    // zeros out matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++){
            // only count when sell > buy
            if (i > j) {
                if (i == j+1) {
                    if (j > 2) {
                        // cout << j-2 << " " << i-j-1 << endl;
                        opt[i][j] = max(opt[i-1][j], predictions[i]-predictions[j] + opt[j-3][j-2]);
                    } else {
                        opt[i][j] = max(predictions[i]-predictions[i-1], 0);
                    }
                } else {
                    if (j > 2) {
                        // cout << j-2 << " " << i-j-1 << endl;
                        opt[i][j] = max(opt[i-1][j], predictions[i]-predictions[j] + opt[j-3][j-2]);
                    } else {
                        opt[i][j] = max(opt[i-1][j], predictions[i]-predictions[j]);
                    }
                }
            } else {
                opt[i][j] = 0;
            }
        }
    }
    // debug print
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n-1; j++){
    //         cout <<opt[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int max_int = 0;
    // TODO: Max bottom row
    for (auto i: opt[n-1]) {
        max_int = max(i, max_int);
    }
    cout << max_int << endl;
    return 0;
}
