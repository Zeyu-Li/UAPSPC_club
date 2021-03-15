#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int M, int K, vector<int> &v) {
    if (M == 0) {
        return true;
    }
    int time = 0;
    int count = 0;
    for (auto s : v) {
        if (s > time) {
            count++;
        }
        K -= count / M;
        time += count / M;
        count = count % M;
        if (K == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> shoes;
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        shoes.push_back(s);
    }
    sort(shoes.begin(), shoes.end());
    int M, u = N, l = 0;
    while (u - l > 5) {
        M = (u + l) / 2;
        if (check(M, K, shoes)) {
            l = M;
        }
        else {
            u = M;
        }
    }
    bool flag = true;
    for (int i = l; i <= u; i++) {
        if (check(i, K, shoes)) {
            continue;
        }
        else {
            cout << i - 1 << endl;
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << u << endl;
    }

}